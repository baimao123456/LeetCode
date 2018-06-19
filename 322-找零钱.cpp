/*
//322-找零钱
*/
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount +1, -1);    //初始化dp,所有金额的最优解不可达到
        dp[0] = 0;                        //金额0的最优解就是0张
        for(int i = 1; i <= amount; i++)  //递推
        {
            for(int j = 0;j < coins.size(); j++)
            {
                if(i - coins[j] >= 0 && dp[i - coins[j]] != -1) //递推条件
                {
                    if(dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1)
                        dp[i] = dp[i - coins[j]] + 1;   //需要张数的最小值
                }
            }
        }
        return dp[amount];
    }
};
int main(void)
{
    vector<int> coins = {1,2,5,7,10};
    Solution sol;
    for(int i = 0; i <= 14; i++)
    {
        printf("dp[%d] = %d\n", i, sol.coinChange(coins, i));
    }

    return 0;
}



