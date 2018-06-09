//206-��������1
#include <iostream>
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
    //���������ȫ���ڵ�-�͵�����
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode *new_head = NULL;   //ָ������������ͷ��
        while(head)
        {
            ListNode* next = head->next;  //����head->next
            head->next = new_head;        //����head->next
            new_head = head;              //����new_head
            head = next;                  //ָ����һ�ڵ�
        }
        return new_head;                  //�����µ�ͷ���
    }
};
class Solution2
{
    //���������ȫ���ڵ�-ͷ�巨
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode temp_head(0);             //����һ����ʱͷ�ڵ�
        while(head)
        {
            ListNode* next = head->next;  //����head->next
            head->next = temp_head.next; //����head->next
            temp_head.next = head;       //����ʱͷ����߲���ڵ�
            head = next;                  //ָ����һ�ڵ�
        }
        return temp_head.next;           //�����µ�ͷ���
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
