/*
//70-爬楼梯
*/
#include <vector>
#include <stdio.h>
using namespace std;
class Solution
{
public:
    //爬到第n层楼梯一共多少种方法
    int climbStairs(int n)
    {
        vector<int> dp(n + 3, 0);  //n = 0时，防止数组越界
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
int main(void)
{
    Solution sol;
    printf("%d\n", sol.climbStairs(3));
    return 0;
}
