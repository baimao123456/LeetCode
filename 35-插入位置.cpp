/*
//35-插入位置
*/
#include <stdio.h>
#include <vector>
using namespace std;
class Solution
{
public:
    //插入元素，使得nums保持有序，且返回插入的位置
    int searchInsert(vector<int> nums, int target)
    {
        int index = -1;      //最终要返回的下标，index == -1时，表示没有找到和target相同的值
        int begin = 0;
        int end = nums.size() - 1;
        while(index == -1)   //如果index == -1，说明没有找到位置插入，持续二分查找
        {
            int mid = (begin + end) / 2;  //计算中心位置
            if(target == nums[mid])       //如果找到了target，则返回target在nums中的位置
                return mid;

            else if(target < nums[mid])   //如果target小于中点值，则更新右端点
            {
                if(mid == 0 || target > nums[mid - 1])
                    index = mid;
                end = mid - 1;
            }
            else if(target > nums[mid])   //如果target大于中点值，则更新左端点
            {
                if(mid == nums.size() - 1 || target < nums[mid + 1])
                    index = mid + 1;
                begin = mid + 1;
            }
        }
        return index;
    }
};
int main(void)
{
    int test[] = {1, 3, 5, 6};
	std::vector<int> nums;
	Solution solve;
	for (int i = 0; i < 4; i++){
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 8; i++){
		printf("i = %d index = %d\n", i, solve.searchInsert(nums, i));
	}
    return 0;
}

