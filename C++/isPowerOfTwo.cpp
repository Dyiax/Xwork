#include <iostream>
#include <string>
using namespace std;

// class Solution {
//     public:
//         bool isPowerOfTwo(int n) {
//             if (n <= 0) return false;
//             while (n > 1) {
//                 if (n % 2 != 0) return false;
//                 n /= 2;
//             }
//             return true;
//         }
//     };

// Deepseek:
// n = 8，二进制是 1000。
// n - 1 = 7，二进制是 0111。
// 1000 & 0111 = 0000。
// 返回值：
// 如果 (n & (n - 1)) == 0，返回 true（或 True），否则返回 false（或 False）。
class Solution {
    public:
        bool isPowerOfTwo(int n) {
            if (n <= 0) return false;
            return (n & (n - 1)) == 0;
        }
    };

int main() {
    Solution solution;
    cout << solution.isPowerOfTwo(1) << endl;
    cout << solution.isPowerOfTwo(16) << endl;
    cout << solution.isPowerOfTwo(3) << endl;
    return 0;
}

