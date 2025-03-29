#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {//nums1是一个对vector<int>类型对象的引用。它并不创建新的vector，而是指向一个已经存在的vector<int>对象。
            int i = m - 1; // nums1 的有效元素索引
            int j = n - 1; // nums2 的有效元素索引
            int k = m + n - 1; // 合并后数组的索引
            // 从后向前合并两个数组
            while (i >= 0 && j >= 0) {
                if (nums1[i] > nums2[j]) {
                    nums1[k--] = nums1[i--]; // 将较大的元素放入 nums1 的末尾
                } else {
                    nums1[k--] = nums2[j--]; // 将较大的元素放入 nums1 的末尾
                }
            }
            // 如果 nums2 还有剩余元素，直接复制到 nums1 的前面部分
            while (j >= 0) {
                nums1[k--] = nums2[j--]; // 将 nums2 的剩余元素放入 nums1
            }
            // 如果 nums1 还有剩余元素，不需要处理，因为它们已经在正确的位置上了

        }
    };

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3; // nums1 中的有效元素个数
    int n = 3; // nums2 中的有效元素个数
    s.merge(nums1, m, nums2, n);
    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}