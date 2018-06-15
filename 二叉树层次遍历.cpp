//二叉树层次遍历
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
//树节点定义
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//宽度优先搜索二叉树
void BFS_print(TreeNode *root)
{
    queue<TreeNode *> Q;
    Q.push(root);
    while(!Q.empty())
    {
        TreeNode *node = Q.front(); //获得队首节点指针
        printf("[%d]", node->val);  //打印节点值
        Q.pop();                    //弹出队首元素

        if(node->left)
            Q.push(node->left);     //将之前的节点的左右节点压入队列中
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
