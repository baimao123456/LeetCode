/*
//114--二叉树转链表
*/
#include <stdio.h>
#include <vector>
using namespace std;
//树节点定义
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution1
{
public:
    //将二叉树转换成链表
    void flatten(TreeNode *root)
    {
        vector<TreeNode *> node_vec; //保存前序遍历的节点
        preorder(root, node_vec);    //将前序遍历的节点放入node_vec中
        for(int i = 1; i < node_vec.size(); i++)
        {
            node_vec[i - 1]->left = NULL; //前一个节点的左指针置空，右指针接下一元素
            node_vec[i - 1]->right = node_vec[i];
        }
    }
private:
    //前序遍历，将节点保存到数组中
    void preorder(TreeNode* node, vector<TreeNode *>& node_vec)
    {
        if(node == NULL)
            return;
        node_vec.push_back(node);
        preorder(node->left, node_vec);
        preorder(node->right, node_vec);
    }
};
class Solution2
{
public:
    //利用递归
    void flatten(TreeNode *root)
    {
        if(root == NULL)
            return;
        TreeNode *last = NULL;
        preorder(root, last);
    }
private:
    void preorder(TreeNode* node, TreeNode* &last)
    {
        if(node == NULL)
            return;
        if(!node->left && !node->right) //找到子树的最后节点
        {
            last = node;
            return;
        }
        TreeNode* left = node->left;  //备份左右节点，用来进行节点的连接
        TreeNode* right = node->right;
        TreeNode* left_last = NULL;
        TreeNode* right_last = NULL;
        if(left)     //若有左子树，则递归将左子树转换成链表，并获得左子树的最后节点
        {
            preorder(left, left_last); //left子树已经转成链表，接下来就进行节点连接
            node->left = NULL;         //左节点置空
            node->right = left;        //右节点连接子树
            last = left_last;          //当前节点的左子树的最后节点
        }
        if(right)    //若有右子树，则递归将右子树转换成链表，并获得右子树的最后节点
        {
            preorder(right, right_last);
            if(left_last)              //如果存在左子树的最后节点
                left_last->right = right; //则将右子树转成的链表和左子树的最后节点连接
            last = right_last;         //连接完成后的最后节点是右子树的最后节点
        }
    }
};
int main(void)
{
    TreeNode a(3);
	TreeNode b(5);
	TreeNode c(1);
	TreeNode d(6);
	TreeNode e(2);
	TreeNode f(0);
	TreeNode x(8);
	TreeNode y(7);
	TreeNode z(4);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &x;
	e.left = &y;
	e.right = &z;

	/*Solution1 solve1;
    solve1.flatten(&a);
    TreeNode * root = &a;
    while(root)
    {
        printf("[%d]", root->val);
        root = root->right;
    }*/
    Solution2 solve2;
    solve2.flatten(&a);
    TreeNode * root = &a;
    while(root)
    {
        printf("[%d]", root->val);
        root = root->right;
    }





	return 0;
}
