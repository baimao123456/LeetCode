/*
//174-������Ϸ
*/
#include <vector>
#include <stack>
#include <stdio.h>
using namespace std;
class Solution
{
public:
    //�����½������Ͻǵ���
    int calculateMinimumHP(vector<vector<int> > &dungeon)
    {
        if(dungeon.size() == 0)
            return 0;

        int row = dungeon.size();     //����
        int col = dungeon[0].size();  //����
        vector<vector<int> > dp(row, vector<int>(col, 0));

        dp[row - 1][col - 1] = max(1, 1 - dungeon[row - 1][col - 1]);

        for(int i = row - 2; i >= 0; i--)   //���һ��ֻ������
            dp[i][col - 1] = max(1, dp[i + 1][col - 1] - dungeon[i][col - 1]);

        for(int i = col - 2; i >= 0; i--)   //���һ��ֻ������
            dp[row - 1][i] = max(1, dp[row - 1][i + 1] - dungeon[row - 1][i]);

        for(int i = row - 2; i >= 0; i--)   //�����½������Ͻǵ���
        {
            for(int j = col - 2; j >= 0; j--)
            {
                int dp_min = min(dp[i + 1][j], dp[i][j + 1]);  //��֤ÿ��·������������������ѡ���Ѫ���ٵĵ�
                dp[i][j] = max(1, dp_min - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
int main(void)
{
    int test[][3] = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    vector<vector<int> > dungeon;
    for(int i = 0; i < 3; i++)
    {
        dungeon.push_back(vector<int>());
        for(int j = 0;j < 3;j++)
        {
            dungeon[i].push_back(test[i][j]);
        }
    }
    Solution sol;
    printf("%d\n", sol.calculateMinimumHP(dungeon));
    return 0;
}

