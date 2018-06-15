/*
407-�ռ���ˮ
*/
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//����heightMap�������height
struct Qitem
{
    int x;
    int y;
    int h;
    Qitem(int x, int y, int h) : x(x), y(y), h(h) {}
};
//�ȽϺ���������Ƚϵ��ǽṹ�壬��������ıȽϺ�����Ҫ�ýṹ���װ
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
        int row = heightMap.size();       //��ȡ
        int column = heightMap[0].size();
        vector<vector<int> > mark(row, vector<int>(column, 0)); //����mark����Ƿ���뵽������
        for(int i = 0; i < row; i++)        //��������������������������ȥ
        {
            for(int j = 0; j < column; j++)
            {
                if(i !=0 && i != row - 1 &&
                   j != 0 && j != column - 1)  //��������Ǳ߽�ֵ������
                {
                    continue;
                }
                Q.push(Qitem(i, j , heightMap[i][j])); //���߽��push����������
                mark[i][j] = 1;                        //����Ѿ����������
            }
        }
        //��������
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};

        int result  = 0;       //���ջ�ˮ��
        while(!Q.empty())
        {
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();
            for(int i = 0; i < 4; i++)//��չ4������
            {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x < 0 || new_x >= row ||   //����չ�ĵ㳬���߽�����Ѽ������
                   new_y < 0 || new_y >= column || mark[new_x][new_y])
                {
                    continue;
                }
                if(h > heightMap[new_x][new_y])   //���������height�����µ������height��˵��ˮ��������ȥ
                {
                    result += h - heightMap[new_x][new_y]; //������ˮ��������
                    heightMap[new_x][new_y] = h;  //�����µ�����ĸ߶�
                }
                Q.push(Qitem(new_x, new_y, heightMap[new_x][new_y]));//������������Ž�������ȥ
                mark[new_x][new_y] = 1;           //���Ϊ�Ѿ����ʹ�
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
