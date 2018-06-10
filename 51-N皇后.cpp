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
        if(k == n)   //如果已经完成n行皇后的放置，将放置结果保存到result
        {
            result.push_back(location);
            return;  //返回执行回溯，查找别的摆放方案
        }
        for(int i = 0; i < n; i++) //按顺序尝试在第k行第i列放置皇后
        {
            if(mark[k][i] == 0)    // == 0，表示可以放置皇后
            {
                vector<vector<int> > tem_mark = mark;//记录回溯前的mark
                location[k][i] = 'Q';
                put_down_the_queen(k, i, mark);      //在第k行,第i列放置皇后
                generate(k + 1, n, location, result, mark); //递归进行下一个皇后的放置
                //回溯到之前的状态,重新进行查找
                mark = tem_mark;      //将mark还原回回溯前的状态
                location[k][i] = '.'; //将当前尝试的放置皇后的位置重新置'.'
            }
            //如果程序执行到这里，说明第k+1行每一列都不能放置，
            //这时候要回溯到第k行，从i往后的列中重新找位置放皇后
            //如果还是不能放，则继续，直到第0行
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
