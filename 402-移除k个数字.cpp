/*
移除k个数字
*/
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
class Solution1
{
public:
    string removeKdigits(string num, int k)
    {
        vector<int> S;  //这里使用vector，因为可以遍历
        string result = "";  //存储返回的结果
        for(int i = 0; i < num.size(); i++)
        {
            int number = num[i] - '0';   //将字符转成int数字
            //如果栈不空，且栈顶元素大于number，仍然可以删除元素时，继续循环
            while(S.size() != 0 && S.back() > number && k > 0)
            {
                S.pop_back();
                k--;
            }
            if(number != 0 || S.size() != 0) //如果S为空，且number是0，则忽略number，
                S.push_back(number);   //将数字压入栈中
        }
        while(S.size() != 0 && k >0)  //如果栈不空，且仍然可以删除数字
        {
            S.pop_back();   //删除栈顶元素
            k--;            //删除数字后更新
        }
        for(int i = 0; i < S.size(); i++)
            result += S[i] + '0';

        if(result == "")
            result = "0";

        return result;
    }
};
class Solution2
{
    //直接对string进行操作
public:
    string removeKdigits(string num, int k)
    {
        string result = "";  //存储返回的结果
        for(int i = 0; i < num.size(); i++)
        {
           if(num[i] > num[i + 1] && k > 0) //如果后边的数字比前边的小,跳出当前循环
           {
               k--;                         //
               continue;                    //不满足条件，跳出当前循环
           }
           if(result.size() != 0 || num[i] != '0') //如果首字符是'0'，则不用加到result中
                result += num[i];
        }
        while(result.size() > 0 && k > 0)   //如果栈不空，且仍然可以删除数字
        {
            result.erase(result.end() - 1); //删除字符串末尾的字符
            k--;
        }
        if(result == "")                    //如果是空，返回0
            result = "0";
        return result;
    }
};
int main(void)
{
    Solution1 sol1;
    Solution2 sol2;
    string result = sol1.removeKdigits("1432219", 3);
    printf("%s\n",result.c_str());
    string result2 = sol1.removeKdigits("100200", 1);
    printf("%s\n",result2.c_str());
    string result3 = sol1.removeKdigits("14345109", 2);
    printf("%s\n",result3.c_str());

    string result4 = sol2.removeKdigits("14345109", 2);
    printf("%s\n",result4.c_str());
    return 0;
}
