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
// Deepseek
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

