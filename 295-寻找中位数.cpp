/*
295-寻找中位数
*/
#include <stdio.h>
#include <queue>
using namespace std;

class MedianFinder
{
public:
    MedianFinder() {}
    //向数据结构中添加一个元素
    void addNum(int num)
    {
        if(big_heap.empty())    //如果big_heap为空，将num加入到big_heap
        {
            big_heap.push(num);
            return;
        }
        //如果big_heap等于small_heap,放到合适的位置
        if(big_heap.size() == small_heap.size())
        {
            if(num < big_heap.top())
                big_heap.push(num);
            else
                small_heap.push(num);
        }
        //如果big_heap大于small_heap,则将较大的数放进small_heap中
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
        //如果big_heap小于small_heap,则将较小的数放进big_heap中
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
    //返回中位数
    double findMedian()
    {
        if(big_heap.size() == small_heap.size())
            return (big_heap.top() + small_heap.top()) / 2;
        else if(big_heap.size() > small_heap.size())
            return big_heap.top();
        return small_heap.top();
    }
private:
    priority_queue<double, vector<double>, greater<double> > small_heap;//最小堆
    priority_queue<double, vector<double>, less<double> > big_heap; //最大堆
};
class MedianFinder2
{
public:
    MedianFinder2() {}
    //向数据结构中添加一个元素
    //每次都把num加入到big_heap，然后将big_heap中的最大数放到small_heap中
    //如果small的元素个数多于big，则将small的最小值放到big中，
    //保证small和big的个数差小于等于1，且big_heap的最大值总是小于small_heap的最小值
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
    //返回中位数
    double findMedian()
    {
        if(big_heap.size() == small_heap.size())
            return (big_heap.top() + small_heap.top()) / 2;
        else if(big_heap.size() > small_heap.size())
            return big_heap.top();
        return small_heap.top();
    }
private:
    priority_queue<double, vector<double>, greater<double> > small_heap;//最小堆
    priority_queue<double, vector<double>, less<double> > big_heap; //最大堆
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

