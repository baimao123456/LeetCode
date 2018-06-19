/*
//64-最小路径和
*/
#include <vector>
#include <stack>
#include <stdio.h>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        if(grid.size() == 0)
            return 0;
        int row = grid.size();     //行数
        int col = grid[0].size();  //列数
        vector<vector<int> >dp(row, vector<int>(col, 0));//dp[i][j]表示到达该点的最小路径和
        dp[0][0] = grid[0][0];     //初始化dp[0][0]
        //第一行只能像右计算
        for(int i = 1; i < col; i++)
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        for(int i = 1; i < row; i++)
        {
            //第一列只能像下计算
            dp[i][0] = dp[i - 1][0] + grid[i][0];
            for(int j = 1; j < col; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[row - 1][col - 1];//返回到达右下角的最短路径和
    }
};
int main(void)
{
    int test[][3] = {{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int> > grid;
    for(int i = 0; i < 3; i++)
    {
        grid.push_back(vector<int>());
        for(int j = 0;j < 3;j++)
        {
            grid[i].push_back(test[i][j]);
        }
    }
    Solution sol;
    printf("%d\n", sol.minPathSum(grid));
    return 0;
}
