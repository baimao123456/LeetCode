/*
155-包含min的栈
*/
#include <stdio.h>
#include <stack>
using namespace std;
class MinStack
{
public:
    MinStack()
    {

    }
    //压入栈内
    void push(int x)
    {
        _data.push(x);       //将数据压入数据栈
        if(_min.empty())     //如果最小值栈为空，直接将数据压入栈
            _min.push(x);
        else
        {
            if(x > _min.top()) //比较当前数据x和最小值的大小，将最小的压入_min中
                x = _min.top();
            _min.push(x);
        }
    }
    //弹出栈顶元素
    int pop()
    {
        _data.pop();  //数据栈和最小栈同时弹出
        _min.pop();
    }
    //获得栈顶元素
    int top()
    {
        return _data.top();
    }
    //返回栈内最小元素
    int getMin()
    {
        return _min.top();
    }
private:
    stack<int> _data;   //数据栈
    stack<int> _min;   //各个状态的最小元素栈
};
int main(void)
{
    MinStack s;
    s.push(1);
    s.push(-2);
    s.push(-3);
    s.push(4);
    printf("the top is %d\n",s.top());
    s.pop();
    printf("the top is %d\n",s.top());
    s.push(5);
    printf("the min is %d\n",s.getMin());

    return 0;
}


