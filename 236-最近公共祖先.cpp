/*
//236-最近公共祖先
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
class Solution
{
public:
    //找到p 和q的最近公共祖先
    TreeNode * lowestCommonAncestor(TreeNode *root, TreeNode *p,TreeNode *q)
    {
        vector<TreeNode *> path;            //遍历时的临时栈
        vector<TreeNode *> node_p_path;     //node——p的路径
        vector<TreeNode *> node_q_path;     //node--q的路径
        int finish = 0;
        preorder(root, p, path, node_p_path, finish); //获得到p节点的路径
        path.clear();                       //清除临时路径，继续保存下一节点路径
        finish = 0;
        preorder(root, q, path, node_q_path , finish);//获得到q节点的路径

        /*int path_len = 0;           //较短路径的长度
        if(node_p_path.size() < node_q_path.size())  //获得较短路径
            path_len = node_p_path.size();
        else
            path_len = node_q_path.size();
        */
        int path_len = min(node_p_path.size(), node_q_path.size());
        TreeNode* result;          //同时遍历从根节点到pq节点的路径
        for(int i = 0; i < path_len; i++)
        {
            if(node_p_path[i] == node_q_path[i])
                result = node_p_path[i];
        }
        return result;
    }
    //寻找根节点node到节点search的路径
    void preorder(TreeNode *node, TreeNode *search,
                  vector<TreeNode *> &path,
                  vector<TreeNode *> &result,
                  int &finish)
    {
        if(node == NULL)
            return;

        path.push_back(node);  //将当前节点加入到路径中去
        if(node == search)     //如果找到了要找的节点，则将路径保存，同时设定完成标志位
        {
            finish = 1;        //
            result = path;
        }
        preorder(node->left, search, path, result, finish);//寻找左树
        preorder(node->right, search, path, result, finish);//寻找右树
        //如果没有找到该节点，且当前节点又是叶子节点，
        //则返回父节点继续查找别的子树
        path.pop_back();
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

	Solution solve;
	TreeNode *result = solve.lowestCommonAncestor(&a, &b, &f);
	printf("lowestCommonAncestor = %d\n", result->val);
	result = solve.lowestCommonAncestor(&a, &d, &z);
	printf("lowestCommonAncestor = %d\n", result->val);
	result = solve.lowestCommonAncestor(&a, &b, &y);
	printf("lowestCommonAncestor = %d\n", result->val);
	return 0;
}


