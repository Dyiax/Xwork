#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) { // Check if the array is empty
        return 0;
    }
    int slow = 0; // Slow pointer to track the position of unique elements
    for (int fast = 1; fast < numsSize; fast++) { // Fast pointer to iterate through the array
        if (nums[fast] != nums[slow]) { // If a new unique element is found
            slow++; // Move the slow pointer forward
            nums[slow] = nums[fast]; // Update the position with the new unique element
        }
    }
    return slow + 1; // Return the count of unique elements (length of the modified array)

}
int main(){
    int nums[] = {1, 1, 2}; // Example input array with duplicates
    int numsSize = sizeof(nums) / sizeof(nums[0]); // Calculate the size of the array
    int newLength = removeDuplicates(nums, numsSize); // Call the function to remove duplicates
    printf("Length of the modified array: %d\n", newLength); // Output the length of the modified array
    printf("Modified array: ");
    for (int i = 0; i < newLength; i++) { // Print the modified array
        printf("%d ", nums[i]); //不需要考虑数组中超出新长度后面的元素。
    }
    printf("\n"); // New line for better readability

    return 0;
}