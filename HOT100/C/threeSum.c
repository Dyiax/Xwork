/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//////////////////////////////////again
#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int cmpare(const void* a, const void* b) {//const void* a：指向第一个元素的指针,const void* b：指向第二个元素的指针
    return (*(int*)a - *(int*)b);
}
// int* nums：输入的整数数组
// int numsSize：数组的长度。
// int* returnSize：返回结果的三元组数量
// int** returnColumnSizes：返回每个三元组的大小（固定为 3）
// int**：返回所有满足条件的三元组

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmpare);  // 排序
    int** result = (int**)malloc(sizeof(int*) * numsSize * (numsSize - 1) * (numsSize - 2)); // 申请空间,分配结果数组
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize * numsSize );   // 申请空间,分配结果数组列数
    *returnSize = 0;  // 初始化结果数组大小

    for(int i = 0; i < numsSize - 2; i++){
        if(i>0 && nums[i] == nums[i-1]) continue; // 跳过重复的元素
        int target = -nums[i];  // 目标值
        int left = i + 1, right = numsSize - 1; // 双指针

        while(left < right){
            int sum = nums[left] + nums[right];

            if(sum < target){
                left++;
            }
            else if(sum > target){
                right--;
            }
            else{
                result[*returnSize] = (int*)malloc(sizeof(int)*3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;   // 记录返回数组的列数
                (*returnSize)++;

                while(left < right && nums[left] == nums[left+1]){ // 跳过重复元素
                    left++;
                }
                while(left < right && nums[right] == nums[right-1]){  // 跳过重复元素
                    right--;
                }

                left++;
                right--;

            }
        }
    }
    return result;
}

int main(){
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize ;
    int* returnColumnSizes; 

    int** result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    printf("resultSize = \n");
    for (int  i = 0; i < returnSize; i++)
    {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("]\n");
    }

    for (int i = 0; i < returnSize; i++)
    {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
    
}