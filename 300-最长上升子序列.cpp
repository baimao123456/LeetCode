
/*
//300-�����������
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

        vector<int> dp(nums.size(), 0);  //��ʼ��dp����ȫ��Ϊ0Ԫ��
        dp[0] = 1;                       //��ʼ������Ϊ1
        int LIS = 1;                     //������г���
        for(int i = 1; i < dp.size(); i++)//���dp[i]��Ӧ��nums[i]Ԫ�ر�nums[j]����dp[i] = dp[j] +1;
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
     //����ջ
    int lengthOfLIS(vector<int> &nums)
    {
        if(nums.size() == 0)
            return 0;

        vector<int> stack;
        stack.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > stack.back())
                stack.push_back(nums[i]);            //���ջ��Ԫ��С��nums[i],ֱ�ӷŵ���ߣ��γ�����
            else
            {
                /*for(int j = 0; j < stack.size(); j++)
                {
                    if(stack[j] >= nums[i])          //��stack���ҵ�һ����nums[j]���Ԫ�أ��������滻
                    {
                        stack[j] = nums[i];
                        break;                       //���һ���滻�����˳�
                    }
                }*/
                int index = binary_search(nums, nums[i]);//���ö��ֲ��Ҳ����λ�ã�ʱ�临�Ӷ�ΪO��n*log(n)��
                stack[index] = nums[i];
            }
        }
        return stack.size();
    }
private:
    //���ֲ���Ԫ�ظò����λ��
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
