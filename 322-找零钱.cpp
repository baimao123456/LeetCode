/*
//322-����Ǯ
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
        vector<int> dp(amount +1, -1);    //��ʼ��dp,���н������Žⲻ�ɴﵽ
        dp[0] = 0;                        //���0�����Ž����0��
        for(int i = 1; i <= amount; i++)  //����
        {
            for(int j = 0;j < coins.size(); j++)
            {
                if(i - coins[j] >= 0 && dp[i - coins[j]] != -1) //��������
                {
                    if(dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1)
                        dp[i] = dp[i - coins[j]] + 1;   //��Ҫ��������Сֵ
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



