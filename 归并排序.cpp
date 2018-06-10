#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge_sort(vector<int>& vec)
    {
        if(vec.size() < 2)              //�������㹻Сʱ,ֱ�����
            return;
        int mid = vec.size() / 2;       //��ԭ������зֽ⣬���ֳ�����С���⣬�ֱ�����
        vector<int> sub_vec1;           //������1
        vector<int> sub_vec2;           //������2
        for(int i = 0; i < mid; i++)    //��ԭ��������ֳ�������
        {
            sub_vec1.push_back(vec[i]);
        }
        for(int j = mid; j < vec.size(); j++)
        {
            sub_vec2.push_back(vec[j]);
        }
        merge_sort(sub_vec1);       //���������
        merge_sort(sub_vec2);
        vec.clear();
        merge_sort_two_vec(sub_vec1, sub_vec2, vec);//��������������кϲ�
    }
    //�ϲ���������vector
    void merge_sort_two_vec(vector<int>& vec1, vector<int>& vec2, vector<int>& result)
    {
        int i = 0, j = 0;
        while(i < vec1.size() && j < vec2.size())
        {
            if(vec1[i] <= vec2[j])
            {
                result.push_back(vec1[i]);
                i++;
            }
            else
            {
                result.push_back(vec2[j]);
                j++;
            }
        }
        for(;i < vec1.size(); i++)
        {
            result.push_back(vec1[i]);
        }
        for(;j < vec2.size(); j++)
        {
            result.push_back(vec2[j]);
        }
    }
};
int main(void)
{
    Solution sol;
    vector<int> nums1 = {11};
    vector<int> nums2 = {2,4,6,8,10,11};
    vector<int> nums3 = {1,3,9,4,0,2,2,3,4,9,8};
    vector<int> result;
    sol.merge_sort(nums3);
    for(int i = 0;i < nums3.size(); i++)
    {
        printf("[%d] ",nums3[i]);
    }
    return 0;
}
