/*
90-���Ӽ�2--ȥ���ظ�
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class Solution1
{
    //���ݷ����ݹ� setȥ���ظ��Ӽ�
public:

    vector<vector<int> > subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int> > result;  //�洢���յ��Ӽ����
        vector<int> item;             //��Ż��ݹ����в������Ӽ�
        set<vector<int> > res_set;    //����setȥ���ظ�
        sort(nums.begin(), nums.end());//��nums��������
        result.push_back(item);       //�ȴ���һ���ռ�
        generate(0, nums, item, res_set, result);  //�����Ӽ�
        return result;
    }
private:
    //�����Ӽ�
    //i����ѡ��nums�е�Ԫ��
    //item��Ż��ݹ����в������Ӽ�
    //result�洢���յ��Ӽ����
    void generate(int i,vector<int>& nums,
                  vector<int>& item,
                  set<vector<int> >& res_set,
                  vector<vector<int> >& result)
    {
        if(i >= nums.size())
            return;
        item.push_back(nums[i]);   //��nums[i]Ԫ�ط����Ӽ���
        if(res_set.find(item) == res_set.end())  //�����������ͬ���Ӽ�
        {
            result.push_back(item);    //����һ���Ӽ�
            res_set.insert(item);      //�����Ӽ���ȥ�ؼ�����
        }

        generate(i + 1, nums, item, res_set, result);  //�����Ӽ�
        item.pop_back();           //��nums[i]Ԫ�ز������Ӽ���
        generate(i + 1, nums, item, res_set, result);  //�����Ӽ�
    }
};
class Solution2
{
    //����λ����ѡ��Ԫ��
public:
    set<vector<int> > res_set;    //����setȥ���ظ�
    vector<vector<int> > subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int> > result;  //�洢���յ��Ӽ����
        sort(nums.begin(), nums.end());//��nums��������

        int all_set = 1 << nums.size(); //�����ڵ��Ӽ���
        for(int i = 0; i < all_set; i++)
        {
            vector<int> item;             //��Ż��ݹ����в������Ӽ�
            for(int j = 0; j < nums.size(); j++)
            {
                if((1 << nums.size() - 1 - j) & i)
                    item.push_back(nums[j]);
            }
            if(res_set.find(item) == res_set.end())  //�����������ͬ���Ӽ�
            {
                result.push_back(item);    //����һ���Ӽ�
                res_set.insert(item);      //�����Ӽ���ȥ�ؼ�����
            }
        }
        return result;
    }
};
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
    vector<int> nums = {1,2,2,2};

    vector<vector<int> > result1 = sol1.subsetsWithDup(nums);
    vector<vector<int> > result2 = sol2.subsetsWithDup(nums);
    printf("the result 1 is \n");
    print_sunsets(result1);
    printf("the result 2 is \n");
    print_sunsets(result2);
    return 0;
}

