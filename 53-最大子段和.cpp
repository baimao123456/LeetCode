/*
//53-最大子段和
*/
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);  //第n个房间的最优解为dp[n]
        dp[0] = nums[0];
        int max_res = dp[0];   //最大连续子段和
        for(int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if(dp[i] > max_res)
                max_res = dp[i];
        }
        return max_res;
    }
};
int main(void)
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    printf("%d\n", sol.maxSubArray(nums));
    return 0;
}


