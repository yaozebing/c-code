#include<stdbool.h>
#include<stdlib.h>
int BSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return BSize(root->left)
		+ BSize(root->right) + 1;
}

void _preOrder(struct TreeNode* root, int* a, int* pi)
{
	if (root)
	{
		//前序遍历，保存当前节点的值
		a[*pi] = root->val;
		++(*pi);
		_preOrder(root->left, a, pi);
		_preOrder(root->right, a, pi);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int* a, i;
	*returnSize = BSize(root);
	a = (int*)malloc(sizeof(int) * (*returnSize));
	i = 0;
	_preOrder(root, a, &i);
	return a;
}
