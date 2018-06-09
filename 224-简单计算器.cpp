/*
简单计算器
*/
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;
void compute(stack<int> &number_stack, stack<char> &operation_stack)
{
    if(number_stack.size() < 2) // 数字至少为2，否则无法计算
        return;
    int num2 = number_stack.top();  //取出两个数，进行计算
    number_stack.pop();
    int num1 = number_stack.top();
    number_stack.pop();

    if(operation_stack.top() == '+')      //从符号栈中取符号进行计算，将计算后的值重新压入数字栈
        number_stack.push(num1 + num2);
    else if(operation_stack.top() == '-')
        number_stack.push(num1 - num2);

    operation_stack.pop();  //符号用完之后，需要弹出
}
class Solution
{
public:
    int calculate(string s)
    {
        static const int STATE_BEGIN = 0;
        static const int NUMBER_STATE = 1;
        static const int OPERATION_STATE = 2;

        stack<int> number_stack;           //数字栈
        stack<char> operation_stack;       //操作符栈
        int number = 0;
        int STATE = STATE_BEGIN;
        int compuate_flag = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')    //如果是空格，不做处理，跳出本层循环
                continue;
            switch(STATE)
            {

                case STATE_BEGIN:   //开始模式
                    if(s[i] >= '0' && s[i] <= '9')  //如果遇到数字，进入数字模式
                        STATE = NUMBER_STATE;
                    else
                        STATE = OPERATION_STATE;    //否则进入操作模式
                    i--;
                    break;
                case NUMBER_STATE:  //进入数字模式，用来得到字符串中的数字
                    if(s[i] >= '0' && s[i] <= '9')
                        number = number * 10 + s[i] - '0';
                    else //如果遇到非数字，说明后边是操作符或者括号，此时将之前得到的数字压栈，等待计算
                    {
                        number_stack.push(number);//将数字压栈
                        if(compuate_flag == 1)    //如果满足计算条件，则进行计算
                            compute(number_stack, operation_stack);
                        number = 0; //还原到默认值
                        i--;        //回到上一字符
                        STATE = OPERATION_STATE;  //切换状态
                    }
                    break;
                case OPERATION_STATE://操作符模式
                    if(s[i] == '+' || s[i] == '-') //遇到 '+'或'-'，则压入符号栈
                    {
                        operation_stack.push(s[i]);
                        compuate_flag = 1;         //有了操作符，说明如果下一步再遇到数字，就能计算
                    }
                    else if(s[i] == '(')           //如果遇到'(',现在不能计算，需要计算括号里边的子式
                    {
                        STATE = NUMBER_STATE;  //'('后边肯定是数字，故这里进入数字模式
                        compuate_flag = 0;
                    }
                    else if(s[i] >= '0' && s[i] <= '9') //如果操作符后边出现了数字，则进入数字模式
                    {
                        STATE = NUMBER_STATE;           //切换模式
                        i--;                            //切换到上个字符
                    }
                    else if(s[i] == ')')                //遇到')',可以直接计算
                        compute(number_stack, operation_stack);
                    break;
            }
        }
        if(number != 0)   //
        {
            number_stack.push(number);
            compute(number_stack, operation_stack);
        }
        if(number == 0 && number_stack.empty())        //
            return 0;

        return number_stack.top();                     //最终number_stack中会剩下一个数，就是最终的结果
    }
};
int main(void)
{
    string str = "1 + (2 + (4-7))";
    Solution sol;
    printf("the result is : %d\n", sol.calculate(str));
    return 0;
}
