/*
//预备知识-拉链法构造哈希函数
*/
#include <stdio.h>
#include <vector>
using namespace std;
//链表节点
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//整型hash函数
int hash_func(int key, int table_len)
{
    return key % table_len;
}
//插入节点node，node中存放hash键
void insert(ListNode *hash_table[], ListNode *node, int table_len)
{
    int hash_key = hash_func(node->val, table_len);
    node->next = hash_table[hash_key];        //头插法插入节点
    hash_table[hash_key] = node;
}
//搜索value是否在hash表中
bool search(ListNode *hash_table[], int value, int table_len)
{
    int hash_key = hash_func(value, table_len); //获得value的键值
    ListNode *head = hash_table[hash_key];      //获得头结点
    while(head)
    {
        if(head->val == value)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}
int main(void)
{
    const int TABLE_LEN = 11;
	ListNode *hash_table[TABLE_LEN] = {0};
	std::vector<ListNode *> hash_node_vec;
	int test[8] = {1, 1, 4, 9, 20, 30, 150, 500};
	for (int i = 0; i < 8; i++){
		hash_node_vec.push_back(new ListNode(test[i]));
	}
	for (int i = 0; i < hash_node_vec.size(); i++){
		insert(hash_table, hash_node_vec[i], TABLE_LEN);
	}
	printf("Hash table:\n");
	for (int i = 0; i < TABLE_LEN; i++){
		printf("[%d]:", i);
		ListNode *head = hash_table[i];
		while(head){
			printf("->%d", head->val);
			head = head->next;
		}
		printf("\n");
	}
	printf("\n");
	printf("Test search:\n");
	for (int i = 0; i < 10; i++){
		if (search(hash_table, i, TABLE_LEN)){
			printf("%d is in the hash table.\n");
		}
		else{
			printf("%d is not in the hash table.\n");
		}
	}
    return 0;
}
