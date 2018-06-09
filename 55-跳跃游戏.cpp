/*
55-跳跃游戏-判断是否可以从数组头跳到数组尾
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        vector<int> index;         //保存最大可跳跃的位置
        for(int i = 0; i <nums.size(); i++)  //计算index数组
            index.push_back(i + nums[i]);
        int jump = 0;              //初始化jump和max_index
        int max_index = index[0];
        while(jump != index.size() && jump <= max_index) //寻找最大跳的位置
        {
            if(max_index < index[jump]) //如果当前可以跳的更远，index[jump;max_index]的元素值大于max_index
                max_index = index[jump];
            jump++;
        }
        if(jump >= nums.size())    //说明jump可以到达nums末尾
            return true;
        return false;
    }
    bool canJump2(vector<int>& nums)
    {
        int max_index = 0;
        //在跳跃范围内找到最大跳跃距离，如果max_index大于nums.size(),说明可以
        for(int i = 0; i < nums.size() && i <= max_index; i++)
        {
            max_index = max(nums[i] + i, max_index); //更新max_index
        }
        if(max_index >= nums.size())    //说明可以到达nums末尾
            return true;
        return false;
    }
};
int main(void)
{
    vector<int> nums = {2,3,1,1,4};
    Solution sol;
    printf("%d\n",sol.canJump(nums));
    printf("%d\n",sol.canJump2(nums));
    return 0;
}
