/*
//35-����λ��
*/
#include <stdio.h>
#include <vector>
using namespace std;
class Solution
{
public:
    //����Ԫ�أ�ʹ��nums���������ҷ��ز����λ��
    int searchInsert(vector<int> nums, int target)
    {
        int index = -1;      //����Ҫ���ص��±꣬index == -1ʱ����ʾû���ҵ���target��ͬ��ֵ
        int begin = 0;
        int end = nums.size() - 1;
        while(index == -1)   //���index == -1��˵��û���ҵ�λ�ò��룬�������ֲ���
        {
            int mid = (begin + end) / 2;  //��������λ��
            if(target == nums[mid])       //����ҵ���target���򷵻�target��nums�е�λ��
                return mid;

            else if(target < nums[mid])   //���targetС���е�ֵ��������Ҷ˵�
            {
                if(mid == 0 || target > nums[mid - 1])
                    index = mid;
                end = mid - 1;
            }
            else if(target > nums[mid])   //���target�����е�ֵ���������˵�
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

