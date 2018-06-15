/*
//���ö���������������
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
        vector<int> count;          //�Ӻ���ǰ��������бȵ�ǰ�ڵ�С�Ľڵ����
        for(int i = nums.size() - 1; i >= 0;i--)
        {
            node_vec.push_back(new TreeNode(nums[i]));
        }
        count.push_back(0);        //�ȵ�һ���ڵ�С��Ϊ0

        for(int i = 1; i < node_vec.size(); i++)
        {
            int count_small = 0;   //��node_vec[i]�ڵ�ֵС�Ľڵ����
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
    //����������ڵ㣬����¼�Ȳ���ڵ�С�Ľڵ����
    //ֻҪinsetNOde����ĳ���ڵ��������������ڵ��countֵ��1
    //���������������˵������ڵ������������������insertnodeС��countsmall��node->count+1
    void BST_insert(TreeNode *node, TreeNode *insert_node, int &count_small)
    {
        if (insert_node->val <= node->val) //�������ڵ��ֵ��node��С�����nodeС�Ľڵ�����1
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

