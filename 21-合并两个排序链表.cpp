//21-合并两个有序链表
#include <iostream>
#include <set>
using namespace std;
//链表节点
struct ListNode
{
    int value;   //节点值
    ListNode* next; //下一个节点
    ListNode(int v) : value(v), next(NULL) {}  //构造函数
};
//解决方案
class Solution
{
    //合并两个有序链表
public:
    ListNode* mergeTwoList(ListNode *l1, ListNode *l2)
    {
        ListNode temp_head(0);       //辅助节点
        ListNode *pre = &temp_head;  //辅助指针
        while(l1 && l2)              //l1 and l2 is not empty
        {
            if(l1->value < l2->value)
            {
                pre->next = l1;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;      //pre指向新链表的最后的节点
        }
        if(l1)                    //将l1剩余的节点连接到pre
            pre->next = l1;
        if(l2)                    //将l2剩余的节点连接到pre
            pre->next = l2;
        return temp_head.next;
    }
};
//打印链表节点值
void show(ListNode* head)
{
    while(head)
    {
        cout << head->value << ',';
        head = head->next;
    }
    cout << endl;
}
int main(void)
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(7);
    ListNode e(9);

    ListNode f(1);
    ListNode g(3);
    ListNode h(7);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    f.next = &g;
    g.next = &h;

    ListNode* headA = &a;
    ListNode* headB = &f;

    Solution sol;
    cout << "list A is" << endl;
    show(headA);
    cout << "list B is" << endl;
    show(headB);
    cout << "after merge : " << endl;
    ListNode *node = sol.mergeTwoList(headA, headB);
    show(node);
}



