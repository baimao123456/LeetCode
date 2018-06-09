
/*
 225-使用栈实现队列
*/
#include <stdio.h>
#include <stack>
using namespace std;
class MyQueue1
{
//利用一个数据栈和一个临时栈，每次push需要利用临时栈调整顺序
//每次push的平均复杂度为O(n),整体复杂度为O(n^2)
public:
    MyQueue1()
    {

    }
    //压入队尾
    void push(int x)
    {
        stack<int> temp_stack;     //临时栈，存储数据
        while(!data_stack.empty()) //将数据栈中的元素push到临时栈中去
        {
            temp_stack.push(data_stack.top());
            data_stack.pop();
        }
        temp_stack.push(x);        //将新元素push到临时栈内
        while(!temp_stack.empty()) //将更新后的临时数据栈中的元素放到原来的数据栈中
        {
            data_stack.push(temp_stack.top());
            temp_stack.pop();
        }
    }
    //弹出队首元素
    int pop()
    {
        int x = data_stack.top();  //获得栈顶元素，就是队首元素
        data_stack.pop();          //弹出栈顶元素，
        return x;
    }
    //获得队首元素
    int peek()
    {
        return data_stack.top();
    }
    //判断队列是否为空
    bool empty()
    {
        return data_stack.empty();
    }
private:
    stack<int> data_stack;
};
class MyQueue2
{
//利用两个栈，一个用来push一个用来pop
//每次push的平均复杂度为O(1),整体复杂度为O(n)
public:
    MyQueue2()
    {

    }
    //push到队尾
    void push(int x)
    {
        input_stack.push(x);
    }
    //弹出队首元素
    int pop()
    {
        adjust();    //进行调整
        int x = output_stack.top(); //返回栈顶元素，这个元素就是队首元素
        output_stack.pop();
        return x;
    }
    //获得队首元素
    int peek()
    {
        adjust();    //进行调整
        return output_stack.top();
    }
    //判断队列是否为空，只有两个栈同时为空，才说明队列为空
    bool empty()
    {
        return (input_stack.empty() && output_stack.empty());
    }
private:
    //根据output_stack是否为空进行调整
    void adjust()
    {
        if(!output_stack.empty())    //如果output_stack不空，则不用调整
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
