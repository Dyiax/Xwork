# ==========================================
# 增强构建监控脚本 - build_monitor_v2.ps1
# 功能: 执行TriCore项目编译，带详细错误/警告检测和报告
# 特点: 捕获编译输出，分析错误和警告，提供详细的构建报告
# 作者: GitHub Copilot
# ==========================================

# 定义脚本参数 - 并行编译任务数，默认为4
param([int]$Jobs = 4)

# 设置TriCore工具链环境变量
$env:TRICORE_TOOLS = "C:\HighTec\toolchains\tricore\v4.9.3.0"

# 构建make.exe的完整路径
$makeExe = "$env:TRICORE_TOOLS\bin\make.exe"

# 切换到Default目录（实际的构建目录）
Set-Location Default

# 显示构建监控器标题和配置信息
Write-Host "=== Build Progress Monitor ===" -ForegroundColor Yellow
Write-Host "Jobs: $Jobs" -ForegroundColor Cyan
Write-Host "Compiler: $env:TRICORE_TOOLS" -ForegroundColor Cyan

# 记录构建开始时间
$startTime = Get-Date

# ===== 第一步：清理构建产物 =====
Write-Host ""
Write-Host "[1/3] Cleaning build artifacts..." -ForegroundColor Blue
# 执行清理命令并捕获输出（虽然这里没有使用）
$cleanResult = & $makeExe clean 2>&1
Write-Host "Clean completed" -ForegroundColor Green

Write-Host ""
Write-Host "[2/3] Starting compilation..." -ForegroundColor Blue

# ===== 第二步：执行编译并捕获所有输出 =====
# 关键：使用 & 操作符直接执行命令并捕获输出
# 2>&1 将错误输出重定向到标准输出，这样错误和警告都会被捕获
$buildOutput = & $makeExe "-j$Jobs" all 2>&1

# 获取make命令的退出码
# $LASTEXITCODE 是PowerShell的自动变量，保存最后执行命令的退出码
$exitCode = $LASTEXITCODE

# ===== 初始化状态变量 =====
# 检查构建是否成功（退出码为0表示成功）
$success = ($exitCode -eq 0)
$upToDate = $false      # 文件是否已经是最新的
$hasErrors = $false     # 是否有编译错误
$hasWarnings = $false   # 是否有编译警告

# ===== 判断构建状态 =====
if ($success) {
    # 检查是否是因为文件已经最新而没有重新编译
    if ($buildOutput -match "Nothing to be done") {
        $upToDate = $true
        Write-Host "All files are up-to-date!" -ForegroundColor Green
    } else {
        Write-Host "Compilation successful!" -ForegroundColor Green
    }
} else {
    # 编译失败
    $hasErrors = $true
    Write-Host "Compilation failed!" -ForegroundColor Red
}

# ===== 解析编译输出，查找错误和警告 =====
# 初始化存储错误和警告的数组
$errorLines = @()       # 存储错误信息的数组
$warningLines = @()     # 存储警告信息的数组
$errorCount = 0         # 错误计数器
$warningCount = 0       # 警告计数器

# 遍历每一行编译输出
foreach ($line in $buildOutput) {
    # 将输出行转换为字符串
    $lineStr = $line.ToString()
    
    # 使用正则表达式匹配错误模式
    # 匹配常见的错误关键词：error:, Error:, fatal error:, make错误信息
    if ($lineStr -match "error:|Error:|fatal error:|\*\*\* \[.*\] Error") {
        $errorCount++                # 增加错误计数
        $errorLines += $lineStr      # 将错误行添加到数组
    } 
    # 使用正则表达式匹配警告模式
    elseif ($lineStr -match "warning:|Warning:") {
        $warningCount++              # 增加警告计数
        $warningLines += $lineStr    # 将警告行添加到数组
        $hasWarnings = $true         # 标记存在警告
    }
}

# ===== 显示发现的问题（错误和警告）=====
if ($hasErrors -or $hasWarnings) {
    Write-Host ""
    Write-Host "=== Issues Found ===" -ForegroundColor Yellow
    
    # 如果有错误，显示错误信息
    if ($errorCount -gt 0) {
        Write-Host "Errors: $errorCount" -ForegroundColor Red
        Write-Host "Error details:" -ForegroundColor Red
        # 显示最后5个错误（避免输出过多）
        $errorLines | Select-Object -Last 5 | ForEach-Object {
            Write-Host "  $_" -ForegroundColor Red
        }
    }
    
    # 如果有警告，显示警告信息
    if ($warningCount -gt 0) {
        Write-Host "Warnings: $warningCount" -ForegroundColor Yellow
        Write-Host "Warning details:" -ForegroundColor Yellow
        # 显示最后3个警告（避免输出过多）
        $warningLines | Select-Object -Last 3 | ForEach-Object {
            Write-Host "  $_" -ForegroundColor Yellow
        }
    }
    
    # ===== 如果有错误，显示构建上下文信息 =====
    if ($hasErrors) {
        Write-Host ""
        Write-Host "Build output context:" -ForegroundColor Cyan
        # 显示最后15行构建输出，提供错误上下文
        $buildOutput | Select-Object -Last 15 | ForEach-Object {
            $line = $_.ToString().Trim()
            if ($line -ne "") {
                # 根据内容类型使用不同颜色显示
                if ($line -match "error:|Error:|fatal error:") {
                    Write-Host "  $line" -ForegroundColor Red
                } elseif ($line -match "warning:|Warning:") {
                    Write-Host "  $line" -ForegroundColor Yellow
                } else {
                    Write-Host "  $line" -ForegroundColor Gray
                }
            }
        }
    }
}

# ===== 第三步：检查输出文件 =====
Write-Host ""
Write-Host "[3/3] Checking output files..." -ForegroundColor Blue

# 检查目标文件bsw.a是否存在
if (Test-Path "bsw.a") {
    # 获取文件信息
    $fileInfo = Get-Item "bsw.a"
    # 计算文件大小（转换为MB，保留2位小数）
    $sizeMB = [math]::Round($fileInfo.Length / 1MB, 2)
    # 获取文件最后修改时间
    $lastModified = $fileInfo.LastWriteTime
    
    # 显示文件信息
    Write-Host "Output file: bsw.a" -ForegroundColor Cyan
    Write-Host "  Size: $sizeMB MB" -ForegroundColor Cyan
    Write-Host "  Modified: $lastModified" -ForegroundColor Cyan
} else {
    # 警告：目标文件不存在
    Write-Host "Warning: bsw.a not found!" -ForegroundColor Yellow
}

# ===== 计算构建耗时 =====
$endTime = Get-Date
$duration = $endTime - $startTime

# ===== 显示构建总结报告 =====
Write-Host ""
Write-Host "=== Build Summary ===" -ForegroundColor Yellow

# 显示构建状态（成功/失败），根据状态使用不同颜色
Write-Host "Status: $(if($success){'SUCCESS'}else{'FAILED'})" -ForegroundColor $(if($success){'Green'}else{'Red'})

# 显示是否为最新状态
Write-Host "Up-to-date: $upToDate" -ForegroundColor Cyan

# 显示错误数量（有错误用红色，无错误用绿色）
Write-Host "Errors: $errorCount" -ForegroundColor $(if($errorCount -gt 0){'Red'}else{'Green'})

# 显示警告数量（有警告用黄色，无警告用绿色）
Write-Host "Warnings: $warningCount" -ForegroundColor $(if($warningCount -gt 0){'Yellow'}else{'Green'})

# 显示构建耗时（保留1位小数）
Write-Host "Duration: $($duration.TotalSeconds.ToString('F1')) seconds" -ForegroundColor Cyan

# 显示并行任务数
Write-Host "Jobs: $Jobs" -ForegroundColor Cyan

# ===== 如果构建失败，以错误码退出 =====
if (!$success) {
    exit 1  # 非零退出码表示脚本执行失败
}
