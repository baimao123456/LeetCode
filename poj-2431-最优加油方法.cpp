/*
最优加油方法
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//比较函数，降序排序--按返回为1进行排序，
bool cmp(const pair<int, int>& a,const pair<int, int>& b)
{
    return a.first > b.first;  //返回为1，就是降序排序
}
//L为起点到终点的距离
//P为油箱剩余的油量
//pair<加油站到终点的距离,加油站的油量>
int get_minimum_stop(int L, int P,vector<pair<int, int> >& stop)
{
    priority_queue<int> Q;   //存储油量的最大堆
    int result = 0;
    stop.push_back(make_pair(0,0)); //将终点作为一个停靠点
    sort(stop.begin(), stop.end(), cmp);
    for(int i = 0; i < stop.size(); i++)
    {
        int dis = L - stop[i].first;//当前要走的距离
        //如果已经路过加油站，且当前的油量不能继续走下一距离
        //则进行加油，加油量为路过的油量最多的加油站
        while(!Q.empty() && P < dis)
        {
            P += Q.top();    //加最多的油（贪心的体现）
            Q.pop();
            result++;        //记录加油次数
        }
        if(P < dis)          //如果每个加油站都加油了，油还是不够，则不能到达终点
            return -1;
        P = P - dis;         //更新剩余的油量
        L = stop[i].first;   //更新L为当前停靠站到终点的距离
        Q.push(stop[i].second); //将当前停靠站的油量加入最大堆
    }
    return result;
}
int main(void)
{
    vector<pair<int, int> > stop;
    int N,L,P;
    int distance;
    int fuel;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &distance, &fuel);
        stop.push_back(make_pair(distance, fuel));
    }
    scanf("%d %d", &L, &P);
    printf("%d\n", get_minimum_stop(L,P,stop));
    return 0;
}
