#include <iostream>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
       int result;
        for (int i = 0; i < n; i++) {
            result ^= start + 2 * i;
        }
        return result; 
    }
};
int  main() {
    Solution solution;
    int n, start;
    cin >> n >> start;
    cout << solution.xorOperation(n, start) << endl;
    return 0;
}
