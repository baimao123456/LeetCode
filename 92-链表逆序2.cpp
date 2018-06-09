//92-链表逆序2
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
class Solution
{
    //逆序链表的 第m到n节点
public:
    ListNode* reverseList(ListNode* head, int m, int n)
    {
        int change_len = n - m  + 1;   //需要逆序的节点个数
        ListNode* pre_head = NULL;     //初始化开始逆序节点的前驱
        ListNode* result = head;       //最终转换后的链表头结点
        while(head && --m)
        {
            pre_head = head;           //更新前驱节点
            head = head->next;         //更新头节点
        }
        ListNode* modify_list_tail = head; //逆序后的链表尾部
        ListNode* new_head = NULL;
        while(head && change_len)          //逆序changelen个节点
        {
            ListNode* next = head->next;   //备份下一个节点
            head->next = new_head;         //更新head的指向
            new_head = head;               //更新new_head
            head = next;                   //指向下一个节点
            change_len--;                  //没完成一个节点逆序，change_len--
        }
        modify_list_tail->next = head;
        if(pre_head)         //如果preHead不为空，说明 m >= 1,不是从第一个节点开始逆序的
            pre_head->next = new_head;    //将逆序前的前驱和逆序后的头节点连接
        else
            result = new_head; //如果从头开始逆序，直接返回逆序后的节点
        return result;
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
    Solution sol;
    ListNode* Head = &a;
    cout << "Before reverse:" << endl;
    show(Head);
    cout << "after reverse:" << endl;
    ListNode* head = sol.reverseList(&a, 2, 2);
    show(head);
}

