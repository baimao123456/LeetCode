/*
射击气球
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
//比较函数，升序排序--按返回为1进行排序，
bool cmp(pair<int, int> a,pair<int, int> b)
{
    return a.first < b.first;  //返回为1，就是升序排序
}
class Solution
{
public:
    int findMinArrowShots(vector<pair<int, int> >& points)
    {
        if(points.size() == 0)
            return 0;
        sort(points.begin(), points.end(),cmp);  //按左节点进行排序
        int shot_num = 1;                        //射击次数
        int shot_begin = points[0].first;        //初始化射击区间，即为第一个气球的两端点
        int shot_end = points[0].second;
        for(int i = 1; i < points.size(); i++)
        {
            //如果下个气球的坐标起始点大于shot_end，
            //说明这个气球和之前的气球没有重合的区间，就不能一箭全部射掉
            if(points[i].first <= shot_end)
            {
                shot_begin = points[i].first;  //更新的射击区间的左端点就是新气球的左端点
                if(shot_end > points[i].second)
                    shot_end = points[i].second;
            }
            //新气球的左端点比shot_end还要大，
            //新的气球肯定不在原来的射击区间内
            //需要增加箭
            else
            {
                shot_num++;
                shot_begin = points[i].first;  //更新射击区间为新的气球的左右端点
                shot_end = points[i].second;
            }
        }
        return shot_num;
    }
};
int main(void)
{
    vector<pair<int, int> > points;
    points.push_back(make_pair(10,16));
    points.push_back(make_pair(2,8));
    points.push_back(make_pair(1,6));
    points.push_back(make_pair(7,12));

    Solution sol;
    printf("%d\n", sol.findMinArrowShots(points));
    return 0;
}
