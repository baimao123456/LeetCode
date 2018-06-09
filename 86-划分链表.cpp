//86-��������
//����һ�������һ��ֵx��
//���������ڴ��ڵ���x�ڵ�����С��x�Ľڵ㱣��ԭ˳��ŵ����ڵ���x�ڵ��ǰ�档
//��1->4->3->2->5->2��x = 3��return 1->2->2->4->3->5
//����ԭ����˳��
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
    //��xΪ���޻�������
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode less_head(0); //����������ʱ�ڵ㣬һ�����ӱ�xС�Ľڵ㣬һ�����ӱ�x��Ľڵ�
        ListNode more_head(0);
        ListNode* less_ptr = &less_head;  //��������ָ��ֱ�ָ��������ʱ�ڵ�
        ListNode* more_ptr = &more_head;
        while(head)
        {
            if(head->value < x)           //����ڵ�ֵ < x,�򽫴˽ڵ���뵽less_ptr���
            {
                less_ptr->next = head;
                less_ptr = head;
            }
            else
            {
                more_ptr->next = head;
                more_ptr = head;
            }

            head = head->next;           //��������
        }
        less_ptr->next = more_head.next; //less����β��more����ͷ������
        more_ptr->next = NULL;           //�ÿ����һ���ڵ��next
        return less_head.next;           //less_head��next�����µ������ͷ���
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
    cout << "after partition the list is��" << endl;
    ListNode* pnode = sol1.partition(headA, 3);
    show(pnode);
}



