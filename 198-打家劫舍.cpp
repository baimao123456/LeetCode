/*
//198-��ҽ���
*/
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //��n����������Ž�
    //�����ȡ��n�����䣬�����Ž�Ϊ��ǰ�ķ���ֵ���ϵ�n-2����������Ž�
    //�������ȡ��n�����䣬�����Ž�Ϊ��ȡ��n-1������ʱ�����Ž�
    int rob(vector<int> &nums)
    {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size(), 0);  //��n����������Ž�Ϊdp[n]
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

