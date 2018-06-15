/*
//200-岛屿数量
*/
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

//深度优先搜索
//mark标记是否搜索到，grid为岛屿的标记,(x, y)为搜索的位置
void DFS(vector<vector<int> > &mark,vector<vector<char> > &grid, int x, int y)
{
    mark[x][y] = 1;             //标记已搜索的位置
    static const int dx[] = {-1, 1, 0, 0};  //方向数组
    static const int dy[] = {0, 0, -1, 1};  //方向数组
    for(int i = 0; i < 4; i++)  //对四个方向进行搜索
    {
        int new_x = x + dx[i];  //获得新的搜索坐标
        int new_y = y + dy[i];
        //如果坐标越界，继续下一个方向的搜索
        if(new_x < 0 || new_x >= mark.size() ||
           new_y < 0 || new_y >= mark[new_x].size())
        {
            continue;
        }
        if(mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1')        //如果（new_x,new_y）没有搜索过
        {
            DFS(mark,grid, new_x, new_y);
        }
    }
}
//广度优先搜索
void BFS(vector<vector<int> > &mark,vector<vector<char> > &grid, int x, int y)
{
    static const int dx[] = {-1, 1, 0, 0};  //方向数组
    static const int dy[] = {0, 0, -1, 1};  //方向数组
    queue<pair<int, int> > Q;   //广度优先搜索队列
    Q.push(make_pair(x, y));    //将（x，y）压入队列，并做标记
    mark[x][y] = 1;             //标记已搜索的位置
    while(!Q.empty())
    {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();                //因为（x，y）已经搜索到，这里将（x，y）从队列中弹出
        for(int i = 0; i < 4; i++)  //对四个方向进行搜索
        {
            int new_x = x + dx[i];  //获得新的搜索坐标
            int new_y = y + dy[i];
            //如果坐标越界，继续下一个方向的搜索
            if(new_x < 0 || new_x >= mark.size() ||
               new_y < 0 || new_y >= mark[new_x].size())
            {
                continue;
            }
            //如果（new_x,new_y）没有搜索过,且为陆地
            if(mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1')
            {
                Q.push(make_pair(new_x, new_y)); //将新位置（new_x，new_y）压入队列，并做标记
                mark[new_x][new_y] = 1;          //标记已搜索的位置
            }
        }
    }
}
class Solution
{
public:
    int numIslands(vector<vector<char> > &grid)
    {
        int island_num = 0;                  //岛屿的数量
        vector<vector<int> > mark;           //用来标记是否被搜索过
        for(int i = 0; i < grid.size();i++)  //构造一个空的二维向量mark，用来标记
        {
            mark.push_back(vector<int >());
            for(int j = 0; j < grid[i].size(); j++)
            {
                mark[i].push_back(0);
            }
        }
        for(int i = 0; i < grid.size();i++)  //构造一个空的二维向量mark，用来标记
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(mark[i][j] == 0 && grid[i][j] == '1')
                {
                    DFS(mark, grid, i, j);
                    island_num++;
                }

            }
        }
        return island_num;
    }
};
int main(void)
{
    vector<vector<char> > grid;
    char str[10][10] = {"11000","00100","00100","00011"};
    for(int i = 0; i < 4; i++)
    {
        grid.push_back(vector<char>());
        for(int j = 0; j < 5;j++)
            grid[i].push_back(str[i][j]);
    }
    Solution sol;
    printf("%d",sol.numIslands(grid));
    return 0;
}
