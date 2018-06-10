/*
//315-逆序数
*/
#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    //计算逆序对的个数，利用归并排序，先分解成小问题并计算逆序对个数
    //计算子数组的逆序对之后，要进行排序，防止多计数
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<pair<int, int> > vec;
        vector<int> count;
        //将nums[i]绑定为(nums[i],i)
        for(int i = 0; i < nums.size(); i++)
        {
            vec.push_back(make_pair(nums[i], i));
            count.push_back(0);
        }
        merge_sort(vec, count); //归并排序中进行逆序对个数的统计
        return count;           //保存了当前元素的逆序对个数
    }
private:
    void merge_sort(vector<pair<int, int> >& vec, vector<int>& count)
    {
        if(vec.size() < 2)              //子问题足够小时,直接求解
            return;
        int mid = vec.size() / 2;       //对原问题进行分解，划分成两个小问题，分别排序
        vector<pair<int, int> > sub_vec1;           //子数组1
        vector<pair<int, int> > sub_vec2;           //子数组2
        for(int i = 0; i < mid; i++)    //将原来的数组分成两部分
        {
            sub_vec1.push_back(vec[i]);
        }
        for(int j = mid; j < vec.size(); j++)
        {
            sub_vec2.push_back(vec[j]);
        }

        merge_sort(sub_vec1, count);       //求解子问题
        merge_sort(sub_vec2, count);
        vec.clear();
        merge_sort_two_vec(sub_vec1, sub_vec2, vec, count);//将求的子问题解进行合并
    }
    //合并两个有序vector
    void merge_sort_two_vec(vector<pair<int, int> >& sub_vec1, vector<pair<int, int> >& sub_vec2,
                            vector<pair<int, int> >& vec, vector<int>& count)
    {
        int i = 0, j = 0;
        while(i < sub_vec1.size() && j < sub_vec2.size())
        {
            if(sub_vec1[i].first <= sub_vec2[j].first) //这里的first才是nums[i]
            {
                count[sub_vec1[i].second] += j; //增加逆序对的个数
                vec.push_back(sub_vec1[i]);
                i++;
            }
            else
            {
                vec.push_back(sub_vec2[j]);
                j++;
            }
        }
        for(;i < sub_vec1.size(); i++)
        {
            count[sub_vec1[i].second] += j;
            vec.push_back(sub_vec1[i]);
        }
        for(;j < sub_vec2.size(); j++)
        {
            vec.push_back(sub_vec2[j]);
        }
    }
};
int main(void)
{
    Solution sol;
    vector<int> nums = {5,-7,9,1,3,5,-2,1};
    vector<int> count = sol.countSmaller(nums);
    for(int i = 0;i < count.size(); i++)
    {
        printf("[%d] ",count[i]);
    }
    return 0;
}

