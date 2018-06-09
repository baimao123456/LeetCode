//22-�ϲ�K����������
#include <iostream>
#include <algorithm>
#include <vector>
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
//�ȽϺ���--����С��������
bool cmp(const ListNode *a, const ListNode *b)
{
    return a->value < b->value;
}
//�ϲ�������������
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
class Solution1
{
    //�ϲ�K����������--���������
public:
    //�����������--lists���k�������ͷָ��
    ListNode* mergeKLists(vector<ListNode *>& lists)
    {
        vector<ListNode *> node_vec;
        for(int i = 0; i < lists.size(); ++i)//��K�������ȫ���ڵ����node_vec��
        {
            ListNode *head = lists[i];      //��õ�i�������ͷ���
            while(head)             //����i������Ľڵ����node_vec��
            {
                node_vec.push_back(head);
                head = head->next;
            }
        }
        if(node_vec.size() == 0)    //����ڵ�Ϊ0��ֱ�ӷ���null
            return NULL;
        sort(node_vec.begin(), node_vec.end() ,cmp);//���ݽڵ���ֵ�������򣬰���С��������
        for(int i = 1; i < node_vec.size(); ++i) //�������Ľڵ��������
        {
            node_vec[i - 1]->next = node_vec[i];
        }
        node_vec[node_vec.size() - 1]->next = NULL; //���ڵ��nextΪNULL
        return node_vec[0];        //�ϲ���������ͷ���
    }
};
class Solution2
{
    //�ϲ�K����������--����
public:
    ListNode* mergeKLists(vector<ListNode *>& lists)
    {
        if(lists.size() == 1)   //ֻ��1���������úϲ�
            return lists[0];

        if(lists.size() == 2)   //�ϲ���������
            return mergeTwoList(lists[0], lists[1]);

        int mid = lists.size() / 2;      //��lists��Ϊ������list
        vector<ListNode *> sub1_lists;
        vector<ListNode *> sub2_lists;

        //���ָ�Ľڵ�ֱ�Ž�������list
        for(int i = 0; i < mid; ++i)
            sub1_lists.push_back(lists[i]);
        for(int i = mid; i < lists.size(); ++i)
            sub2_lists.push_back(lists[i]);

        //�ٽ�sub1_lists��sub2_lists���еݹ�ָ�ϲ�
        ListNode *l1 = mergeKLists(sub1_lists);
        ListNode *l2 = mergeKLists(sub2_lists);

        return mergeTwoList(l1, l2);           //���ƴ���
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

    ListNode i(8);
    ListNode j(12);
    ListNode k(122);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    f.next = &g;
    g.next = &h;

    i.next = &j;
    j.next = &k;

    ListNode* headA = &a;
    ListNode* headB = &f;
    ListNode* headC = &i;

    Solution1 sol1;
    Solution2 sol2;
    cout << "list A is" << endl;
    show(headA);
    cout << "list B is" << endl;
    show(headB);
    cout << "list C is" << endl;
    show(headC);

    cout << "after merge : " << endl;
    vector<ListNode*> lists = { headA, headB, headC};
    //ListNode *node1 = sol1.mergeKLists(lists);
    //show(node1);

    //cout << "after merge : " << endl;
    ListNode *node2 = sol2.mergeKLists(lists);
    show(node2);
}




