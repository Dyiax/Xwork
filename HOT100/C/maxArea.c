#include <stdio.h>

// 辅助函数：返回两个数中的较小值
int min(int a, int b) {
    return a < b ? a : b;
}

// 辅助函数：返回两个数中的较大值
int max(int a, int b) {
    return a > b ? a : b;
}
//双针法求解
int maxArea(int* height, int heightSize) {
    int left = 0; // 左指针
    int right = heightSize - 1; // 右指针
    int maxWater = 0; // 最大水量

    while (left < right) {
        // 计算当前容器的水量
        int currentWater = min(height[left], height[right]) * (right - left);
        // 更新最大水量
        maxWater = max(maxWater, currentWater);

        // 移动较短的那条线
        if (height[left] < height[right]) {
            left++; // 左指针右移
        } else {
            right--; // 右指针左移
        }
    }

    return maxWater;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);  //hightSize = 9
    printf("maxArea:%d\n", maxArea(height, heightSize));
    return 0;
}