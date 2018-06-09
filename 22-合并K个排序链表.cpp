//22-合并K个有序链表
#include <iostream>
#include <algorithm>
#include <vector>
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
//比较函数--按从小到大排序
bool cmp(const ListNode *a, const ListNode *b)
{
    return a->value < b->value;
}
//合并两个有序链表
ListNode* mergeTwoList(ListNode *l1, ListNode *l2)
{
    ListNode temp_head(0);       //辅助节点
    ListNode *pre = &temp_head;  //辅助指针
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
        pre = pre->next;      //pre指向新链表的最后的节点
    }
    if(l1)                    //将l1剩余的节点连接到pre
        pre->next = l1;
    if(l2)                    //将l2剩余的节点连接到pre
        pre->next = l2;
    return temp_head.next;
}
class Solution1
{
    //合并K个有序链表--排序后相连
public:
    //先排序后连接--lists存放k个链表的头指针
    ListNode* mergeKLists(vector<ListNode *>& lists)
    {
        vector<ListNode *> node_vec;
        for(int i = 0; i < lists.size(); ++i)//将K个链表的全部节点放入node_vec中
        {
            ListNode *head = lists[i];      //获得第i个链表的头结点
            while(head)             //将第i个链表的节点放入node_vec中
            {
                node_vec.push_back(head);
                head = head->next;
            }
        }
        if(node_vec.size() == 0)    //如果节点为0，直接返回null
            return NULL;
        sort(node_vec.begin(), node_vec.end() ,cmp);//根据节点数值进行排序，按从小到大排序
        for(int i = 1; i < node_vec.size(); ++i) //将排序后的节点进行连接
        {
            node_vec[i - 1]->next = node_vec[i];
        }
        node_vec[node_vec.size() - 1]->next = NULL; //最后节点的next为NULL
        return node_vec[0];        //合并后的链表的头结点
    }
};
class Solution2
{
    //合并K个有序链表--分制
public:
    ListNode* mergeKLists(vector<ListNode *>& lists)
    {
        if(lists.size() == 1)   //只有1个链表，不用合并
            return lists[0];

        if(lists.size() == 2)   //合并两个链表
            return mergeTwoList(lists[0], lists[1]);

        int mid = lists.size() / 2;      //将lists分为两个子list
        vector<ListNode *> sub1_lists;
        vector<ListNode *> sub2_lists;

        //将分割的节点分别放进两个子list
        for(int i = 0; i < mid; ++i)
            sub1_lists.push_back(lists[i]);
        for(int i = mid; i < lists.size(); ++i)
            sub2_lists.push_back(lists[i]);

        //再将sub1_lists和sub2_lists进行递归分割，合并
        ListNode *l1 = mergeKLists(sub1_lists);
        ListNode *l2 = mergeKLists(sub2_lists);

        return mergeTwoList(l1, l2);           //分制处理
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




