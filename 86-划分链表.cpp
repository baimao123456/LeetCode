//86-划分链表
//给定一个链表和一个值x，
//将所有排在大于等于x节点后面的小于x的节点保持原顺序放到大于等于x节点的前面。
//如1->4->3->2->5->2，x = 3，return 1->2->2->4->3->5
//保持原来的顺序
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
class Solution1
{
    //以x为界限划分链表
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode less_head(0); //设置两个临时节点，一个连接比x小的节点，一个连接比x大的节点
        ListNode more_head(0);
        ListNode* less_ptr = &less_head;  //设置两个指针分别指向两个临时节点
        ListNode* more_ptr = &more_head;
        while(head)
        {
            if(head->value < x)           //如果节点值 < x,则将此节点插入到less_ptr后边
            {
                less_ptr->next = head;
                less_ptr = head;
            }
            else
            {
                more_ptr->next = head;
                more_ptr = head;
            }

            head = head->next;           //遍历链表
        }
        less_ptr->next = more_head.next; //less链表尾和more链表头相连接
        more_ptr->next = NULL;           //置空最后一个节点的next
        return less_head.next;           //less_head的next就是新的链表的头结点
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
    ListNode b(4);
    ListNode c(3);
    ListNode d(2);
    ListNode e(5);
    ListNode f(2);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;

    Solution1 sol1;
    ListNode* headA = &a;
    show(headA);
    cout << "after partition the list is；" << endl;
    ListNode* pnode = sol1.partition(headA, 3);
    show(pnode);
}



