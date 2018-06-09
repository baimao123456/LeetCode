//160-��������Ľ���
#include <iostream>
#include <set>
using namespace std;
//����ڵ�
struct ListNode
{
    int value;   //�ڵ�ֵ
    ListNode* next; //��һ���ڵ�
    ListNode(int v) : value(v), next(NULL) {}  //���캯��
};
//�������
class Solution1
{
    //����������Ľ���
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        set<ListNode* > node_set;   //����һ�������ϣ���Žڵ�ĵ�ַ
        while(headA)
        {
            node_set.insert(headA);
            headA = headA->next;
        }
        while(headB)
        {
            if(node_set.find(headB) != node_set.end()) //���������ĩβ�ҵ���ͬ�Ľڵ㣬���ش˽ڵ�
                return headB;
            headB = headB->next;  //��������B
        }
        return NULL;     //����������B��û���ҵ���ͬ�ڵ㣬����NULL
    }
};
class Solution2
{
    //����������Ľ���
public:
    //�������ĳ���
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
    //��ָ���ƶ�������ڵ������ߵĽڵ�
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
        int list_A_len = get_list_length(headA);  //�����������ĳ���
        int list_B_len = get_list_length(headB);

        if(list_A_len > list_B_len)
            headA = forward_long_list(headA, list_A_len, list_B_len);
        else if(list_A_len < list_B_len)
            headB = forward_long_list(headB, list_B_len, list_A_len);
        else
            return NULL;
        while(headA && headB)    //�������������ҵ���ͬ�ڵ�
        {
            if(headA->value == headB->value)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
    }
};
//��ӡ����ڵ�ֵ
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


