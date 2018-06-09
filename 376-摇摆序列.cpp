/*
ҡ������
*/
#include <stdio.h>
#include <vector>
using namespace std;
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if(nums.size() < 2)     //���и���С��2��ֱ�Ӿ���ҡ������
            return nums.size();
        static const int BEGIN = 0;   //��ʼ״̬
        static const int UP = 1;      //����״̬
        static const int DOWN = 2;    //�½�״̬
        int STATE = BEGIN;
        int max_length = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            switch(STATE)
            {
                case BEGIN:  //�������ǰ����������ȣ�ֱ������switch
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
                    if(nums[i - 1] > nums[i])  //��������½�����ı�״̬���������
                    {
                        max_length++;
                        STATE = DOWN;
                    }
                    break;
                case DOWN:
                    if(nums[i - 1] < nums[i]) //���������������ı�״̬���������
                    {
                        max_length++;
                        STATE = UP;
                    }
                    break;
            }
        }
        return max_length;   //������������г���
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    printf("wiggle maxlength is %d \n",sol.wiggleMaxLength(nums));
    return 0;
}
