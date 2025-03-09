#include <iostream>
#include <string>
using namespace std;

class Solution
{
private:
    /* data */
public:
    bool isPowerOfThree(int n){
        if (n <= 0) 
        return false;
        while (n>1)
        {
            if (n % 3 != 0) return false;
            n/=3;
        }
        return true;
    }

};

main()
{
    /* code */
    Solution solution;
    cout<< solution.isPowerOfThree(27)<<endl;
    return 0;
}

