/*
�Ϸ��ĳ�ջ����
*/
#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;
//�ж�order�Ƿ��ǺϷ���ջ����
bool check_is_valid_order(queue<int> &order)
{
    stack<int> s;          //����ջs
    int n = order.size();  //nΪ���г��ȣ���1-n��˳����ջ
    for(int i = 1; i <= n; ++i)
    {
        s.push(i);     //s��ջ
        //ֻҪs���գ���s��ջ��Ԫ�غ�order�Ķ���Ԫ����ͬ����ͬʱ����
        while(!s.empty() && (s.top() == order.front()))
        {
            s.pop();
            order.pop();
        }
    }
    if(!s.empty())     //�������ջ���գ�˵�����в��Ϸ�
        return false;
    else
        return true;
}
int main(void)
{
    int n;
    int train;
    scanf("%d", &n);
    while(n)
    {
        scanf("%d", &train);
        while(train)                   //���trainΪ0���򲻷�����������ִ��
        {
            queue<int> order;
            order.push(train);
            for(int i = 1; i < n; ++i) //����ֻ������4�Σ�֮ǰtrain�Ѿ������һ��
            {
                scanf("%d", &train);
                order.push(train);
            }
            if(check_is_valid_order(order)) //����Ƿ��ǺϷ�����
                printf("YES\n");
            else
                printf("NO\n");
            scanf("%d", &train);
        }
        printf("\n");
        scanf("%d", &n);                   //���»��n��ֵ
    }
    return 0;
}
