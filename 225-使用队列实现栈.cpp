/*
 225-使用队列实现栈
*/
#include <stdio.h>
#include <queue>
using namespace std;
class MyStack
{
public:
    MyStack()
    {

    }
    //压入栈内
    void push(int x)
    {
        queue<int> temp_queue;     //定义临时queue来改变元素的顺序
        while(!data_queue.empty()) //先将原来的数据元素push进temp_queue中
        {
            temp_queue.push(data_queue.front());
            data_queue.pop();
        }
        data_queue.push(x);        //新元素push进dataqueue中
        while(!temp_queue.empty()) //将原来的数据元素重新导入到data_queue中
        {
            data_queue.push(temp_queue.front());
            temp_queue.pop();
        }
    }
    //弹出栈顶元素
    int pop()
    {
        int x = data_queue.front();
        data_queue.pop();
        return x;
    }
    //获得栈顶元素
    int top()
    {
        return data_queue.front();
    }
    //判断是否为空
    bool empty()
    {
        return data_queue.empty();
    }
private:
    queue<int> data_queue;
};
int main(void)
{
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    printf("the top is %d\n",s.top());
    s.pop();
    printf("the top is %d\n",s.top());
    s.push(5);
    printf("the top is %d\n",s.top());

    return 0;
}
