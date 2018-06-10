/*
//315-������
*/
#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    //��������Եĸ��������ù鲢�����ȷֽ��С���Ⲣ��������Ը���
    //����������������֮��Ҫ�������򣬷�ֹ�����
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<pair<int, int> > vec;
        vector<int> count;
        //��nums[i]��Ϊ(nums[i],i)
        for(int i = 0; i < nums.size(); i++)
        {
            vec.push_back(make_pair(nums[i], i));
            count.push_back(0);
        }
        merge_sort(vec, count); //�鲢�����н�������Ը�����ͳ��
        return count;           //�����˵�ǰԪ�ص�����Ը���
    }
private:
    void merge_sort(vector<pair<int, int> >& vec, vector<int>& count)
    {
        if(vec.size() < 2)              //�������㹻Сʱ,ֱ�����
            return;
        int mid = vec.size() / 2;       //��ԭ������зֽ⣬���ֳ�����С���⣬�ֱ�����
        vector<pair<int, int> > sub_vec1;           //������1
        vector<pair<int, int> > sub_vec2;           //������2
        for(int i = 0; i < mid; i++)    //��ԭ��������ֳ�������
        {
            sub_vec1.push_back(vec[i]);
        }
        for(int j = mid; j < vec.size(); j++)
        {
            sub_vec2.push_back(vec[j]);
        }

        merge_sort(sub_vec1, count);       //���������
        merge_sort(sub_vec2, count);
        vec.clear();
        merge_sort_two_vec(sub_vec1, sub_vec2, vec, count);//��������������кϲ�
    }
    //�ϲ���������vector
    void merge_sort_two_vec(vector<pair<int, int> >& sub_vec1, vector<pair<int, int> >& sub_vec2,
                            vector<pair<int, int> >& vec, vector<int>& count)
    {
        int i = 0, j = 0;
        while(i < sub_vec1.size() && j < sub_vec2.size())
        {
            if(sub_vec1[i].first <= sub_vec2[j].first) //�����first����nums[i]
            {
                count[sub_vec1[i].second] += j; //��������Եĸ���
                vec.push_back(sub_vec1[i]);
                i++;
            }
            else
            {
                vec.push_back(sub_vec2[j]);
                j++;
            }
        }
        for(;i < sub_vec1.size(); i++)
        {
            count[sub_vec1[i].second] += j;
            vec.push_back(sub_vec1[i]);
        }
        for(;j < sub_vec2.size(); j++)
        {
            vec.push_back(sub_vec2[j]);
        }
    }
};
int main(void)
{
    Solution sol;
    vector<int> nums = {5,-7,9,1,3,5,-2,1};
    vector<int> count = sol.countSmaller(nums);
    for(int i = 0;i < count.size(); i++)
    {
        printf("[%d] ",count[i]);
    }
    return 0;
}

