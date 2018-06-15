/*
//236-�����������
*/
#include <stdio.h>
#include <vector>
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
    //�ҵ�p ��q�������������
    TreeNode * lowestCommonAncestor(TreeNode *root, TreeNode *p,TreeNode *q)
    {
        vector<TreeNode *> path;            //����ʱ����ʱջ
        vector<TreeNode *> node_p_path;     //node����p��·��
        vector<TreeNode *> node_q_path;     //node--q��·��
        int finish = 0;
        preorder(root, p, path, node_p_path, finish); //��õ�p�ڵ��·��
        path.clear();                       //�����ʱ·��������������һ�ڵ�·��
        finish = 0;
        preorder(root, q, path, node_q_path , finish);//��õ�q�ڵ��·��

        /*int path_len = 0;           //�϶�·���ĳ���
        if(node_p_path.size() < node_q_path.size())  //��ý϶�·��
            path_len = node_p_path.size();
        else
            path_len = node_q_path.size();
        */
        int path_len = min(node_p_path.size(), node_q_path.size());
        TreeNode* result;          //ͬʱ�����Ӹ��ڵ㵽pq�ڵ��·��
        for(int i = 0; i < path_len; i++)
        {
            if(node_p_path[i] == node_q_path[i])
                result = node_p_path[i];
        }
        return result;
    }
    //Ѱ�Ҹ��ڵ�node���ڵ�search��·��
    void preorder(TreeNode *node, TreeNode *search,
                  vector<TreeNode *> &path,
                  vector<TreeNode *> &result,
                  int &finish)
    {
        if(node == NULL)
            return;

        path.push_back(node);  //����ǰ�ڵ���뵽·����ȥ
        if(node == search)     //����ҵ���Ҫ�ҵĽڵ㣬��·�����棬ͬʱ�趨��ɱ�־λ
        {
            finish = 1;        //
            result = path;
        }
        preorder(node->left, search, path, result, finish);//Ѱ������
        preorder(node->right, search, path, result, finish);//Ѱ������
        //���û���ҵ��ýڵ㣬�ҵ�ǰ�ڵ�����Ҷ�ӽڵ㣬
        //�򷵻ظ��ڵ�������ұ������
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


