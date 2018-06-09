/*
155-����min��ջ
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
    //ѹ��ջ��
    void push(int x)
    {
        _data.push(x);       //������ѹ������ջ
        if(_min.empty())     //�����СֵջΪ�գ�ֱ�ӽ�����ѹ��ջ
            _min.push(x);
        else
        {
            if(x > _min.top()) //�Ƚϵ�ǰ����x����Сֵ�Ĵ�С������С��ѹ��_min��
                x = _min.top();
            _min.push(x);
        }
    }
    //����ջ��Ԫ��
    int pop()
    {
        _data.pop();  //����ջ����Сջͬʱ����
        _min.pop();
    }
    //���ջ��Ԫ��
    int top()
    {
        return _data.top();
    }
    //����ջ����СԪ��
    int getMin()
    {
        return _min.top();
    }
private:
    stack<int> _data;   //����ջ
    stack<int> _min;   //����״̬����СԪ��ջ
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


