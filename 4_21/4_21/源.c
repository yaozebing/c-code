#include<stdbool.h>
#include<stdlib.h>
#include<stdbool.h>

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
typedef struct TreeNode 
{
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
}TreeNode;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int Getsize(TreeNode* root)//获取树的节点数量
{
	if (root == NULL)
	{
		return 0;
	}

	return	Getsize(root->left) + Getsize(root->right) + 1;
}
void Pre(int* num, int* i, TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	num[*i] = root->val;
	(*i)++;
	Pre(num, i, root->left);
	Pre(num, i, root->right);
}
//先序遍历
int* preorderTraversal(TreeNode* root, int* returnSize)
{
	//int sz = 0;
	//Getsize(root, &sz);
	//*returnSize = sz;
	*returnSize = Getsize(root);
	int* num = (int*)malloc((sizeof(int) * *(returnSize)));//给返回数组开辟空间
	int i = 0;
	Pre(num, &i, root);//将数据存入数组
	return num;
}
//中序遍历
void In(int* num, int* i, TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	In(num, i, root->left);
	num[*i] = root->val;
	(*i)++;
	In(num, i, root->right);
}
int* inorderTraversal(TreeNode* root, int* returnSize)
{

	*returnSize = Getsize(root);
	int* num = (int*)malloc((sizeof(int) * *(returnSize)));//给返回数组开辟空间
	int i = 0;
	In(num, &i, root);//将数据存入数组
	return num;
}
//后序遍历
void Post(int* num, int* i, TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	Post(num, i, root->left);
	Post(num, i, root->right);
	num[*i] = root->val;
	(*i)++;
}
int* postorderTraversal(TreeNode* root, int* returnSize)
{

	*returnSize = Getsize(root);
	int* num = (int*)malloc((sizeof(int) * *(returnSize)));//给返回数组开辟空间
	int i = 0;
	Post(num, &i, root);//将数据存入数组
	return num;
}

bool _isUnivalTree(struct TreeNode* root, int val)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->val != val)
	{
		return false;
	}
	return _isUnivalTree(root->left, val) && _isUnivalTree(root->right, val);
}
bool isUnivalTree(struct TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	int val = root->val;
	return _isUnivalTree(root, val);
}

int maxDepth(struct TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	int size_l = maxDepth(root->left) + 1;
	int size_r = maxDepth(root->right) + 1;
	if (size_l > size_r)
	{
		return size_l;
	}
	return size_r;
}

void swap(TreeNode* root)
{
	if (root)
	{
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		swap(root->left);
		swap(root->right);
	}
}
struct TreeNode* invertTree(struct TreeNode* root){
	swap(root);
	return root;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL && q != NULL || p != NULL && q == NULL)
	{
		return false;
	}
	if (p->val != q->val)
	{
		return false;
	}
	return isSameTree(q->left, p->left) && isSameTree(p->right, q->right);
}

bool _isSymmetric(TreeNode* left, TreeNode* right)
{
	if (left == NULL && right == NULL)
	{
		return true;
	}
	if (left == NULL && right != NULL || left != NULL && right == NULL)
	{
		return false;
	}
	if (left->val != right->val)
	{
		return false;
	}
	return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
	{
		return true;
	}
	TreeNode* l = root->left;
	TreeNode* r = root->right;
	return _isSymmetric(l, r);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (s == NULL)
	{
		return false;
	}
	if (isSameTree(s, t) == 0)
	{
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
	else
	{
		return true;
	}
}

