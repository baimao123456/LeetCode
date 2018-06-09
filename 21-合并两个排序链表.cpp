//21-�ϲ�������������
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
class Solution
{
    //�ϲ�������������
public:
    ListNode* mergeTwoList(ListNode *l1, ListNode *l2)
    {
        ListNode temp_head(0);       //�����ڵ�
        ListNode *pre = &temp_head;  //����ָ��
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
            pre = pre->next;      //preָ������������Ľڵ�
        }
        if(l1)                    //��l1ʣ��Ľڵ����ӵ�pre
            pre->next = l1;
        if(l2)                    //��l2ʣ��Ľڵ����ӵ�pre
            pre->next = l2;
        return temp_head.next;
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



