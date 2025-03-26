#include <iostream> 
#include <vector>
using namespace std;

class Solution {
    public:
    // 从数组中删除指定元素
        int removeElement(vector<int>& nums, int val) {
            int i = 0;//// 慢指针：指向当前可以放置非 val 元素的位置
            for (int j = 0; j < nums.size(); j++) {// 快指针：遍历数组
                if (nums[j] != val) {
                    nums[i] = nums[j];// 当前元素不等于 val 时，将其放入慢指针位置，慢指针后移一位
                    i++;
                }
            }
            return i;// 返回非 val 元素个数
        }
    };
int main(){
    Solution s;
    vector<int> nums = {3,2,2,3};
    int val = 3;
    int res = s.removeElement(nums,val);
    cout << res << endl;
    cout << "nums = [";
    for (int i = 0; i < res; i++) {
        cout << nums[i] << ",";
    }
    cout << "]" << endl;
    return 0;
}