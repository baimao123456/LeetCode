/*
215-�����е�k�����
*/
#include <stdio.h>
#include <queue>
using namespace std;
//STL���ȼ����в��ԣ������Ҳ�������С�ȳ��Ķ�������
void Test()
{
    priority_queue<int> big_heap;  //Ĭ�Ϲ�������
    priority_queue<int, vector<int>, less<int> > big_heap2;
    priority_queue<int, vector<int>, greater<int> > small_heap; //��С��

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
    //����һ��sizeΪk����С�ѣ��Ѷ����ǵ�k�����
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int> > Q;
        for(int i = 0; i < nums.size(); i++)
        {
            if(Q.size() < k)            //����ѵ�Ԫ�ظ���С��k��ֱ��push������
                Q.push(nums[i]);
            else if(nums[i] > Q.top())  //����Ѷ�Ԫ�ر���Ԫ��С
            {
                Q.pop();                //������С��Ԫ��
                Q.push(nums[i]);        //���µĽϴ��Ԫ��push����
            }
        }
        return Q.top();                 //�Ѷ�Ԫ�ؾ��ǵ�k�����
    }
};
int main(void)
{
    vector<int> nums = {1,3,9,4,0,2,2,3,4,9,8};
    Solution sol;
    printf("the kth number is: %d\n",sol.findKthLargest(nums, 4));
    return 0;
}
