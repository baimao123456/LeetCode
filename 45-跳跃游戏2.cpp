/*
45-��Ծ��Ϸ2,������Ҫ��������numsĩβ
*/
#include <stdio.h>
#include <vector>
using namespace std;
class Solution
{
//�ѵ��Ǽ�¼��Ծ�Ĵ���
//ֻ���ڱ���Ҫ����ʱ�����Ծ
public:
    int jump(vector<int>& nums)
    {
        if(nums.size() < 2)    //���鳤��С��2��������Ծ
            return 0;
        int current_max_index = nums[0];  //��ǰ�ɵ������Զλ��
        int pre_max_max_index = nums[0];  //���������У��ɵ������Զλ��
        int jump_min = 1;                 //������Ծ1��
        for(int i = 1; i < nums.size(); i++)
        {
            if(i > current_max_index)     //�����������ܵ������Զλ��ʱ
            {
                jump_min++;               //��¼��Ծ����
                current_max_index = pre_max_max_index; //���������ܵ������Զλ��
            }
            //���£�ʹ�䱣��pre_max_max_index���
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

