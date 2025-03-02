#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        int subtractProductAndSum(int n) {
            string numStr = to_string(n);  // 将整数转换为字符串
            int product = 1;  // 初始化乘积为 1
            int sum = 0;      // 初始化和为 0
            // 遍历字符串中的每个字符
            for (char ch : numStr) {
                int digit = ch - '0';  // 将字符转换为数字
                product *= digit;      // 计算乘积
                sum += digit;         // 计算和
            }
            return product - sum;  // 返回乘积减和
        }
    };
int main() {
    Solution solution;
    cout << solution.subtractProductAndSum(234) << endl;
    cout << solution.subtractProductAndSum(4421) << endl;
    return 0;
}