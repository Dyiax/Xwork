# ==========================================
# 简单构建脚本 - build_simple.ps1
# 功能: 执行TriCore项目编译，带基本进度显示
# 作者: GitHub Copilot
# ==========================================

# 定义脚本参数 - 并行编译任务数，默认为4
param([int]$Jobs = 4)

# 设置TriCore工具链环境变量
# 这个路径指向Infineon TriCore编译器工具链
$env:TRICORE_TOOLS = "C:\HighTec\toolchains\tricore\v4.9.3.0"

# 构建make.exe的完整路径
$makeExe = "$env:TRICORE_TOOLS\bin\make.exe"

# 切换到Default目录（这是实际的构建目录）
Set-Location Default

# 显示构建开始信息
Write-Host "Starting build with progress monitoring..." -ForegroundColor Yellow
Write-Host "Jobs: $Jobs" -ForegroundColor Cyan

# 记录构建开始时间，用于后续计算构建耗时
$startTime = Get-Date

# 第一步：清理之前的构建产物
Write-Host "Step 1/3: Cleaning..." -ForegroundColor Blue
# 执行make clean命令，2>&1将错误重定向到标准输出，| Out-Null丢弃所有输出
& $makeExe clean 2>&1 | Out-Null

# 第二步：开始编译
Write-Host "Step 2/3: Building..." -ForegroundColor Blue
# 启动make进程进行编译
# -FilePath: 指定要执行的程序
# -ArgumentList: 传递给程序的参数列表（-j$Jobs表示并行任务数，all表示编译所有目标）
# -PassThru: 返回进程对象，让我们可以监控进程状态
# -NoNewWindow: 不打开新窗口，在当前控制台运行
$makeProcess = Start-Process -FilePath $makeExe -ArgumentList "-j$Jobs", "all" -PassThru -NoNewWindow

# 初始化进度变量
$progress = 0

# 模拟进度显示循环
# 当make进程还在运行时，持续显示进度
while (!$makeProcess.HasExited) {
    # 等待1秒钟
    Start-Sleep -Seconds 1
    
    # 增加进度值，但最大不超过95%（避免在编译完成前显示100%）
    $progress = [Math]::Min(95, $progress + 10)
    
    # 显示当前进度
    Write-Host "Building... $progress%" -ForegroundColor Green
}

# 等待make进程完全结束
$makeProcess.WaitForExit()

# 检查编译结果
# ExitCode为0表示成功，非0表示失败
if ($makeProcess.ExitCode -eq 0) {
    # 编译成功
    Write-Host "Build successful!" -ForegroundColor Green
    
    # 检查输出文件是否存在
    if (Test-Path "bsw.a") {
        # 获取文件大小并转换为MB
        $fileSize = (Get-Item "bsw.a").Length
        $fileSizeMB = [math]::Round($fileSize/1MB, 2)
        Write-Host "Output: bsw.a ($fileSizeMB MB)" -ForegroundColor Cyan
    }
} else {
    # 编译失败
    Write-Host "Build failed!" -ForegroundColor Red
    exit 1  # 以错误码1退出脚本
}

# 计算并显示总构建时间
$endTime = Get-Date
$duration = $endTime - $startTime
Write-Host "Build time: $($duration.TotalSeconds.ToString('F1')) seconds" -ForegroundColor Yellow
