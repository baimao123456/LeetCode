//206-链表逆序1
#include <iostream>
using namespace std;
//链表节点
struct ListNode
{
    int value;   //节点值
    ListNode* next; //下一个节点
    ListNode(int v) : value(v), next(NULL) {}  //构造函数
};
//解决方案
class Solution1
{
    //逆序链表的全部节点-就地逆序
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode *new_head = NULL;   //指向逆序后的链表头部
        while(head)
        {
            ListNode* next = head->next;  //备份head->next
            head->next = new_head;        //更新head->next
            new_head = head;              //更新new_head
            head = next;                  //指向下一节点
        }
        return new_head;                  //返回新的头结点
    }
};
class Solution2
{
    //逆序链表的全部节点-头插法
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode temp_head(0);             //创建一个临时头节点
        while(head)
        {
            ListNode* next = head->next;  //备份head->next
            head->next = temp_head.next; //更新head->next
            temp_head.next = head;       //在临时头结点后边插入节点
            head = next;                  //指向下一节点
        }
        return temp_head.next;           //返回新的头结点
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
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution1 sol1;
    Solution2 sol2;
    ListNode* Head = &a;
    cout << "Before reverse:" << endl;
    show(Head);
    cout << "after reverse:" << endl;
    ListNode* head1 = sol1.reverseList(&a);
    show(head1);
    cout << "after reverse:" << endl;
    ListNode* head2 = sol2.reverseList(head1);
    show(head2);
}
