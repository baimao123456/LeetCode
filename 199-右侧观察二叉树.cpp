//199-右侧观察二叉树
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
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> view;     //保存从右侧观察的节点
        queue<pair<TreeNode *, int> > Q; //元素为<节点，层数>

        if(root)
            Q.push(make_pair(root, 0));
        while(!Q.empty())               //队列中一直有元素，则一直循环
        {
            TreeNode *node = Q.front().first; //获得队首节点指针
            int depth = Q.front().second;     //待搜索节点的层数
            Q.pop();                    //弹出队首元素
            //！！！很巧妙
            //如果当前处理节点的层和view的节点个数相同，
            //则push新元素，如果不相同，更新view[depth]
            if(depth == view.size())
            {
                view.push_back(node->val); //push下一层的第一个元素
            }
            else
                view[depth] = node->val; //更新view[depth]

            if(node->left)
            {
                Q.push(make_pair(node->left, depth + 1));
            }
            if(node->right)
            {
                Q.push(make_pair(node->right, depth + 1));
            }
        }
        return view;
    }
};

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
	Solution sol;

    vector<int> result = sol.rightSideView(&a);
    for(int i = 0; i < result.size(); i++)
    {
        printf("[%d]", result[i]);
    }
	return 0;
}

