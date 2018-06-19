
/*
//300-最长上升子序列
*/
#include <vector>
#include <stack>
#include <stdio.h>
using namespace std;
class Solution1
{
public:

    int lengthOfLIS(vector<int> &nums)
    {
        if(nums.size() == 0)
            return 0;

        vector<int> dp(nums.size(), 0);  //初始化dp数组全部为0元素
        dp[0] = 1;                       //初始化长度为1
        int LIS = 1;                     //最长子序列长度
        for(int i = 1; i < dp.size(); i++)//如果dp[i]对应的nums[i]元素比nums[j]大，则dp[i] = dp[j] +1;
        {
            for(int j = 0; j < i; j++)
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            if(dp[i] > LIS)
                LIS = dp[i];
        }
        return LIS;
    }
};
class Solution2
{
public:
     //利用栈
    int lengthOfLIS(vector<int> &nums)
    {
        if(nums.size() == 0)
            return 0;

        vector<int> stack;
        stack.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > stack.back())
                stack.push_back(nums[i]);            //如果栈顶元素小于nums[i],直接放到后边，形成序列
            else
            {
                /*for(int j = 0; j < stack.size(); j++)
                {
                    if(stack[j] >= nums[i])          //从stack中找第一个比nums[j]大的元素，并进行替换
                    {
                        stack[j] = nums[i];
                        break;                       //完成一次替换即可退出
                    }
                }*/
                int index = binary_search(nums, nums[i]);//利用二分查找插入的位置，时间复杂度为O（n*log(n)）
                stack[index] = nums[i];
            }
        }
        return stack.size();
    }
private:
    //二分查找元素该插入的位置
    int binary_search(vector<int> &nums, int target)
    {
        int index = -1;
        int begin = 0;
        int end = nums.size() - 1;
        while(index == -1)
        {
            int mid = (begin + end) / 2;
            if(target == nums[mid])
            {
                index = mid;
            }
            else if(target < nums[mid])
            {
                if(mid == 0 || target > nums[mid - 1])
                    index = mid;
                end = mid - 1;
            }
            else if(target > nums[mid])
            {
                if(mid == nums.size() - 1 || target < nums[mid + 1])
                    index = mid + 1;
                begin = mid + 1;
            }
        }
        return index;
    }
};
int main(void)
{
    Solution1 sol1;
    Solution2 sol2;
    vector<int> nums = {1, 2, 3, 1, 2, 3, 4};
    printf("%d\n", sol1.lengthOfLIS(nums));
    printf("%d\n", sol2.lengthOfLIS(nums));
    return 0;
}
