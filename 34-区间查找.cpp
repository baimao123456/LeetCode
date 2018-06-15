/*
//34-�������
*/
#include <stdio.h>
#include <vector>
using namespace std;
class Solution
{
public:
    //����Ԫ�أ�ʹ��nums���������ҷ��ز����λ��
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> result;
        result.push_back(left_bound(nums, target));
        result.push_back(right_bound(nums, target));
        return result;
    }
private:
    //Ѱ����˵�
    int left_bound(vector<int>& nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end)
        {
            int mid = (begin + end) / 2;
            if(target == nums[mid])
            {
                if(mid == 0 || target > nums[mid - 1])
                    return mid;
                end = mid - 1;
            }
            else if(target > nums[mid]) //���²�������
                begin = mid + 1;
            else if(target < nums[mid])
                end = mid - 1;
        }
        return -1;    //���û���ҵ�����-1
    }
    //Ѱ���Ҷ˵�
    int right_bound(vector<int>& nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end)
        {
            int mid = (begin + end) / 2;
            if(target == nums[mid])
            {
                if(mid == nums.size() - 1 || target < nums[mid + 1])
                    return mid;
                begin = mid + 1;
            }
            else if(target > nums[mid])  //���²�������
                begin = mid + 1;
            else if(target < nums[mid])
                end = mid - 1;
        }
        return -1; //���û���ҵ�����-1
    }
};
int main(void)
{
    int test[] = {5, 7, 7, 8, 8, 8, 8, 10};
	std::vector<int> nums;
	Solution solve;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 12; i++){
		std::vector<int> result = solve.searchRange(nums, i);
		printf("%d : [%d, %d]\n",i , result[0], result[1]);
	}
    return 0;
}


