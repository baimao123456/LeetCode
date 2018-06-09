/*
合法的出栈序列
*/
#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;
//判断order是否是合法出栈序列
bool check_is_valid_order(queue<int> &order)
{
    stack<int> s;          //辅助栈s
    int n = order.size();  //n为序列长度，将1-n按顺序入栈
    for(int i = 1; i <= n; ++i)
    {
        s.push(i);     //s入栈
        //只要s不空，且s的栈顶元素和order的队首元素相同，则同时弹出
        while(!s.empty() && (s.top() == order.front()))
        {
            s.pop();
            order.pop();
        }
    }
    if(!s.empty())     //如果最终栈不空，说明序列不合法
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
        while(train)                   //如果train为0，则不符合条件，不执行
        {
            queue<int> order;
            order.push(train);
            for(int i = 1; i < n; ++i) //这里只输入了4次，之前train已经输入过一次
            {
                scanf("%d", &train);
                order.push(train);
            }
            if(check_is_valid_order(order)) //检查是否是合法序列
                printf("YES\n");
            else
                printf("NO\n");
            scanf("%d", &train);
        }
        printf("\n");
        scanf("%d", &n);                   //重新获得n的值
    }
    return 0;
}
