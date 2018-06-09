//92-��������2
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
class Solution
{
    //��������� ��m��n�ڵ�
public:
    ListNode* reverseList(ListNode* head, int m, int n)
    {
        int change_len = n - m  + 1;   //��Ҫ����Ľڵ����
        ListNode* pre_head = NULL;     //��ʼ����ʼ����ڵ��ǰ��
        ListNode* result = head;       //����ת���������ͷ���
        while(head && --m)
        {
            pre_head = head;           //����ǰ���ڵ�
            head = head->next;         //����ͷ�ڵ�
        }
        ListNode* modify_list_tail = head; //����������β��
        ListNode* new_head = NULL;
        while(head && change_len)          //����changelen���ڵ�
        {
            ListNode* next = head->next;   //������һ���ڵ�
            head->next = new_head;         //����head��ָ��
            new_head = head;               //����new_head
            head = next;                   //ָ����һ���ڵ�
            change_len--;                  //û���һ���ڵ�����change_len--
        }
        modify_list_tail->next = head;
        if(pre_head)         //���preHead��Ϊ�գ�˵�� m >= 1,���Ǵӵ�һ���ڵ㿪ʼ�����
            pre_head->next = new_head;    //������ǰ��ǰ����������ͷ�ڵ�����
        else
            result = new_head; //�����ͷ��ʼ����ֱ�ӷ��������Ľڵ�
        return result;
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
    Solution sol;
    ListNode* Head = &a;
    cout << "Before reverse:" << endl;
    show(Head);
    cout << "after reverse:" << endl;
    ListNode* head = sol.reverseList(&a, 2, 2);
    show(head);
}

