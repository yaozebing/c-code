#include<stdbool.h>
#include<stdlib.h>
//void BinaryTreeLeafSize(Btnode* root,int k)
//{
//	if (root == NULL)
//	{
//		return 1;
//	}
//	return 
//}
//BTnode* BinaryTreeFind(BTnode* root, int x)
//{
//	if (root->_data == x)
//	{
//		return root;
//	}
//	if (root == NULL)
//	{
//		return;
//	}
//	return BinaryTreeFind(root->_left, x) + BinaryTreeFind(root->_right, x);
//}
struct TreeNode 
{
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

int* preorderTraversal(struct TreeNode* root, int* returnSize) 
{
	if (root == NULL)
	{
		return NULL;
	}
	printf("%d", root->val);
	preorderTraversal(root->left, returnSize);
	preorderTraversal(root->right, returnSize);
}