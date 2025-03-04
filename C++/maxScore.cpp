#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// class Solution {
//     public:
//         int maxScore(vector<int>& cardPoints, int k) {
//             int n = cardPoints.size();
//             int windowSize = n - k;
//             int sum = 0;
//             for(int i = 0; i < windowSize; i++){
//                 sum += cardPoints[i];
//             }
//             int minSum = sum;
//             for(int i = windowSize; i < n; i++){
//                 sum += cardPoints[i] - cardPoints[i - windowSize];
//                 minSum = min(minSum, sum);
//             }
//             int totalSum = 0;
//             for(int i = 0; i < n; i++){
//                 totalSum += cardPoints[i];
//             }
//             return totalSum - minSum;
//         }
//     };
// class Solution {
//     public:
//         int maxScore(string s) {
//             int n = s.size();
//             int maxScore = 0;
//             for(int i = 1; i < n; i++){
//                 string left = s.substr(0, i);//substr(0, i) 是字符串对象的一个方法，用于提取子字符串。
//                 string right = s.substr(i, n - i);
//                 int leftZeros = count(left.begin(), left.end(), '0');
//                 int rightOnes = count(right.begin(), right.end(), '1');
//                 maxScore = max(maxScore, leftZeros + rightOnes);
//             }
//             return maxScore;
//         }
//     };
class Solution{
    public:
        int maxScore(string s) {
            int max_score = 0;
            int left_zeros = 0;  // 左子字符串中 0 的数量
            int right_ones = count(s.begin(), s.end(), '1');  // 右子字符串中 1 的数量（初始为整个字符串的 1 的数量）

            // 遍历字符串，尝试每一种分割方式
            for (int i = 0; i < s.length() - 1; i++) {  // 注意：右子字符串不能为空
                if (s[i] == '0') {
                    left_zeros++;  // 左子字符串中 0 的数量增加
                } else {
                    right_ones--;  // 右子字符串中 1 的数量减少
                }

                // 计算当前分割方式的得分
                int current_score = left_zeros + right_ones;
                // 更新最大得分
                if (current_score > max_score) {
                    max_score = current_score;
                }
            }

            return max_score;
        }
};

int main(){
    Solution solution;
    string s = "011101";
    cout << solution.maxScore(s) << endl;
    return 0;
}