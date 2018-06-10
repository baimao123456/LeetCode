/*
40-�����֮��2  ---ʹ���Ӽ�����ĳ����
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
    vector<vector<int> > combinationSum2(vector<int>& nums,
                                         int target)
    {
        vector<vector<int> > result;  //�洢���յ��Ӽ����
        vector<int> item;             //��Ż��ݹ����в������Ӽ�
        set<vector<int> > res_set;    //����setȥ���ظ�
        sort(nums.begin(), nums.end());//��nums��������
        //result.push_back(item);       //�ȴ���һ���ռ�
        generate(0, nums, item, res_set, result, 0, target);  //�����Ӽ�
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
                  vector<vector<int> >& result,
                  int sum, int target)
    {
        if(i >= nums.size() || sum > target)
            return;
        sum += nums[i];
        item.push_back(nums[i]);   //��nums[i]Ԫ�ط����Ӽ���
        if(sum == target && res_set.find(item) == res_set.end())  //�����������ͬ���Ӽ�
        {
            result.push_back(item);    //����һ���Ӽ�
            res_set.insert(item);      //�����Ӽ���ȥ�ؼ�����
        }

        generate(i + 1, nums, item, res_set, result, sum, target);  //�����Ӽ�
        sum -= nums[i];            //���ݺ�sumҪ��ums[i]��ȥ
        item.pop_back();           //��nums[i]Ԫ�ز������Ӽ���
        generate(i + 1, nums, item, res_set, result, sum, target);  //�����Ӽ�
    }
};
class Solution2
{
    //����λ����ѡ��Ԫ��
public:
    set<vector<int> > res_set;    //����setȥ���ظ�
    vector<vector<int> > combinationSum2(vector<int>& nums, int target)
    {
        vector<vector<int> > result;     //�洢���յ��Ӽ����
        sort(nums.begin(), nums.end());  //��nums��������

        int all_set = 1 << nums.size();  //�����ڵ��Ӽ���
        for(int i = 0; i < all_set; i++) //������ϣ����ҷ����������Ӽ�
        {
            vector<int> item;             //�������ɵ��Ӽ�
            int sum = 0;
            for(int j = 0; j < nums.size(); j++)  //�ж�ĳ��Ԫ���Ƿ����Ӽ���
            {
                if((1 << nums.size() - 1 - j) & i)
                {
                    sum += nums[j];         //�ۼ��Ӽ��ĺ�
                    item.push_back(nums[j]);
                }
            }
            //�����������ͬ���Ӽ������Ӽ��ĺ�sum����target
            if((res_set.find(item) == res_set.end())
                                   && sum == target)
            {
                result.push_back(item);    //����һ���Ӽ�
                res_set.insert(item);      //�����Ӽ���ȥ�ؼ�����
            }
        }
        return result;
    }
};
//��ӡ�Ӽ�
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
    vector<int> nums = {10,1,2,7,6,1,5};

    vector<vector<int> > result1 = sol1.combinationSum2(nums, 8);
    printf("the result 1 is \n");
    print_sunsets(result1);

    vector<vector<int> > result2 = sol2.combinationSum2(nums, 8);
    printf("the result 2 is \n");
    print_sunsets(result2);
    return 0;
}



