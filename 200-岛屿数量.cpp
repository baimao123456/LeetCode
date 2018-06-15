/*
//200-��������
*/
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

//�����������
//mark����Ƿ���������gridΪ����ı��,(x, y)Ϊ������λ��
void DFS(vector<vector<int> > &mark,vector<vector<char> > &grid, int x, int y)
{
    mark[x][y] = 1;             //�����������λ��
    static const int dx[] = {-1, 1, 0, 0};  //��������
    static const int dy[] = {0, 0, -1, 1};  //��������
    for(int i = 0; i < 4; i++)  //���ĸ������������
    {
        int new_x = x + dx[i];  //����µ���������
        int new_y = y + dy[i];
        //�������Խ�磬������һ�����������
        if(new_x < 0 || new_x >= mark.size() ||
           new_y < 0 || new_y >= mark[new_x].size())
        {
            continue;
        }
        if(mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1')        //�����new_x,new_y��û��������
        {
            DFS(mark,grid, new_x, new_y);
        }
    }
}
//�����������
void BFS(vector<vector<int> > &mark,vector<vector<char> > &grid, int x, int y)
{
    static const int dx[] = {-1, 1, 0, 0};  //��������
    static const int dy[] = {0, 0, -1, 1};  //��������
    queue<pair<int, int> > Q;   //���������������
    Q.push(make_pair(x, y));    //����x��y��ѹ����У��������
    mark[x][y] = 1;             //�����������λ��
    while(!Q.empty())
    {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();                //��Ϊ��x��y���Ѿ������������ｫ��x��y���Ӷ����е���
        for(int i = 0; i < 4; i++)  //���ĸ������������
        {
            int new_x = x + dx[i];  //����µ���������
            int new_y = y + dy[i];
            //�������Խ�磬������һ�����������
            if(new_x < 0 || new_x >= mark.size() ||
               new_y < 0 || new_y >= mark[new_x].size())
            {
                continue;
            }
            //�����new_x,new_y��û��������,��Ϊ½��
            if(mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1')
            {
                Q.push(make_pair(new_x, new_y)); //����λ�ã�new_x��new_y��ѹ����У��������
                mark[new_x][new_y] = 1;          //�����������λ��
            }
        }
    }
}
class Solution
{
public:
    int numIslands(vector<vector<char> > &grid)
    {
        int island_num = 0;                  //���������
        vector<vector<int> > mark;           //��������Ƿ�������
        for(int i = 0; i < grid.size();i++)  //����һ���յĶ�ά����mark���������
        {
            mark.push_back(vector<int >());
            for(int j = 0; j < grid[i].size(); j++)
            {
                mark[i].push_back(0);
            }
        }
        for(int i = 0; i < grid.size();i++)  //����һ���յĶ�ά����mark���������
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
