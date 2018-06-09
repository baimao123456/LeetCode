//141-142-�����������ڵ�
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
    //�ж��Ƿ��ǻ�״����--set
public:
    ListNode* detectCycle(ListNode* head)
    {
        set<ListNode* > node_set;
        while(head)                //��������
        {
            if(node_set.find(head) != node_set.end()) //����Ѿ�������
                return head;
            node_set.insert(head); //��������ڣ������
            head = head->next;     //��һ�ڵ�
        }
        return NULL;               //û��������������
    }
};
class Solution2
{
    //��״���������--����ָ��
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;  //��ָ��
        ListNode* fast = head;  //��ָ��
        ListNode* meet = NULL;  //����ָ��
        while(fast)             //�����޻����ҽڵ����Ϊż����ʱ������ѭ��
        {
            slow = slow->next;
            fast = fast->next;
            if(!fast)           //�����޻����ҽڵ����Ϊ������ʱ������ѭ��
                return NULL;
            fast = fast->next;  //fast����һ��
            if(fast == slow)    //���fast��slow��������¼������λ��
            {
                meet = fast;
                break;
            }
        }
        if(meet == NULL)        //���û��������֤��û�л�
            return NULL;
        while(head && meet)     //Ѱ�һ�����ʼλ��
        {
            if(head == meet)
                return head;    //headΪ������ʼλ��

            head = head->next;  //ÿ����һ��
            meet = meet->next;
        }
        return NULL;
    }
};
class Solution3
{
    //��״���������--����ָ��2-��ָoffer�ⷨ
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;  //��ָ��
        ListNode* fast = head;  //��ָ��
        ListNode* meet = NULL;  //����ָ��
        int cycle_len = 1;      //���нڵ����
        while(fast)             //���fast��Ϊ�գ�Ѱ�������Ľڵ�λ��
        {
            slow = slow->next;
            fast = fast->next;
            if(!fast)           //���ֻ��һ���ڵ㣬�����ڻ�
                return NULL;
            fast = fast->next;  //fast����һ��
            if(fast == slow)    //���fast��slow��������¼������λ��
            {
                meet = fast;
                break;
            }
        }
        if(meet == NULL)        //���û��������֤��û�л�
            return NULL;
        //���������Ľڵ����
        ListNode* node = meet->next;
        while(node != meet)     //Ѱ�һ�����ʼλ��
        {
            node = node->next;
            cycle_len++;        //���Ľڵ���� ��1
        }
        slow = head;
        fast = head;
        while(cycle_len > 0)    //�Ƚ���ָ��ǰ��һ�����Ĳ���
        {
            fast = fast->next;
            cycle_len--;
        }
        while()
        return NULL;
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



