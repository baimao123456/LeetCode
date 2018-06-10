/*
90-求子集2--去除重复
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class Solution1
{
    //回溯法，递归 set去除重复子集
public:

    vector<vector<int> > subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int> > result;  //存储最终的子集结果
        vector<int> item;             //存放回溯过程中产生的子集
        set<vector<int> > res_set;    //利用set去除重复
        sort(nums.begin(), nums.end());//对nums进行排序，
        result.push_back(item);       //先存入一个空集
        generate(0, nums, item, res_set, result);  //生成子集
        return result;
    }
private:
    //生成子集
    //i用来选择nums中的元素
    //item存放回溯过程中产生的子集
    //result存储最终的子集结果
    void generate(int i,vector<int>& nums,
                  vector<int>& item,
                  set<vector<int> >& res_set,
                  vector<vector<int> >& result)
    {
        if(i >= nums.size())
            return;
        item.push_back(nums[i]);   //将nums[i]元素放入子集中
        if(res_set.find(item) == res_set.end())  //如果不存在相同的子集
        {
            result.push_back(item);    //保存一次子集
            res_set.insert(item);      //保存子集到去重集合中
        }

        generate(i + 1, nums, item, res_set, result);  //生成子集
        item.pop_back();           //将nums[i]元素不放入子集中
        generate(i + 1, nums, item, res_set, result);  //生成子集
    }
};
class Solution2
{
    //利用位操作选择元素
public:
    set<vector<int> > res_set;    //利用set去除重复
    vector<vector<int> > subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int> > result;  //存储最终的子集结果
        sort(nums.begin(), nums.end());//对nums进行排序，

        int all_set = 1 << nums.size(); //最多存在的子集数
        for(int i = 0; i < all_set; i++)
        {
            vector<int> item;             //存放回溯过程中产生的子集
            for(int j = 0; j < nums.size(); j++)
            {
                if((1 << nums.size() - 1 - j) & i)
                    item.push_back(nums[j]);
            }
            if(res_set.find(item) == res_set.end())  //如果不存在相同的子集
            {
                result.push_back(item);    //保存一次子集
                res_set.insert(item);      //保存子集到去重集合中
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

