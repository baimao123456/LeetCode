/*
���ż��ͷ���
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//�ȽϺ�������������--������Ϊ1��������
bool cmp(const pair<int, int>& a,const pair<int, int>& b)
{
    return a.first > b.first;  //����Ϊ1�����ǽ�������
}
//LΪ��㵽�յ�ľ���
//PΪ����ʣ�������
//pair<����վ���յ�ľ���,����վ������>
int get_minimum_stop(int L, int P,vector<pair<int, int> >& stop)
{
    priority_queue<int> Q;   //�洢����������
    int result = 0;
    stop.push_back(make_pair(0,0)); //���յ���Ϊһ��ͣ����
    sort(stop.begin(), stop.end(), cmp);
    for(int i = 0; i < stop.size(); i++)
    {
        int dis = L - stop[i].first;//��ǰҪ�ߵľ���
        //����Ѿ�·������վ���ҵ�ǰ���������ܼ�������һ����
        //����м��ͣ�������Ϊ·�����������ļ���վ
        while(!Q.empty() && P < dis)
        {
            P += Q.top();    //�������ͣ�̰�ĵ����֣�
            Q.pop();
            result++;        //��¼���ʹ���
        }
        if(P < dis)          //���ÿ������վ�������ˣ��ͻ��ǲ��������ܵ����յ�
            return -1;
        P = P - dis;         //����ʣ�������
        L = stop[i].first;   //����LΪ��ǰͣ��վ���յ�ľ���
        Q.push(stop[i].second); //����ǰͣ��վ��������������
    }
    return result;
}
int main(void)
{
    vector<pair<int, int> > stop;
    int N,L,P;
    int distance;
    int fuel;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &distance, &fuel);
        stop.push_back(make_pair(distance, fuel));
    }
    scanf("%d %d", &L, &P);
    printf("%d\n", get_minimum_stop(L,P,stop));
    return 0;
}
