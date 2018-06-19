/*
//120-��������С·����
*/
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //
    int minimumTotal(vector<vector<int> > &triangle)
    {
        if(triangle.size() == 0)
            return 0;
        //��ʼ��dp,dp[i][j]��ʾ�������ϵ��ƣ��ߵ������ε�i�е�j�е����Ž�
        vector<vector<int> >dp(triangle.size(), vector<int>(triangle.size(), 0));
        //��dp�����һ���ʼ��Ϊtriangle�����һ��
        for(int i = 0; i < dp.size();i++)
            dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];
        //��������Ѱ����Сֵ��·����
        for(int i = dp.size() - 2;i >= 0; i--)
            for(int j = 0; j < dp[i].size();j++)
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];

        return dp[0][0];
    }
};
int main(void)
{
    vector<vector<int> > triangle;
    int test[][10] = {{2},{3, 4},{6, 5, 7},{4, 1, 8, 3}};
    for(int i = 0; i < 4; i++)
    {
        triangle.push_back(vector<int>());
        for(int j = 0;j < i + 1;j++)
        {
            triangle[i].push_back(test[i][j]);
        }
    }
    Solution sol;
    printf("%d\n", sol.minimumTotal(triangle));
    return 0;
}




