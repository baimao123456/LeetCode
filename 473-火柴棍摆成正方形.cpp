/*
473-火柴棍摆成正方形
*/
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool cmp(int &a, int &b)
{
    return a > b;
}
class Solution1
{
public:
    //判断是否能生成正方形
    bool makesquare(vector<int> &nums)
    {
        if(nums.size() < 4)   //正方形至少4条边
            return false;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if(sum % 4 != 0)     //如果sum不能整除4，则不能构成4边形
            return false;
        sort(nums.begin(), nums.end());
        int bucket[4] = {0};  //定义4个桶保存4个边长
        return generate(0, nums, sum / 4, bucket);
    }
private:
    //i为nums元素，nums保存火柴棍的长度，target为最终正方形的边长，bucket存放正方形的边长
    bool generate(int i, vector<int> &nums, int target, int bucket[])
    {
        if(i >= nums.size())               //如果火柴棍全部用完，判断4个边是否相同
            return bucket[0] == target && bucket[1] == target
                && bucket[2] == target && bucket[3] == target;
        for(int j = 0;j < 4; j++)           //在4个桶中分别尝试
        {
            if(bucket[j] + nums[i] > target) //如果将火柴棍nums[i]放进bucket[j]超过最大边长，则尝试其他的边
                continue;
            bucket[j] += nums[i];            //放在j桶中
            if(generate(i + 1, nums, target, bucket)) //将下一个火柴棍放进桶中
            {
                return true;
            }
            bucket[j] -= nums[i];            //从j桶中取出，回溯过程
        }
        return false;
    }
};
class Solution2
{
public:
    //判断是否能生成正方形--利用位运算
    bool makesquare(vector<int> &nums)
    {
        if(nums.size() < 4)     //正方形至少4条边
            return false;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if(sum % 4 != 0)         //如果sum不能整除4，则不能构成4边形
            return false;
        int target = sum / 4;
        vector<int> ok_subset;   //所有满足条件的1条边的集合
        vector<int> ok_half;     //所有满足条件的2条边的集合
        int all = 1 << nums.size();   //all数字对应的位如果是1，表示被选中
        for(int i = 0; i < all; i++)
        {
            int sum = 0;
            for(int j = 0; j < nums.size();j++)
            {
                if(i &(1 << j))  //如果第j个数被选中，则进行相加
                    sum += nums[j];
            }
            if(sum == target)    //如果sum等于边长，则将该集合push进ok_subset
                ok_subset.push_back(i);
        }
        for(int i = 0; i < ok_subset.size(); i++)  //两两相与，如果为0，表示这两个集合独立
        {
            for(int j = i + 1; j < ok_subset.size(); j++)
            {
                if((ok_subset[i] & ok_subset[j]) == 0)
                    ok_half.push_back(ok_subset[i] | ok_subset[j]);//存储两个集合的并集
            }
        }
        for(int i = 0; i < ok_half.size(); i++)   //再次判断两个集合是否独立，
        {
            for(int j = i + 1; j < ok_half.size(); j++)
            {
                if((ok_half[i] & ok_half[j]) == 0)//如果相与为0，说明独立且满足条件，否则不成立
                    return true;
            }
        }
    }
};
class Solution3
{
public:
    //利用双向队列，队列中元素从大到小，
    //每次从前后找到两个元素，使其能构成一个边，然后将符合条件的元素pop出
    //如果最后队列为空，说明可以构成一个正方形
    bool makesquare(vector<int> &nums)
    {
        if(nums.size() < 4)
            return false;

        sort(nums.begin(), nums.end(), cmp);   //将元素从大到小排列
        deque<int> Q;
        int sum = 0;                //火柴棍的总和
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            Q.push_back(nums[i]);
        }
        if(sum % 4 != 0)            //如果sum不是4的倍数，则不能构成正方形
            return false;
        int target = sum / 4;       //正方形的边长
        while(!Q.empty())
        {
            int value = Q.front();
            Q.pop_front();
            while(value < target)   //如果边不够target，则从小的一端拿出一端，直到满足
            {
                value += Q.back();
                Q.pop_back();
            }
        }
        return Q.empty();
    }
};
int main(void)
{
    vector<int> nums = {1,1,2,4,3,2,3};
    Solution1 sol1;
    printf("%d", sol1.makesquare(nums));
    Solution2 sol2;
    printf("%d", sol2.makesquare(nums));
    Solution3 sol3;
    printf("%d", sol3.makesquare(nums));
    return 0;
}
