//138-�����������ȿ���
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
//�������ָ�������ڵ�
struct RandomListNode
{
    int value;      //�ڵ�ֵ
    RandomListNode *next, *random;   //��һ�ڵ㣬����ڵ�
    RandomListNode(int x) : value(x), next(NULL), random(NULL) {} //���캯��
};
class Solution
{   //ʵ�ָ����������㸴�ƣ����ظ��Ƶ������ͷ�ڵ�
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        map<RandomListNode* , int> node_map;   //��ַ���ڵ�λ�õ�ӳ��
        vector<RandomListNode* > node_vec;     //ʹ��vector���ݴ洢�ڵ�λ�÷��ʵ�ַ
        RandomListNode *ptr = head;
        int i = 0;    //�洢�ڵ�� id
        while(ptr)
        {
            node_vec.push_back(new RandomListNode(ptr->value)); //���½�������ڵ����vector��
            node_map[ptr] = i;
            ptr = ptr->next;
            i++;      //�ڵ�λ����Ӧ�� 1
        }
        node_vec.push_back(0); // ���һ���ڵ��next��NULL
        ptr = head;
        i = 0;
        while(ptr)   //�ٴα���ԭ������������next��randomָ��
        {
            node_vec[i]->next = node_vec[i + 1]; //�����������ָ��
            if(ptr->random)
            {
                int id = node_map[ptr->random]; //����ԭ����ĵ�ַ�ҵ���ӦID���ٴ�vector�л�ýڵ�ĵ�ַ
                node_vec[i]->random = node_vec[id];
            }
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];  //node_vec[0]��ʵ���������ͷ���
    }
};
void show(RandomListNode* head)
{
    while(head)
    {
        printf("value is : %d   ", head->value);
        if(head->random)
            printf("random is : %d\n", head->random->value);
        else
            printf("random is : NULL\n");
        head = head->next;
    }
}
void Map_Test()
{
    map<RandomListNode* , int> node_map;   //���ڵ�ĵ�ַӳ���int������
    RandomListNode a(5);
    RandomListNode b(3);
    RandomListNode c(6);

    a.next = &b;
    b.next = &c;
    a.random = &c;
    b.random = &a;
    c.random = &c;
    node_map[&a] = 1;    //��a�ĵ�ַӳ���  1
    node_map[&b] = 2;
    node_map[&c] = 3;
    printf("a.random id is: %d\n", node_map[a.random]);
    printf("b.random id is: %d\n", node_map[b.random]);
    printf("c.random id is: %d\n", node_map[c.random]);
}
int main(void)
{
    RandomListNode a(1);
    RandomListNode b(2);
    RandomListNode c(3);
    RandomListNode d(4);
    RandomListNode e(5);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    a.random = &c;
    b.random = &d;
    c.random = &c;
    e.random = &d;
    Solution sol;
    RandomListNode *head = &a;
    show(head);
    printf("after copy the list is \n");
    RandomListNode *node = sol.copyRandomList(head);
    show(node);
}
