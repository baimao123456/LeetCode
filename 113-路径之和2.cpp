/*
//113-路径之和2
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
    //找到和是sum的路径
    vector<vector<int> >pathSum(TreeNode *root, int sum)
    {
        vector<vector<int> > result;
        vector<int> path;     //路径
        int path_value = 0;   //路径和
        preorder(root, path_value, sum, path, result);
        return result;
    }
private:
    void preorder(TreeNode *node, int &path_value, int &sum,
                  vector<int> &path,
                  vector<vector<int> > &result)
    {
        if(node == NULL)
            return;

        path_value += node->val;    //遍历一个节点，就更新路径和
        path.push_back(node->val);  //将当前节点加入路径中
        //如果node节点是叶子节点且路径和等于sum，将此路径保存
        //如果不是叶子节点，继续遍历
        if(!node->left && !node->right && path_value == sum)
            result.push_back(path);

        preorder(node->left, path_value, sum, path, result);
        preorder(node->right, path_value, sum, path, result);
        //程序执行到这里，表示node已经是叶子节点，
        //但是路径和不满足条件，则返回node的父节点，
        //继续遍历其他节点
        path_value -= node->val;
        path.pop_back();           //遍历完成，将节点从路径栈中弹出
    }
};
int main(void)
{
	TreeNode a(5);
	TreeNode b(4);
	TreeNode c(8);
	TreeNode d(11);
	TreeNode e(13);
	TreeNode f(4);
	TreeNode g(7);
	TreeNode h(2);
	TreeNode x(5);
	TreeNode y(1);

	a.left = &b;
	a.right = &c;
	b.left = &d;
	c.left = &e;
	c.right = &f;
    d.left = &g;
    d.right = &h;
    f.left = &x;
    f.right = &y;
    Solution sol;
    vector<vector<int> > result = sol.pathSum(&a, 22);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            printf("[%d]", result[i][j]);
        }
        printf("\n");
    }
	return 0;
}

