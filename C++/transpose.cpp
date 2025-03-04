#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    /* data */
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)//使用 &matrix 是为了避免拷贝，提高性能。
    {
        int m = matrix.size();//矩阵的行数
        int n = matrix[0].size();//矩阵的列数
        vector<vector<int>> result(n, vector<int>(m));//创建一个矩阵，行数为n，列数为m
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[j][i] = matrix[i][j];//行列互换
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> result = solution.transpose(matrix);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;//换行
    }
    return 0;
}
