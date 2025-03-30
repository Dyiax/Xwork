#include <iostream>
#include <vector>
using namespace std;



class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty()) { // Check if the vector is empty
                return 0;
            }
            int slow = 0; // Slow pointer to track the position of unique elements
            for (int fast = 1; fast < nums.size(); fast++) { // Fast pointer to iterate through the vector
                if (nums[fast] != nums[slow]) { // If a new unique element is found
                    slow++; // Move the slow pointer forward
                    nums[slow] = nums[fast]; // Update the position with the new unique element
                }
            }
            return slow + 1; // Return the count of unique elements (length of the modified vector)
        }
    };


int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2}; // Example input vector with duplicates
    int newLength = solution.removeDuplicates(nums); // Call the function to remove duplicates
    cout << "Length of the modified vector: " << newLength << endl; // Output the length of the modified vector
    cout << "Modified vector: ";
    for (int i = 0; i < newLength; i++) { // Print the modified vector
        cout << nums[i] << " "; //不需要考虑数组中超出新长度后面的元素。
    }
    cout << endl; // New line for better readability

}