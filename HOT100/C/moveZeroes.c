#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int left = 0;  // 指向下一个非零元素要放置的位置
    int right = 0; // 用于遍历数组的指针

    // 遍历数组
    while (right < numsSize) {
        // 如果当前元素非零，将其移动到'left'位置
        if (nums[right]) {
            nums[left] = nums[right];
            left++;//移动到下一个非零元素
        }
        right++;//遍历完数组
    }

    // 将剩余位置填充为零
    while (left < numsSize) {
        nums[left] = 0;
        left++;
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, numsSize);

//    printf("移动后的数组: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}