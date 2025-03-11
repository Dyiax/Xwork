#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    //计数法
    // void moveZeroes(vector<int>& nums) {
    //     int count = 0; // 统计 0 的个数
    
    //     // 将非零元素移动到数组前面
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] != 0) {
    //             nums[count] = nums[i]; // 将非零元素移动到 count 位置
    //             count++; // count 右移
    //         }
    //     }
    
    //     // 将剩余位置置为 0
    //     while (count < nums.size()) {
    //         nums[count] = 0; // 将 count 之后的位置置为 0
    //         count++;
    //     }
    // }
    
    // };

    //双指针法
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        // 遍历数组
        while (right < n) {
            // 如果当前元素不为 0，进入判断语句
            if (nums[right]) {
                // 交换 left 和 right 位置的元素
                swap(nums[left], nums[right]);
                // 左指针右移
                left++;
            }
            // 右指针右移
            right++;
        }
    }
};
int main() {
    Solution solution;
    vector<int> nums = {0, 3, 0, 1, 12};
    solution.moveZeroes(nums);

//    cout << "移动后的数组: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}