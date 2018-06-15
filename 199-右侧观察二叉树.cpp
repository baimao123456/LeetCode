//199-�Ҳ�۲������
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
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> view;     //������Ҳ�۲�Ľڵ�
        queue<pair<TreeNode *, int> > Q; //Ԫ��Ϊ<�ڵ㣬����>

        if(root)
            Q.push(make_pair(root, 0));
        while(!Q.empty())               //������һֱ��Ԫ�أ���һֱѭ��
        {
            TreeNode *node = Q.front().first; //��ö��׽ڵ�ָ��
            int depth = Q.front().second;     //�������ڵ�Ĳ���
            Q.pop();                    //��������Ԫ��
            //������������
            //�����ǰ����ڵ�Ĳ��view�Ľڵ������ͬ��
            //��push��Ԫ�أ��������ͬ������view[depth]
            if(depth == view.size())
            {
                view.push_back(node->val); //push��һ��ĵ�һ��Ԫ��
            }
            else
                view[depth] = node->val; //����view[depth]

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

