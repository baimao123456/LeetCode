/*
 225-ʹ�ö���ʵ��ջ
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
    //ѹ��ջ��
    void push(int x)
    {
        queue<int> temp_queue;     //������ʱqueue���ı�Ԫ�ص�˳��
        while(!data_queue.empty()) //�Ƚ�ԭ��������Ԫ��push��temp_queue��
        {
            temp_queue.push(data_queue.front());
            data_queue.pop();
        }
        data_queue.push(x);        //��Ԫ��push��dataqueue��
        while(!temp_queue.empty()) //��ԭ��������Ԫ�����µ��뵽data_queue��
        {
            data_queue.push(temp_queue.front());
            temp_queue.pop();
        }
    }
    //����ջ��Ԫ��
    int pop()
    {
        int x = data_queue.front();
        data_queue.pop();
        return x;
    }
    //���ջ��Ԫ��
    int top()
    {
        return data_queue.front();
    }
    //�ж��Ƿ�Ϊ��
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
