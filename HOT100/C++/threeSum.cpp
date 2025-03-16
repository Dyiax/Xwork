#include <iostream>
#include <vector>
#include <algorithm> // 用于排序

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> result; // 用于存储满足条件的三元组
    sort(nums.begin(), nums.end()); // 对数组进行排序
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {  //n-1为数组最后一个元素，如果i=n-3，left = n-2，right = n-1，则left=i+1，right=n-1，这是最后一个可能的数组。
        if (i > 0 && nums[i] == nums[i - 1]) continue; // 跳过重复的元素
        int target = -nums[i]; // 目标值
        int left = i + 1, right = n - 1; // 左指针在当前位置的右边，右指针在数组的最后一个位置
        while (left < right) { // 双指针循环
            int sum = nums[left] + nums[right];
            if (sum < target) {
                left++;

            }
            else if (sum > target) {
                right--;

            }
            else {
                result.push_back({nums[i], nums[left], nums[right]}); // 找到满足条件的三元组然后push_back()
                while (left < right && nums[left] == nums[left + 1]) left++; // 跳过重复元素，但好像没有重复元素
                while (left < right && nums[right] == nums[right - 1]) right--; // 跳过重复元素
                left++; // 更新左指针和右指针
                right--;
            }

        }
    }
    return result;

}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

    // 输出结果三元组
    cout << "threeSums:" << endl;
    for (const auto& triplet : result) { // 遍历每个三元组
        cout << "["; // 输出三元组的起始括号
        for (int num : triplet) { // 遍历三元组中的每个数字
            cout << num << " "; // 输出数字并以空格分隔
        }
        cout << "]" << endl; // 输出三元组的结束括号并换行
    }

    return 0;
}