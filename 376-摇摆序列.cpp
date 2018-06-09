/*
摇摆序列
*/
#include <stdio.h>
#include <vector>
using namespace std;
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if(nums.size() < 2)     //序列个数小于2，直接就是摇摆序列
            return nums.size();
        static const int BEGIN = 0;   //开始状态
        static const int UP = 1;      //上升状态
        static const int DOWN = 2;    //下降状态
        int STATE = BEGIN;
        int max_length = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            switch(STATE)
            {
                case BEGIN:  //如果存在前后两个数相等，直接跳出switch
                    if(nums[i - 1] < nums[i])
                    {
                        max_length++;
                        STATE = UP;
                    }
                    else if(nums[i - 1] > nums[i])
                    {
                        max_length++;
                        STATE = DOWN;
                    }
                    break;
                case UP:
                    if(nums[i - 1] > nums[i])  //如果出现下降，则改变状态，否则忽略
                    {
                        max_length++;
                        STATE = DOWN;
                    }
                    break;
                case DOWN:
                    if(nums[i - 1] < nums[i]) //如果出现上升，则改变状态，否则忽略
                    {
                        max_length++;
                        STATE = UP;
                    }
                    break;
            }
        }
        return max_length;   //返回最大子序列长度
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    printf("wiggle maxlength is %d \n",sol.wiggleMaxLength(nums));
    return 0;
}
