#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> shuffle(vector<int>& nums, int n) {
            vector<int> result(2*n);
            // printf("result.size() = %d\n", result.size());
            for(int i = 0; i < n; i++){
                result[2 * i] = nums[i];
                result[2 * i + 1] = nums[i + n];
            }
            return result;
        }
    };

int main(){
    Solution solution;
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    vector<int> result = solution.shuffle(nums, 3);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}
