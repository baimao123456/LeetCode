//160-两个链表的交点
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
    //求连个链表的交点
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        set<ListNode* > node_set;   //创建一个链表集合，存放节点的地址
        while(headA)
        {
            node_set.insert(headA);
            headA = headA->next;
        }
        while(headB)
        {
            if(node_set.find(headB) != node_set.end()) //如果不是在末尾找到相同的节点，返回此节点
                return headB;
            headB = headB->next;  //遍历链表B
        }
        return NULL;     //遍历完链表B都没有找到相同节点，返回NULL
    }
};
class Solution2
{
    //求连个链表的交点
public:
    //获得链表的长度
    int get_list_length(ListNode* head)
    {
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    //将指针移动到多出节点个数后边的节点
    ListNode* forward_long_list(ListNode* head, int long_len, int short_len)
    {
        int delta = long_len - short_len;
        while(head && delta)
        {
            head = head->next;
            delta--;
        }
        return head;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        int list_A_len = get_list_length(headA);  //获得两个链表的长度
        int list_B_len = get_list_length(headB);

        if(list_A_len > list_B_len)
            headA = forward_long_list(headA, list_A_len, list_B_len);
        else if(list_A_len < list_B_len)
            headB = forward_long_list(headB, list_B_len, list_A_len);
        else
            return NULL;
        while(headA && headB)    //遍历两个链表，找到相同节点
        {
            if(headA->value == headB->value)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
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
    ListNode a(5);
    ListNode b(7);
    ListNode c(6);
    ListNode d(2);
    ListNode e(1);

    ListNode f(1);
    ListNode g(7);
    ListNode h(3);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    f.next = &g;
    g.next = &h;
    h.next = &c;
    Solution1 sol1;
    Solution2 sol2;
    ListNode* headA = &a;
    ListNode* headB = &f;
    cout << "list A is" << endl;
    show(headA);
    cout << "list B is" << endl;
    show(headB);
    cout << "the common node is" << endl;
    ListNode* co_node1 = sol1.getIntersectionNode(headA, headB);
    cout << co_node1->value  << endl;

    cout << "the common node is" << endl;
    ListNode* curnode2 = sol2.getIntersectionNode(headA, headB);
    cout << curnode2->value;

}


