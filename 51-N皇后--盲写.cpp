/*
//51--N皇后问题
*/
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;
class Solution
{
public:
    vector<vector<string> > solveNQueens(int n)
    {
        vector<vector<string> > result;   //保存最终的结果
        vector<vector<int> > mark;        //棋盘
        vector<string> location;          //存储某个摆放结果
        for(int i = 0;i < n; i++)         //构造n*n的二维数组,标记棋盘
        {
            mark.push_back(vector<int>());
            for(int j = 0;j < n; j++)
                mark[i].push_back(0);     //初始化为0
            location.push_back("");       //初始化摆放结果全部为'.'
            location[i].append(n, '.');   //填充8个'.'
        }
        generate(0, n, location, result, mark);
        return result;
    }
private:
    //在(x,y)位置上放置皇后，并且更新棋盘
    void put_down_the_queen(int x, int y,
                        vector<vector<int> >& mark)
    {
        //方向数组
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1;  //在(x,y)处放置皇后
        for(int i = 1; i < mark.size(); i++)
        {
            for(int j = 0; j < 8; j++)   //8个方向分别延伸 i 个单位
            {
                int new_x = x + i * dx[j];
                int new_y = y + i * dy[j];
                //检查新位置是否还在棋盘内
                if(new_x >= 0 && new_x < mark.size() &&
                   new_y >= 0 && new_y < mark.size() )
                {
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }

    void generate(int k, int n,     //k代表了完成了几个皇后的放置
                  vector<string>& location,
                  vector<vector<string> >& result,
                  vector<vector<int> >& mark)
    {
       if(k == n)
       {
           result.push_back(location);
           return;
       }
       for(int i = 0; i < mark.size(); i++)
       {
           if(mark[k][i] == 0)
           {
               vector<vector<int> > temp_mark = mark;
               put_down_the_queen(k, i, mark);
               location[k][i] = 'Q';
               generate(k + 1, n, location, result, mark);
               mark = temp_mark;
               location[k][i] = '.';
           }
       }
    }
};

int main(void)
{
    Solution sol;
    vector<vector<string> > result;
    result = sol.solveNQueens(8);
    for(int i = 0; i < result.size(); i++)
    {
        printf("i = %d\n",i);
        for(int j = 0; j < result[i].size(); j++)
        {
            printf("%s\n",result[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}
