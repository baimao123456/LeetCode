/*
40-组合数之和2  ---使得子集满足某个和
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
    vector<vector<int> > combinationSum2(vector<int>& nums,
                                         int target)
    {
        vector<vector<int> > result;  //存储最终的子集结果
        vector<int> item;             //存放回溯过程中产生的子集
        set<vector<int> > res_set;    //利用set去除重复
        sort(nums.begin(), nums.end());//对nums进行排序，
        //result.push_back(item);       //先存入一个空集
        generate(0, nums, item, res_set, result, 0, target);  //生成子集
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
                  vector<vector<int> >& result,
                  int sum, int target)
    {
        if(i >= nums.size() || sum > target)
            return;
        sum += nums[i];
        item.push_back(nums[i]);   //将nums[i]元素放入子集中
        if(sum == target && res_set.find(item) == res_set.end())  //如果不存在相同的子集
        {
            result.push_back(item);    //保存一次子集
            res_set.insert(item);      //保存子集到去重集合中
        }

        generate(i + 1, nums, item, res_set, result, sum, target);  //生成子集
        sum -= nums[i];            //回溯后，sum要将ums[i]减去
        item.pop_back();           //将nums[i]元素不放入子集中
        generate(i + 1, nums, item, res_set, result, sum, target);  //生成子集
    }
};
class Solution2
{
    //利用位操作选择元素
public:
    set<vector<int> > res_set;    //利用set去除重复
    vector<vector<int> > combinationSum2(vector<int>& nums, int target)
    {
        vector<vector<int> > result;     //存储最终的子集结果
        sort(nums.begin(), nums.end());  //对nums进行排序，

        int all_set = 1 << nums.size();  //最多存在的子集数
        for(int i = 0; i < all_set; i++) //遍历组合，查找符合条件的子集
        {
            vector<int> item;             //保存生成的子集
            int sum = 0;
            for(int j = 0; j < nums.size(); j++)  //判断某个元素是否在子集中
            {
                if((1 << nums.size() - 1 - j) & i)
                {
                    sum += nums[j];         //累计子集的和
                    item.push_back(nums[j]);
                }
            }
            //如果不存在相同的子集，且子集的和sum等于target
            if((res_set.find(item) == res_set.end())
                                   && sum == target)
            {
                result.push_back(item);    //保存一次子集
                res_set.insert(item);      //保存子集到去重集合中
            }
        }
        return result;
    }
};
//打印子集
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



