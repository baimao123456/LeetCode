/*
//449-二叉查找树编码与解码
*/
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL),right(NULL) {}
};
class Codec
{
public:
    //编码-将二叉树转换成字符串
    string serialize(TreeNode *root)
    {
        string data;
        BST_preorder(root, data);
        return data;
    }
    //解码-用字符串来构造二叉树
    TreeNode *deserialize(string data)
    {
        if(data.size() <= 0)
            return NULL;
        vector<TreeNode *> node_vec;        //保存树的节点
        int val = 0;
        for(int i = 0; i < data.size();i++)
        {
            if(data[i] == '#')
            {
                node_vec.push_back(new TreeNode(val));
                val = 0;
            }
            else
            {
                val = val * 10 + data[i] - '0';
            }
        }
        for(int i = 1;i < node_vec.size();i++)
        {
            BST_insert(node_vec[0], node_vec[i]);
        }
        return node_vec[0];
    }
private:
    //将int型转换成string
    change_int_to_string(int val, string &str_val)
    {
        string tem;
        while(val)
        {
            tem += val % 10 + '0';
            val /= 10;
        }
        for(int i = tem.size() - 1; i >= 0;i--) //逆序
        {
            str_val += tem[i];
        }
        str_val += '#';
    }
    //前序遍历二叉树，将二叉树转成字符串
    void BST_preorder(TreeNode *node, string &data)
    {
        if(!node)
            return;
        string str_val;
        change_int_to_string(node->val, str_val);
        data += str_val;
        BST_preorder(node->left, data);
        BST_preorder(node->right, data);
    }
    //二叉树节点的插入
    void BST_insert(TreeNode *node, TreeNode *insert_node)
    {
        if (insert_node->val < node->val){
            if (node->left){
                BST_insert(node->left, insert_node);
            }
            else{
                node->left = insert_node;
            }
        }
        else{
            if (node->right){
                BST_insert(node->right, insert_node);
            }
            else{
                node->right = insert_node;
            }
        }
    }
};
void preorder_print(TreeNode *node,int layer){
	if (!node){
		return;
	}
	for (int i = 0; i < layer; i++){
		printf("-----");
	}
	printf("[%d]\n", node->val);
	preorder_print(node->left, layer + 1);
	preorder_print(node->right, layer + 1);
}

int main(){
	TreeNode a(8);
	TreeNode b(3);
	TreeNode c(10);
	TreeNode d(1);
	TreeNode e(6);
	TreeNode f(15);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	Codec solve;
	std::string data = solve.serialize(&a);
	printf("%s\n", data.c_str());
	TreeNode *root = solve.deserialize(data);
	preorder_print(root, 0);
	return 0;
}


