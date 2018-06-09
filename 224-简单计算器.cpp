/*
�򵥼�����
*/
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;
void compute(stack<int> &number_stack, stack<char> &operation_stack)
{
    if(number_stack.size() < 2) // ��������Ϊ2�������޷�����
        return;
    int num2 = number_stack.top();  //ȡ�������������м���
    number_stack.pop();
    int num1 = number_stack.top();
    number_stack.pop();

    if(operation_stack.top() == '+')      //�ӷ���ջ��ȡ���Ž��м��㣬��������ֵ����ѹ������ջ
        number_stack.push(num1 + num2);
    else if(operation_stack.top() == '-')
        number_stack.push(num1 - num2);

    operation_stack.pop();  //��������֮����Ҫ����
}
class Solution
{
public:
    int calculate(string s)
    {
        static const int STATE_BEGIN = 0;
        static const int NUMBER_STATE = 1;
        static const int OPERATION_STATE = 2;

        stack<int> number_stack;           //����ջ
        stack<char> operation_stack;       //������ջ
        int number = 0;
        int STATE = STATE_BEGIN;
        int compuate_flag = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')    //����ǿո񣬲���������������ѭ��
                continue;
            switch(STATE)
            {

                case STATE_BEGIN:   //��ʼģʽ
                    if(s[i] >= '0' && s[i] <= '9')  //����������֣���������ģʽ
                        STATE = NUMBER_STATE;
                    else
                        STATE = OPERATION_STATE;    //����������ģʽ
                    i--;
                    break;
                case NUMBER_STATE:  //��������ģʽ�������õ��ַ����е�����
                    if(s[i] >= '0' && s[i] <= '9')
                        number = number * 10 + s[i] - '0';
                    else //������������֣�˵������ǲ������������ţ���ʱ��֮ǰ�õ�������ѹջ���ȴ�����
                    {
                        number_stack.push(number);//������ѹջ
                        if(compuate_flag == 1)    //��������������������м���
                            compute(number_stack, operation_stack);
                        number = 0; //��ԭ��Ĭ��ֵ
                        i--;        //�ص���һ�ַ�
                        STATE = OPERATION_STATE;  //�л�״̬
                    }
                    break;
                case OPERATION_STATE://������ģʽ
                    if(s[i] == '+' || s[i] == '-') //���� '+'��'-'����ѹ�����ջ
                    {
                        operation_stack.push(s[i]);
                        compuate_flag = 1;         //���˲�������˵�������һ�����������֣����ܼ���
                    }
                    else if(s[i] == '(')           //�������'(',���ڲ��ܼ��㣬��Ҫ����������ߵ���ʽ
                    {
                        STATE = NUMBER_STATE;  //'('��߿϶������֣��������������ģʽ
                        compuate_flag = 0;
                    }
                    else if(s[i] >= '0' && s[i] <= '9') //�����������߳��������֣����������ģʽ
                    {
                        STATE = NUMBER_STATE;           //�л�ģʽ
                        i--;                            //�л����ϸ��ַ�
                    }
                    else if(s[i] == ')')                //����')',����ֱ�Ӽ���
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

        return number_stack.top();                     //����number_stack�л�ʣ��һ�������������յĽ��
    }
};
int main(void)
{
    string str = "1 + (2 + (4-7))";
    Solution sol;
    printf("the result is : %d\n", sol.calculate(str));
    return 0;
}
