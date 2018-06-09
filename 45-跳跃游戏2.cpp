/*
45-跳跃游戏2,至少需要几次跳到nums末尾
*/
#include <stdio.h>
#include <vector>
using namespace std;
class Solution
{
//难点是记录跳跃的次数
//只有在必须要跳的时候才跳跃
public:
    int jump(vector<int>& nums)
    {
        if(nums.size() < 2)    //数组长度小于2，不用跳跃
            return 0;
        int current_max_index = nums[0];  //当前可到达的最远位置
        int pre_max_max_index = nums[0];  //遍历过程中，可到达的最远位置
        int jump_min = 1;                 //最少跳跃1次
        for(int i = 1; i < nums.size(); i++)
        {
            if(i > current_max_index)     //当遍历到所能到达的最远位置时
            {
                jump_min++;               //记录跳跃次数
                current_max_index = pre_max_max_index; //更新现在能到达的最远位置
            }
            //更新，使其保持pre_max_max_index最大
            pre_max_max_index = max(pre_max_max_index, nums[i] + i);
        }
        return jump_min;
    }
};
int main(void)
{
    vector<int> nums = {2,3,1,1,4};
    Solution sol;
    printf("%d",sol.jump(nums));
    return 0;
}

