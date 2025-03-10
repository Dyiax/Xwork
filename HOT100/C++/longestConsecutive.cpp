#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        // int longestConsecutive(vector<int>& nums) {
        //     unordered_set<int> s;
        //     // for (int i = 0; i < nums.size(); i++) {
        //     //     s.insert(nums[i]);
        //     // }
        //     for(const int& num : nums)
        //         s.insert(num);

            
        //     int longestStreak = 0;

        //     for(const int& num : nums){
        //         if(s.find(num - 1) == s.end()){
        //             int currentNum = num;
        //             int currentStreak = 1;

        //             while(s.find(currentNum + 1) != s.end()){
        //                 currentNum++;
        //                 currentStreak++;
        //             }

        //             longestStreak = max(longestStreak, currentStreak);
        //         }
        //     }
        // }
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> numSet(nums.begin(), nums.end()); // 将数组存入哈希集合
            int maxLength = 0;
        
            for (int num : numSet) {  //numSet哈希表
                // 如果当前数字是一个连续序列的起点
                if (numSet.find(num - 1) == numSet.end()) {
                    int currentNum = num;
                    int currentLength = 1;
        
                    // 向后查找连续的数字
                    while (numSet.find(currentNum + 1) != numSet.end()) {
                        currentNum++;
                        currentLength++;
                    }
        
                    // 更新最长序列的长度
                    maxLength = max(maxLength, currentLength);
                }
            }
        
            return maxLength;
        }
    };

int main() {
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = solution.longestConsecutive(nums);
    cout << "The longest consecutive sequence length is: " << result << endl;
    return 0;
}