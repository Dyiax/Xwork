#include <iostream>
#include <vector>
#include <algorithm>  // for max() and min()
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0, right = height.size() - 1;  // left and right pointer
            int maxArea = 0;    //max area

            while (left < right) {
                int currentwater = min(height[left], height[right])*(right - left);//calculate current water
                maxArea = max(maxArea, currentwater);
                if (height[left] < height[right]) { // if left is smaller than right
                    left++;                     // move left pointer to right
                }
                else {
                    right--;                    // move right pointer to left
                }
            }
            return maxArea;
        }
    };

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution s;
    cout << "maxArea:"<< s.maxArea(height)<< endl;
}