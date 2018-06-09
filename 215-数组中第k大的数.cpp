/*
215-数组中第k大的数
*/
#include <stdio.h>
#include <queue>
using namespace std;
//STL优先级队列测试（二叉堆也叫最大最小先出的二叉树）
void Test()
{
    priority_queue<int> big_heap;  //默认构造最大堆
    priority_queue<int, vector<int>, less<int> > big_heap2;
    priority_queue<int, vector<int>, greater<int> > small_heap; //最小堆

    if(big_heap.empty())
        printf("big_heap is empty\n");
    int test[] = {6, 10, 1, 7, 99, 4, 33};
    for(int i = 0; i < 7; i++)
        big_heap.push(test[i]);
    printf("the top of big_heap is %d \n", big_heap.top());
    big_heap.pop();
    printf("the top of big_heap is %d \n", big_heap.top());
    printf("the size of big_heap is %d \n", big_heap.size());
}
class Solution
{
public:
    //构建一个size为k的最小堆，堆顶就是第k大的数
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int> > Q;
        for(int i = 0; i < nums.size(); i++)
        {
            if(Q.size() < k)            //如果堆的元素个数小于k，直接push到堆中
                Q.push(nums[i]);
            else if(nums[i] > Q.top())  //如果堆顶元素比新元素小
            {
                Q.pop();                //弹出较小的元素
                Q.push(nums[i]);        //将新的较大的元素push进堆
            }
        }
        return Q.top();                 //堆顶元素就是第k大的数
    }
};
int main(void)
{
    vector<int> nums = {1,3,9,4,0,2,2,3,4,9,8};
    Solution sol;
    printf("the kth number is: %d\n",sol.findKthLargest(nums, 4));
    return 0;
}
