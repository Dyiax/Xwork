#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
    public:
        string toLowerCase(string s) {
            for (char &ch : s) {
                ch = tolower(ch);
            }
            return s;
        }
    };
int main() {
    Solution s;
    string str = "Hello";
    cout << s.toLowerCase(str) << endl;
    return 0;
}