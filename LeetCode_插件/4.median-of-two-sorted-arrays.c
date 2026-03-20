/*
 * @lc app=leetcode.cn id=4 lang=c
 * @lcpr version=30204
 *
 * [4] 寻找两个正序数组的中位数
 */


// @lcpr-template-start
#include <stdio.h>
#include <stdlib.h>
// @lcpr-template-end
// @lc code=start
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //合并两个数组
    int totalsize = nums1Size + nums1Size;
    int* median = (int*)malloc(totalsize * sizeof(int));
    int i,j = 0;
    while (nums1Size < totalsize && nums2Size < totalsize)
    {
        if (nums1[nums1Size] < nums2[nums2Size])
        {
            median[i++] = nums1[nums1Size++];
        }
        else
        {
            median[i++] = nums2[nums2Size++];
        }
    }
    
}
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */
int main(void) {
    int a[] = {1, 2};
    int b[] = {3, 4};
    double m = findMedianSortedArrays(a, 2, b, 2);
    printf("median = %.2f\n", m);
    return 0;
}
