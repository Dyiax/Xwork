#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& arr) {
            int left = 0;
            //int right = sizeof(arr) - 1;   arr.size() 是 std::vector 的成员函数，返回向量中元素的数量。
            int right = arr.size() - 1;
//             sizeof(arr) 是 C++ 的运算符，返回变量或类型占用的内存大小（以字节为单位）。
//              对于 std::vector，sizeof(arr) 返回的是向量对象本身的大小，而不是向量中元素的数量。因此，应该使用 arr.size() 来获取向量中元素的数量。
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] < arr[mid + 1]){
                    left = mid + 1;
                }
                else{
                    right = mid;
                }
            }
            return left;
        }
};

int main() {
    Solution solution;
    vector<int> arr = {0, 1, 0};
    cout << solution.peakIndexInMountainArray(arr) << endl;
    return 0;
}
