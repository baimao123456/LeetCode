
/*
 225-ʹ��ջʵ�ֶ���
*/
#include <stdio.h>
#include <stack>
using namespace std;
class MyQueue1
{
//����һ������ջ��һ����ʱջ��ÿ��push��Ҫ������ʱջ����˳��
//ÿ��push��ƽ�����Ӷ�ΪO(n),���帴�Ӷ�ΪO(n^2)
public:
    MyQueue1()
    {

    }
    //ѹ���β
    void push(int x)
    {
        stack<int> temp_stack;     //��ʱջ���洢����
        while(!data_stack.empty()) //������ջ�е�Ԫ��push����ʱջ��ȥ
        {
            temp_stack.push(data_stack.top());
            data_stack.pop();
        }
        temp_stack.push(x);        //����Ԫ��push����ʱջ��
        while(!temp_stack.empty()) //�����º����ʱ����ջ�е�Ԫ�طŵ�ԭ��������ջ��
        {
            data_stack.push(temp_stack.top());
            temp_stack.pop();
        }
    }
    //��������Ԫ��
    int pop()
    {
        int x = data_stack.top();  //���ջ��Ԫ�أ����Ƕ���Ԫ��
        data_stack.pop();          //����ջ��Ԫ�أ�
        return x;
    }
    //��ö���Ԫ��
    int peek()
    {
        return data_stack.top();
    }
    //�ж϶����Ƿ�Ϊ��
    bool empty()
    {
        return data_stack.empty();
    }
private:
    stack<int> data_stack;
};
class MyQueue2
{
//��������ջ��һ������pushһ������pop
//ÿ��push��ƽ�����Ӷ�ΪO(1),���帴�Ӷ�ΪO(n)
public:
    MyQueue2()
    {

    }
    //push����β
    void push(int x)
    {
        input_stack.push(x);
    }
    //��������Ԫ��
    int pop()
    {
        adjust();    //���е���
        int x = output_stack.top(); //����ջ��Ԫ�أ����Ԫ�ؾ��Ƕ���Ԫ��
        output_stack.pop();
        return x;
    }
    //��ö���Ԫ��
    int peek()
    {
        adjust();    //���е���
        return output_stack.top();
    }
    //�ж϶����Ƿ�Ϊ�գ�ֻ������ջͬʱΪ�գ���˵������Ϊ��
    bool empty()
    {
        return (input_stack.empty() && output_stack.empty());
    }
private:
    //����output_stack�Ƿ�Ϊ�ս��е���
    void adjust()
    {
        if(!output_stack.empty())    //���output_stack���գ����õ���
            return;
        while(!input_stack.empty())
        {
            output_stack.push(input_stack.top());
            input_stack.pop();
        }
    }
    stack<int> input_stack;
    stack<int> output_stack;
};
int main(void)
{
    MyQueue1 q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    printf("the top is %d\n",q1.peek());
    q1.pop();
    printf("the top is %d\n",q1.peek());

    MyQueue1 q2;
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(4);
    printf("the top is %d\n",q2.peek());
    q2.pop();
    q2.push(5);
    q2.push(7);
    printf("the top is %d\n",q2.peek());
    q2.pop();
    printf("the top is %d\n",q2.peek());
    q2.pop();
    printf("the top is %d\n",q2.peek());
    q2.pop();
    printf("the top is %d\n",q2.peek());
    q2.pop();
    printf("the top is %d\n",q2.peek());
    q2.pop();

    return 0;
}
