/*
//33-��ת�������
*/
#include <stdio.h>
#include <vector>
using namespace std;
class Solution
{
public:
    //��ת�������,����target��nums�е�λ��
    int search(vector<int>& nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end)
        {
            int mid = (begin + end) / 2;
            if(target == nums[mid])
                return mid;

            if(target < nums[mid])
            {
                if(nums[begin] < nums[mid])  //��������[begin : mid -1]
                {
                    if(target >= nums[begin])
                        end = mid - 1;
                    else
                        begin = mid + 1;
                }
                else if(nums[begin] > nums[mid])
                {
                    end = mid - 1;
                }
                else if(nums[begin] == nums[mid])
                {
                    begin = mid + 1;
                }
            }
            else if(target > nums[mid])
            {
                if(nums[begin] < nums[mid])  //��������[begin : mid -1]
                {
                    begin = mid + 1;
                }
                else if(nums[begin] > nums[mid])
                {
                    if(target >= nums[begin])
                        end = mid - 1;
                    else
                        begin = mid + 1;
                }
                else if(nums[begin] == nums[mid])
                {
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }

};
int main(void)
{
    int test[] = {9, 12, 15, 20, 1, 3, 6, 7};
	std::vector<int> nums;
	Solution solve;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 22; i++){
		printf("%d : %d\n", i, solve.search(nums, i));
	}
    return 0;
}



