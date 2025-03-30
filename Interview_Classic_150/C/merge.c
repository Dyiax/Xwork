#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* nums1, int m, int* nums2, int n) {//int* nums1 是一个 指向整型的指针
    int i = m - 1; // nums1 的有效元素索引
    int j = n - 1; // nums2 的有效元素索引
    int k = m + n - 1; // 合并后数组的索引

    // 从后向前合并两个数组
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--]; // 将较大的元素放入 nums1 的末尾
        } else {
            nums1[k--] = nums2[j--]; // 将较大的元素放入 nums1 的末尾
        }
    }

    // 如果 nums2 还有剩余元素，直接复制到 nums1 的前面部分
    while (j >= 0) {
        nums1[k--] = nums2[j--]; // 将 nums2 的剩余元素放入 nums1
    }
    // 如果 nums1 还有剩余元素，不需要处理，因为它们已经在正确的位置上了
}

int main() {
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};
    int m = 3; // nums1 中的有效元素个数
    int n = 3; // nums2 中的有效元素个数

    merge(nums1, m, nums2, n);

    printf("Merged array: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}
// Output: Merged array: 1 2 2 3 5 6