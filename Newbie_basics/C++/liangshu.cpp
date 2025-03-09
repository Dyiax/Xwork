// class Solution {
// public:
//    int sum(int num1, int num2) {
// 		return num1 + num2;
//    }
// };
#include <iostream>
using namespace std;
class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};

int main() {
    Solution solution;
    //接受用户输入
	int num1, num2;
	std::cout << "Please input two numbers: ";
	std::cin >> num1 >> num2;
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << solution.sum(num1, num2) << std::endl;
    return 0;
}


