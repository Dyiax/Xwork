#include <stdio.h>
#include <stdint.h>

// 模拟结构体中的状态字段
typedef struct {
    uint8_t RSeatMotSdyFlag; // 要写入 bit0
    uint8_t LSeatMotSdyFlag; // 要写入 bit1
} SeatMotrModePosition;

// 位操作示例函数
void packFlagsToByte(SeatMotrModePosition ModeSeatPos) {
    uint8_t l_ucData = 0; // 初始为 0，所有位都是 0

    // 写入 bit 0：用 RSeatMotSdyFlag 的最低位 & 0x01，然后左移 0 位
    l_ucData |= (ModeSeatPos.RSeatMotSdyFlag & 0x01) << 0;

    // 写入 bit 1：用 LSeatMotSdyFlag 的最低位 & 0x01，然后左移 1 位
    l_ucData |= (ModeSeatPos.LSeatMotSdyFlag & 0x01) << 1;

    // 打印结果：十进制和二进制都打印一下
    printf("最终结果: l_ucData = %u (十进制), 0x%02X (十六进制)\n", l_ucData, l_ucData);

    // 打印二进制位结构（从高位到低位）
    printf("二进制位结构：");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (l_ucData >> i) & 0x01);
    }
    printf("\n");
}

// 主函数测试
int main() {
    SeatMotrModePosition ModeSeatPos;

    ModeSeatPos.RSeatMotSdyFlag = 1; // 写入 bit0
    ModeSeatPos.LSeatMotSdyFlag = 0; // 写入 bit1

    packFlagsToByte(ModeSeatPos);

    return 0;
}
