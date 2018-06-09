//138-复杂链表的深度拷贝
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
//具有随机指针的链表节点
struct RandomListNode
{
    int value;      //节点值
    RandomListNode *next, *random;   //下一节点，随机节点
    RandomListNode(int x) : value(x), next(NULL), random(NULL) {} //构造函数
};
class Solution
{   //实现复杂链表的深层复制，返回复制的链表的头节点
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        map<RandomListNode* , int> node_map;   //地址到节点位置的映射
        vector<RandomListNode* > node_vec;     //使用vector根据存储节点位置访问地址
        RandomListNode *ptr = head;
        int i = 0;    //存储节点的 id
        while(ptr)
        {
            node_vec.push_back(new RandomListNode(ptr->value)); //将新建的链表节点存入vector中
            node_map[ptr] = i;
            ptr = ptr->next;
            i++;      //节点位置相应加 1
        }
        node_vec.push_back(0); // 最后一个节点的next是NULL
        ptr = head;
        i = 0;
        while(ptr)   //再次遍历原链表，用来设置next和random指针
        {
            node_vec[i]->next = node_vec[i + 1]; //连接新链表的指针
            if(ptr->random)
            {
                int id = node_map[ptr->random]; //根据原链表的地址找到对应ID，再从vector中获得节点的地址
                node_vec[i]->random = node_vec[id];
            }
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];  //node_vec[0]其实是新链表的头结点
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
    map<RandomListNode* , int> node_map;   //将节点的地址映射成int型数据
    RandomListNode a(5);
    RandomListNode b(3);
    RandomListNode c(6);

    a.next = &b;
    b.next = &c;
    a.random = &c;
    b.random = &a;
    c.random = &c;
    node_map[&a] = 1;    //将a的地址映射成  1
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
