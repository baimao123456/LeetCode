/*
//120-三角形最小路径和
*/
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //
    int minimumTotal(vector<vector<int> > &triangle)
    {
        if(triangle.size() == 0)
            return 0;
        //初始化dp,dp[i][j]表示从下往上递推，走到三角形第i行第j列的最优解
        vector<vector<int> >dp(triangle.size(), vector<int>(triangle.size(), 0));
        //将dp的最后一层初始化为triangle的最后一层
        for(int i = 0; i < dp.size();i++)
            dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];
        //从下往上寻找最小值的路径，
        for(int i = dp.size() - 2;i >= 0; i--)
            for(int j = 0; j < dp[i].size();j++)
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];

        return dp[0][0];
    }
};
int main(void)
{
    vector<vector<int> > triangle;
    int test[][10] = {{2},{3, 4},{6, 5, 7},{4, 1, 8, 3}};
    for(int i = 0; i < 4; i++)
    {
        triangle.push_back(vector<int>());
        for(int j = 0;j < i + 1;j++)
        {
            triangle[i].push_back(test[i][j]);
        }
    }
    Solution sol;
    printf("%d\n", sol.minimumTotal(triangle));
    return 0;
}




