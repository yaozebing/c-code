//#include"Դ.c"
//int maxDepth(struct TreeNode* root) {
//	return root ? 1 + fmax(maxDepth(root->left), maxDepth(root->right)) : 0;
//}
//
//bool isBalanced(struct TreeNode* root) {
//	if (root == NULL)
//		return true;
//	int left = maxDepth(root->left);
//	int right = maxDepth(root->right);
//	return abs(left - right) < 2
//		&& isBalanced(root->left)
//		&& isBalanced(root->right);
//}


#include <stdio.h>
#include <malloc.h>

typedef struct BTNode
{
	char _data;
	struct BTNode* _left;
	struct BTNode* _right;
}BTNode;

//�������
void Inorder(BTNode* root)
{
	if (root)
	{
		Inorder(root->_left);
		printf("%c ", root->_data);
		Inorder(root->_right);
	}
}

BTNode* CreatBTree(char* str, int* pi)
{
	if (str[*pi] != '#')
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = str[*pi];
		++(*pi);
		root->_left = CreatBTree(str, pi);
		++(*pi);
		root->_right = CreatBTree(str, pi);
		return root;
	}
	else
		return NULL;  
}

int main()
{
	char str[101];
	int i = 0;
	//�����ַ���
	scanf("%s", str);
	//����������
	BTNode* root = CreatBTree(str, &i);
	//�����ӡ������
	Inorder(root);
	printf("\n");
	return 0;
}