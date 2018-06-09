/*
455-分糖果-贪心算法
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());  //对s和g进行排序。sort默认是从大到小排序
        sort(s.begin(), s.end());
        int child = 0;   //child代表满足了几个孩子
        int cookie = 0;  //cookie代表用的是哪个糖果
        while(child <g.size() && cookie < s.size())
        {
            if(g[child] <= s[cookie])  //如果这个糖果能满足child，child++，并且
                child++;
            cookie++;
        }
        return child;   //最终的child是满足的孩子的个数
    }
};
int main()
{
    vector<int> g = {5,10,2,9,15,9};
    vector<int> s = {6,1,20,3,8};
    Solution sol;
    printf("the total sum of content children is %d \n",sol.findContentChildren(g,s));
    return 0;
}
