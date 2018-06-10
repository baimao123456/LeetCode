/*
//22-生成括号
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
    //item用来保存生成的括号，leftright分别为可放置左右括号的数量，
    //result是生成括号的集合
    void generate(string item,int left, int right,
                  vector<string>& result)
    {
        if(left == 0 && right == 0) //如果左右括号全部放置完成
        {
            result.push_back(item);
            return;
        }
        if(left > 0) //优先放置左括号
            generate(item + "(", left - 1, right, result);    //添加左括号
        if(left < right)  //如果已经放置左括号，才能放置右括号
        generate(item + ")", left, right - 1, result);    //添加右括号
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
