/*
//22-��������
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
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generate("", n, n, result);
        return result;
    }
private:
    //item�����������ɵ����ţ�leftright�ֱ�Ϊ�ɷ����������ŵ�������
    //result���������ŵļ���
    void generate(string item,int left, int right,
                  vector<string>& result)
    {
        if(left == 0 && right == 0) //�����������ȫ���������
        {
            result.push_back(item);
            return;
        }
        if(left > 0) //���ȷ���������
            generate(item + "(", left - 1, right, result);    //���������
        if(left < right)  //����Ѿ����������ţ����ܷ���������
        generate(item + ")", left, right - 1, result);    //���������
    }
};
int main(void)
{
    Solution sol;
    vector<string> result = sol.generateParenthesis(3);
    for(int i = 0;i < result.size();i++)
    {
        printf("%s\n",result[i].c_str());
    }
    return 0;
}
