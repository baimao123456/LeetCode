//141-142-环形链表的入口点
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
    //判断是否是环状链表--set
public:
    ListNode* detectCycle(ListNode* head)
    {
        set<ListNode* > node_set;
        while(head)                //遍历链表
        {
            if(node_set.find(head) != node_set.end()) //如果已经存在了
                return head;
            node_set.insert(head); //如果不存在，则插入
            head = head->next;     //下一节点
        }
        return NULL;               //没有遇到环，返回
    }
};
class Solution2
{
    //环状链表求入口--快慢指针
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;  //慢指针
        ListNode* fast = head;  //快指针
        ListNode* meet = NULL;  //相遇指针
        while(fast)             //链表无环，且节点个数为偶数个时，跳出循环
        {
            slow = slow->next;
            fast = fast->next;
            if(!fast)           //链表无环，且节点个数为奇数个时，跳出循环
                return NULL;
            fast = fast->next;  //fast再走一步
            if(fast == slow)    //如果fast和slow相遇，记录相遇的位置
            {
                meet = fast;
                break;
            }
        }
        if(meet == NULL)        //如果没有相遇，证明没有环
            return NULL;
        while(head && meet)     //寻找环的起始位置
        {
            if(head == meet)
                return head;    //head为环的起始位置

            head = head->next;  //每次走一步
            meet = meet->next;
        }
        return NULL;
    }
};
class Solution3
{
    //环状链表求入口--快慢指针2-剑指offer解法
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;  //慢指针
        ListNode* fast = head;  //快指针
        ListNode* meet = NULL;  //相遇指针
        int cycle_len = 1;      //环中节点个数
        while(fast)             //如果fast不为空，寻找相遇的节点位置
        {
            slow = slow->next;
            fast = fast->next;
            if(!fast)           //如果只有一个节点，不存在环
                return NULL;
            fast = fast->next;  //fast再走一步
            if(fast == slow)    //如果fast和slow相遇，记录相遇的位置
            {
                meet = fast;
                break;
            }
        }
        if(meet == NULL)        //如果没有相遇，证明没有环
            return NULL;
        //计算链表环的节点个数
        ListNode* node = meet->next;
        while(node != meet)     //寻找环的起始位置
        {
            node = node->next;
            cycle_len++;        //环的节点个数 加1
        }
        slow = head;
        fast = head;
        while(cycle_len > 0)    //先将快指针前进一个环的步数
        {
            fast = fast->next;
            cycle_len--;
        }
        while()
        return NULL;
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
    ListNode f(6);
    ListNode g(7);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &c;

    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;
    ListNode* headA = &a;

    ListNode* result1 = sol1.detectCycle(headA);
    if(result1)
        cout << "the input node value is "<< result1->value << endl;
    else
        cout << "not found" << endl;


    ListNode* result2 = sol2.detectCycle(headA);
    if(result2)
        cout << "the input node value is "<< result2->value << endl;
    else
        cout << "not found" << endl;

    ListNode* result3 = sol3.detectCycle(headA);
    if(result3)
        cout << "the input node value is "<< result2->value << endl;
    else
        cout << "not found" << endl;
}



