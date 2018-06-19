/*
//198-打家劫舍
*/
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //第n个房间的最优解
    //如果盗取第n个房间，则最优解为当前的房间值加上第n-2个房间的最优解
    //如果不盗取第n个房间，则最优解为盗取第n-1个房间时的最优解
    int rob(vector<int> &nums)
    {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size(), 0);  //第n个房间的最优解为dp[n]
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
int main(void)
{
    vector<int> nums = {5,2,6,3,1,7};
    Solution sol;
    printf("%d\n", sol.rob(nums));
    return 0;
}

