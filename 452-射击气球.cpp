/*
�������
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
//�ȽϺ�������������--������Ϊ1��������
bool cmp(pair<int, int> a,pair<int, int> b)
{
    return a.first < b.first;  //����Ϊ1��������������
}
class Solution
{
public:
    int findMinArrowShots(vector<pair<int, int> >& points)
    {
        if(points.size() == 0)
            return 0;
        sort(points.begin(), points.end(),cmp);  //����ڵ��������
        int shot_num = 1;                        //�������
        int shot_begin = points[0].first;        //��ʼ��������䣬��Ϊ��һ����������˵�
        int shot_end = points[0].second;
        for(int i = 1; i < points.size(); i++)
        {
            //����¸������������ʼ�����shot_end��
            //˵����������֮ǰ������û���غϵ����䣬�Ͳ���һ��ȫ�����
            if(points[i].first <= shot_end)
            {
                shot_begin = points[i].first;  //���µ�����������˵�������������˵�
                if(shot_end > points[i].second)
                    shot_end = points[i].second;
            }
            //���������˵��shot_end��Ҫ��
            //�µ�����϶�����ԭ�������������
            //��Ҫ���Ӽ�
            else
            {
                shot_num++;
                shot_begin = points[i].first;  //�����������Ϊ�µ���������Ҷ˵�
                shot_end = points[i].second;
            }
        }
        return shot_num;
    }
};
int main(void)
{
    vector<pair<int, int> > points;
    points.push_back(make_pair(10,16));
    points.push_back(make_pair(2,8));
    points.push_back(make_pair(1,6));
    points.push_back(make_pair(7,12));

    Solution sol;
    printf("%d\n", sol.findMinArrowShots(points));
    return 0;
}
