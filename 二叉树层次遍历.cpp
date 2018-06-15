//��������α���
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
//���ڵ㶨��
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//�����������������
void BFS_print(TreeNode *root)
{
    queue<TreeNode *> Q;
    Q.push(root);
    while(!Q.empty())
    {
        TreeNode *node = Q.front(); //��ö��׽ڵ�ָ��
        printf("[%d]", node->val);  //��ӡ�ڵ�ֵ
        Q.pop();                    //��������Ԫ��

        if(node->left)
            Q.push(node->left);     //��֮ǰ�Ľڵ�����ҽڵ�ѹ�������
        if(node->right)
            Q.push(node->right);

    }
}
int main(void)
{
    TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	BFS_print(&a);
	return 0;
}
