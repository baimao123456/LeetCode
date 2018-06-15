/*
407-收集雨水
*/
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//保存heightMap的坐标和height
struct Qitem
{
    int x;
    int y;
    int h;
    Qitem(int x, int y, int h) : x(x), y(y), h(h) {}
};
//比较函数，这里比较的是结构体，所以这里的比较函数需要用结构体封装
struct cmp
{
    bool operator()(const Qitem &a, const Qitem &b)
    {
        return a.h > b.h;
    }
};
class Solution1
{
public:
    int trapRainWater(vector<vector<int> > &heightMap)
    {
        priority_queue<Qitem, vector<Qitem> , cmp > Q;
        if(heightMap.size() < 3 || heightMap[0].size() < 3)
            return 0;
        int row = heightMap.size();       //获取
        int column = heightMap[0].size();
        vector<vector<int> > mark(row, vector<int>(column, 0)); //定义mark标记是否加入到队列中
        for(int i = 0; i < row; i++)        //将最外面的坐标加入搜索队列中去
        {
            for(int j = 0; j < column; j++)
            {
                if(i !=0 && i != row - 1 &&
                   j != 0 && j != column - 1)  //如果遇到非边界值，忽略
                {
                    continue;
                }
                Q.push(Qitem(i, j , heightMap[i][j])); //将边界点push进搜索队列
                mark[i][j] = 1;                        //标记已经加入队列中
            }
        }
        //方向数组
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};

        int result  = 0;       //最终积水量
        while(!Q.empty())
        {
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();
            for(int i = 0; i < 4; i++)//拓展4个方向
            {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x < 0 || new_x >= row ||   //新拓展的点超出边界或者已加入队列
                   new_y < 0 || new_y >= column || mark[new_x][new_y])
                {
                    continue;
                }
                if(h > heightMap[new_x][new_y])   //如果搜索的height大于新的坐标的height，说明水可以流进去
                {
                    result += h - heightMap[new_x][new_y]; //积累雨水数量增加
                    heightMap[new_x][new_y] = h;  //更新新的坐标的高度
                }
                Q.push(Qitem(new_x, new_y, heightMap[new_x][new_y]));//将搜索的坐标放进队列中去
                mark[new_x][new_y] = 1;           //标记为已经访问过
            }
        }
        return result;
    }
};
int main(void)
{
    int test[][10] = {
    {1,4,3,1,3,2},
    {3,2,1,3,2,4},
    {2,3,3,2,3,1}
    };
    vector<vector<int> > heightMap;
    for(int i = 0; i < 3; i++)
    {
        heightMap.push_back(vector<int> ());
        for(int j = 0; j < 6; j++)
            heightMap[i].push_back(test[i][j]);
    }
    Solution1 sol;
    printf("%d\n", sol.trapRainWater(heightMap));
    return 0;
}
