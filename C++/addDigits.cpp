#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        int addDigits(int num) {
            while (num >= 10){
            int sum = 0;
            while (num >0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum; 
            }
            return num;
        }
    };

int main() {
    Solution solution;
    cout << solution.addDigits(38) << endl;
    cout << solution.addDigits(0) << endl;
    return 0;
}
        
