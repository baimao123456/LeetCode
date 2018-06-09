/*
455-���ǹ�-̰���㷨
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());  //��s��g��������sortĬ���ǴӴ�С����
        sort(s.begin(), s.end());
        int child = 0;   //child���������˼�������
        int cookie = 0;  //cookie�����õ����ĸ��ǹ�
        while(child <g.size() && cookie < s.size())
        {
            if(g[child] <= s[cookie])  //�������ǹ�������child��child++������
                child++;
            cookie++;
        }
        return child;   //���յ�child������ĺ��ӵĸ���
    }
};
int main()
{
    vector<int> g = {5,10,2,9,15,9};
    vector<int> s = {6,1,20,3,8};
    Solution sol;
    printf("the total sum of content children is %d \n",sol.findContentChildren(g,s));
    return 0;
}
