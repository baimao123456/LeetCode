/*
295-Ѱ����λ��
*/
#include <stdio.h>
#include <queue>
using namespace std;

class MedianFinder
{
public:
    MedianFinder() {}
    //�����ݽṹ�����һ��Ԫ��
    void addNum(int num)
    {
        if(big_heap.empty())    //���big_heapΪ�գ���num���뵽big_heap
        {
            big_heap.push(num);
            return;
        }
        //���big_heap����small_heap,�ŵ����ʵ�λ��
        if(big_heap.size() == small_heap.size())
        {
            if(num < big_heap.top())
                big_heap.push(num);
            else
                small_heap.push(num);
        }
        //���big_heap����small_heap,�򽫽ϴ�����Ž�small_heap��
        else if(big_heap.size() > small_heap.size())
        {
            if(num > big_heap.top())
                small_heap.push(num);
            else
            {
                small_heap.push(big_heap.top());
                big_heap.pop();
                big_heap.push(num);
            }
        }
        //���big_heapС��small_heap,�򽫽�С�����Ž�big_heap��
        else if(big_heap.size() < small_heap.size())
        {
            if(num < small_heap.top())
                big_heap.push(num);
            else
            {
                big_heap.push(small_heap.top());
                small_heap.pop();
                small_heap.push(num);
            }
        }
    }
    //������λ��
    double findMedian()
    {
        if(big_heap.size() == small_heap.size())
            return (big_heap.top() + small_heap.top()) / 2;
        else if(big_heap.size() > small_heap.size())
            return big_heap.top();
        return small_heap.top();
    }
private:
    priority_queue<double, vector<double>, greater<double> > small_heap;//��С��
    priority_queue<double, vector<double>, less<double> > big_heap; //����
};
class MedianFinder2
{
public:
    MedianFinder2() {}
    //�����ݽṹ�����һ��Ԫ��
    //ÿ�ζ���num���뵽big_heap��Ȼ��big_heap�е�������ŵ�small_heap��
    //���small��Ԫ�ظ�������big����small����Сֵ�ŵ�big�У�
    //��֤small��big�ĸ�����С�ڵ���1����big_heap�����ֵ����С��small_heap����Сֵ
    void addNum(int num)
    {
        big_heap.push(num);
        small_heap.push(big_heap.top());
        big_heap.pop();
        if(small_heap.size() > big_heap.size())
        {
            big_heap.push(small_heap.top());
            small_heap.pop();
        }
    }
    //������λ��
    double findMedian()
    {
        if(big_heap.size() == small_heap.size())
            return (big_heap.top() + small_heap.top()) / 2;
        else if(big_heap.size() > small_heap.size())
            return big_heap.top();
        return small_heap.top();
    }
private:
    priority_queue<double, vector<double>, greater<double> > small_heap;//��С��
    priority_queue<double, vector<double>, less<double> > big_heap; //����
};
int main(void)
{
    MedianFinder sol;
    MedianFinder2 sol2;
    int test[] = {6, 10, 1, 7, 99, 4, 33};
    for(int i = 0; i < 7; i++)
    {
        sol.addNum(test[i]);
        printf("the median of test1 is %2f \n", sol.findMedian());
    }
    for(int i = 0; i < 7; i++)
    {
        sol2.addNum(test[i]);
        printf("the median of test2 is %2f \n", sol2.findMedian());
    }
    return 0;
}

