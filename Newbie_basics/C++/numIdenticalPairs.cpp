#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    cout << solution.numIdenticalPairs(nums) << endl;
    return 0;
}