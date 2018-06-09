/*
55-��Ծ��Ϸ-�ж��Ƿ���Դ�����ͷ��������β
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
        vector<int> index;         //����������Ծ��λ��
        for(int i = 0; i <nums.size(); i++)  //����index����
            index.push_back(i + nums[i]);
        int jump = 0;              //��ʼ��jump��max_index
        int max_index = index[0];
        while(jump != index.size() && jump <= max_index) //Ѱ���������λ��
        {
            if(max_index < index[jump]) //�����ǰ�������ĸ�Զ��index[jump;max_index]��Ԫ��ֵ����max_index
                max_index = index[jump];
            jump++;
        }
        if(jump >= nums.size())    //˵��jump���Ե���numsĩβ
            return true;
        return false;
    }
    bool canJump2(vector<int>& nums)
    {
        int max_index = 0;
        //����Ծ��Χ���ҵ������Ծ���룬���max_index����nums.size(),˵������
        for(int i = 0; i < nums.size() && i <= max_index; i++)
        {
            max_index = max(nums[i] + i, max_index); //����max_index
        }
        if(max_index >= nums.size())    //˵�����Ե���numsĩβ
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
