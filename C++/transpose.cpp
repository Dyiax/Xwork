#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    /* data */
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> result(n, vector<int>(m));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[j][i] = matrix[i][j];
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
        cout << endl;
    }
    return 0;
}
