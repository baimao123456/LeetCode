/*
//51--N�ʺ�����
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
        vector<vector<string> > result;   //�������յĽ��
        vector<vector<int> > mark;        //����
        vector<string> location;          //�洢ĳ���ڷŽ��
        for(int i = 0;i < n; i++)         //����n*n�Ķ�ά����,�������
        {
            mark.push_back(vector<int>());
            for(int j = 0;j < n; j++)
                mark[i].push_back(0);     //��ʼ��Ϊ0
            location.push_back("");       //��ʼ���ڷŽ��ȫ��Ϊ'.'
            location[i].append(n, '.');   //���8��'.'
        }
        generate(0, n, location, result, mark);
        return result;
    }
private:
    //��(x,y)λ���Ϸ��ûʺ󣬲��Ҹ�������
    void put_down_the_queen(int x, int y,
                        vector<vector<int> >& mark)
    {
        //��������
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1;  //��(x,y)�����ûʺ�
        for(int i = 1; i < mark.size(); i++)
        {
            for(int j = 0; j < 8; j++)   //8������ֱ����� i ����λ
            {
                int new_x = x + i * dx[j];
                int new_y = y + i * dy[j];
                //�����λ���Ƿ���������
                if(new_x >= 0 && new_x < mark.size() &&
                   new_y >= 0 && new_y < mark.size() )
                {
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }

    void generate(int k, int n,     //k����������˼����ʺ�ķ���
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
