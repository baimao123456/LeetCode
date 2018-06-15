/*
78-���Ӽ�
*/
#include <stdio.h>
#include <vector>
using namespace std;
class Solution1
{
    //���ݷ����ݹ�
public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        vector<vector<int> > result;  //�洢���յ��Ӽ����
        vector<int> item;             //��Ż��ݹ����в������Ӽ�
        result.push_back(item);       //�ȴ���һ���ռ�
        generate(0, nums, item, result);  //�����Ӽ�
        return result;
    }
private:
    //�����Ӽ�
    //i����ѡ��nums�е�Ԫ��
    //item��Ż��ݹ����в������Ӽ�
    //result�洢���յ��Ӽ����
    void generate(int i,vector<int>& nums,
                  vector<int>& item,
                  vector<vector<int> >& result)
    {
        if(i >= nums.size())
            return;
        item.push_back(nums[i]);   //��nums[i]Ԫ�ط����Ӽ���
        result.push_back(item);    //����һ���Ӽ�
        generate(i + 1, nums, item, result);  //�����Ӽ�
        item.pop_back();           //��nums[i]Ԫ�ز������Ӽ���
        generate(i + 1, nums, item, result);  //�����Ӽ�
    }
};
class Solution2
{
public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        vector<vector<int> > result;  //�洢���յ��Ӽ����

        int all_set = 1 << nums.size(); //�����ڵ��Ӽ�����
        for(int i = 0; i < all_set; i++)
        {
            vector<int> item;             //��Ż��ݹ����в������Ӽ�
            for(int j = 0; j < nums.size(); j++)
            {
                if((1 << j) & i)
                    item.push_back(nums[j]);
            }
            result.push_back(item);
        }
        return result;
    }
};
//��ӡ��ά����
void print_sunsets(const vector<vector<int> >& result)
{
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            printf("[%d]",result[i][j]);
        }
        printf("\n");
    }
}
int main(void)
{
    Solution1 sol1;
    Solution2 sol2;
    vector<int> nums = {1,2,3};

    vector<vector<int> > result1 = sol1.subsets(nums);
    vector<vector<int> > result2 = sol2.subsets(nums);
    printf("the result 1 is \n");
    print_sunsets(result1);
    printf("the result 2 is \n");
    print_sunsets(result2);
    return 0;
}
