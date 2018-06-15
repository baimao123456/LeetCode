/*
473-�����ڳ�������
*/
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool cmp(int &a, int &b)
{
    return a > b;
}
class Solution1
{
public:
    //�ж��Ƿ�������������
    bool makesquare(vector<int> &nums)
    {
        if(nums.size() < 4)   //����������4����
            return false;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if(sum % 4 != 0)     //���sum��������4�����ܹ���4����
            return false;
        sort(nums.begin(), nums.end());
        int bucket[4] = {0};  //����4��Ͱ����4���߳�
        return generate(0, nums, sum / 4, bucket);
    }
private:
    //iΪnumsԪ�أ�nums��������ĳ��ȣ�targetΪ���������εı߳���bucket��������εı߳�
    bool generate(int i, vector<int> &nums, int target, int bucket[])
    {
        if(i >= nums.size())               //�������ȫ�����꣬�ж�4�����Ƿ���ͬ
            return bucket[0] == target && bucket[1] == target
                && bucket[2] == target && bucket[3] == target;
        for(int j = 0;j < 4; j++)           //��4��Ͱ�зֱ���
        {
            if(bucket[j] + nums[i] > target) //���������nums[i]�Ž�bucket[j]�������߳������������ı�
                continue;
            bucket[j] += nums[i];            //����jͰ��
            if(generate(i + 1, nums, target, bucket)) //����һ�������Ž�Ͱ��
            {
                return true;
            }
            bucket[j] -= nums[i];            //��jͰ��ȡ�������ݹ���
        }
        return false;
    }
};
class Solution2
{
public:
    //�ж��Ƿ�������������--����λ����
    bool makesquare(vector<int> &nums)
    {
        if(nums.size() < 4)     //����������4����
            return false;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if(sum % 4 != 0)         //���sum��������4�����ܹ���4����
            return false;
        int target = sum / 4;
        vector<int> ok_subset;   //��������������1���ߵļ���
        vector<int> ok_half;     //��������������2���ߵļ���
        int all = 1 << nums.size();   //all���ֶ�Ӧ��λ�����1����ʾ��ѡ��
        for(int i = 0; i < all; i++)
        {
            int sum = 0;
            for(int j = 0; j < nums.size();j++)
            {
                if(i &(1 << j))  //�����j������ѡ�У���������
                    sum += nums[j];
            }
            if(sum == target)    //���sum���ڱ߳����򽫸ü���push��ok_subset
                ok_subset.push_back(i);
        }
        for(int i = 0; i < ok_subset.size(); i++)  //�������룬���Ϊ0����ʾ���������϶���
        {
            for(int j = i + 1; j < ok_subset.size(); j++)
            {
                if((ok_subset[i] & ok_subset[j]) == 0)
                    ok_half.push_back(ok_subset[i] | ok_subset[j]);//�洢�������ϵĲ���
            }
        }
        for(int i = 0; i < ok_half.size(); i++)   //�ٴ��ж����������Ƿ������
        {
            for(int j = i + 1; j < ok_half.size(); j++)
            {
                if((ok_half[i] & ok_half[j]) == 0)//�������Ϊ0��˵���������������������򲻳���
                    return true;
            }
        }
    }
};
class Solution3
{
public:
    //����˫����У�������Ԫ�شӴ�С��
    //ÿ�δ�ǰ���ҵ�����Ԫ�أ�ʹ���ܹ���һ���ߣ�Ȼ�󽫷���������Ԫ��pop��
    //���������Ϊ�գ�˵�����Թ���һ��������
    bool makesquare(vector<int> &nums)
    {
        if(nums.size() < 4)
            return false;

        sort(nums.begin(), nums.end(), cmp);   //��Ԫ�شӴ�С����
        deque<int> Q;
        int sum = 0;                //�������ܺ�
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            Q.push_back(nums[i]);
        }
        if(sum % 4 != 0)            //���sum����4�ı��������ܹ���������
            return false;
        int target = sum / 4;       //�����εı߳�
        while(!Q.empty())
        {
            int value = Q.front();
            Q.pop_front();
            while(value < target)   //����߲���target�����С��һ���ó�һ�ˣ�ֱ������
            {
                value += Q.back();
                Q.pop_back();
            }
        }
        return Q.empty();
    }
};
int main(void)
{
    vector<int> nums = {1,1,2,4,3,2,3};
    Solution1 sol1;
    printf("%d", sol1.makesquare(nums));
    Solution2 sol2;
    printf("%d", sol2.makesquare(nums));
    Solution3 sol3;
    printf("%d", sol3.makesquare(nums));
    return 0;
}
