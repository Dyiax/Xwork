#include <iostream>
using namespace std;

class Solution {
private:
    /* data */
public:
    bool isUgly(int n){
        if(n <= 0) return false;
        while(n % 2 == 0) n /= 2;
        while(n % 3 == 0) n /= 3;
        while(n % 5 == 0) n /= 5;
        return n == 1;
    }
};

int main(){
    Solution solution;
    cout << solution.isUgly(6) << endl;
    cout << solution.isUgly(1) << endl;
    cout << solution.isUgly(14) << endl;
    return 0;
}