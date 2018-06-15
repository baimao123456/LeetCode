/*
//114--������ת����
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
class Solution1
{
public:
    //��������ת��������
    void flatten(TreeNode *root)
    {
        vector<TreeNode *> node_vec; //����ǰ������Ľڵ�
        preorder(root, node_vec);    //��ǰ������Ľڵ����node_vec��
        for(int i = 1; i < node_vec.size(); i++)
        {
            node_vec[i - 1]->left = NULL; //ǰһ���ڵ����ָ���ÿգ���ָ�����һԪ��
            node_vec[i - 1]->right = node_vec[i];
        }
    }
private:
    //ǰ����������ڵ㱣�浽������
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
    //���õݹ�
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
        if(!node->left && !node->right) //�ҵ����������ڵ�
        {
            last = node;
            return;
        }
        TreeNode* left = node->left;  //�������ҽڵ㣬�������нڵ������
        TreeNode* right = node->right;
        TreeNode* left_last = NULL;
        TreeNode* right_last = NULL;
        if(left)     //��������������ݹ齫������ת������������������������ڵ�
        {
            preorder(left, left_last); //left�����Ѿ�ת�������������ͽ��нڵ�����
            node->left = NULL;         //��ڵ��ÿ�
            node->right = left;        //�ҽڵ���������
            last = left_last;          //��ǰ�ڵ�������������ڵ�
        }
        if(right)    //��������������ݹ齫������ת������������������������ڵ�
        {
            preorder(right, right_last);
            if(left_last)              //������������������ڵ�
                left_last->right = right; //��������ת�ɵ�����������������ڵ�����
            last = right_last;         //������ɺ�����ڵ��������������ڵ�
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
