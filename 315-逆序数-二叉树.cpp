/*
//利用二叉树获得逆序个数
*/
#include <stdio.h>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	int count;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), count(0), left(NULL), right(NULL) {}
};
class Solution
{
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<int> result;
        vector<TreeNode *> node_vec;
        vector<int> count;          //从后往前插入过程中比当前节点小的节点个数
        for(int i = nums.size() - 1; i >= 0;i--)
        {
            node_vec.push_back(new TreeNode(nums[i]));
        }
        count.push_back(0);        //比第一个节点小的为0

        for(int i = 1; i < node_vec.size(); i++)
        {
            int count_small = 0;   //比node_vec[i]节点值小的节点个数
            BST_insert(node_vec[0],node_vec[i],count_small);
            count.push_back(count_small);
        }
        for(int i = node_vec.size() - 1; i >= 0; i--)
        {
            delete node_vec[i];
            result.push_back(count[i]);
        }
        return result;
    }
private:
    //二叉树插入节点，并记录比插入节点小的节点个数
    //只要insetNOde进入某个节点的左树，则这个节点的count值加1
    //如果进入右子树，说明这个节点包括他的左子树均比insertnode小，countsmall是node->count+1
    void BST_insert(TreeNode *node, TreeNode *insert_node, int &count_small)
    {
        if (insert_node->val <= node->val) //如果插入节点的值比node的小，则比node小的节点数加1
        {
            node->count++;
            if (node->left){
                BST_insert(node->left, insert_node, count_small);
            }
            else{
                node->left = insert_node;
            }
        }
        else
        {
            count_small += node->count + 1;
            if (node->right){
                BST_insert(node->right, insert_node, count_small);
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

int main()
{
    int test[] = {5, -7, 9, 1, 3, 5, -2, 1};
	std::vector<int> nums;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	Solution solve;
	std::vector<int> result = solve.countSmaller(nums);
	for (int i = 0; i < result.size(); i++){
		printf("[%d]", result[i]);
	}
	printf("\n");
	return 0;
	return 0;
}

