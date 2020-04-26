//#pragma once
//#include<stdio.h>
//#include<stdbool.h>

//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;		// ջ��
//	int _capacity;  // ���� 
//}Stack;
//// ��ʼ��ջ 
//void StackInit(Stack* ps)
//{
//	ps->_capacity = 100;//����ջ������
//	ps->_a = (STDataType*)malloc(ps->_capacity * sizeof(STDataType));//���������ռ�
//	ps->_top = 0;//��ջ�����ڳ�ʼλ��
//}
//// ��ջ 
//void StackPush(Stack* ps, STDataType data)
//{
//	if (ps->_top == ps->_capacity)
//	{
//		ps->_capacity += 100;
//		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
//		//STDataType* NewA = (STDataType*)malloc(sizeof(STDataType)*ps->_capacity);
//		//memcpy(NewA, ps->_a, ps->_capacity * sizeof(STDataType));
//		//free(ps->_a);
//		//ps->_a = NewA;
//	}
//	ps->_a[ps->_top] = data;
//	ps->_top++;
//}
//// ��ջ 
//void StackPop(Stack* ps)
//{
//	if (StackEmpty(ps))//�ж��Ƿ�Ϊ��
//	{
//		return 0;
//	}
//	else
//	{
//		ps->_a--;//��ջ��ǰ��
//	}
//}
//// ��ȡջ��Ԫ�� 
//STDataType StackPeek(Stack* ps)
//{
//	if (StackEmpty(ps))
//	{
//		return 0;
//	}
//	else
//	{
//		return ps->_a[ps->_top - 1];
//	}
//}
//// ��ȡջ����ЧԪ�ظ��� 
//int StackSize(Stack* ps)
//{
//	return sizeof(ps->_a) / sizeof(int);
//}
//// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
//int StackEmpty(Stack* ps)
//{
//	return ps->_top == 0;
//}
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//};
//
//typedef struct TreeNode TreeNode;
//
//int maxDepth(struct TreeNode* root) {
//	return root ? 1 + fmax(maxDepth(root->left), maxDepth(root->right)) : 0;
//}
//
//bool isBalanced(struct TreeNode* root) {
//	if (root == NULL){
//		return true;
//	}
//	int l = maxDepth(root->left);
//	int r = maxDepth(root->right);
//	return abs(l - r) < 2 && isBalanced(root->left) && isBalanced(root->right);
//}
//
//TreeNode* TreeCreate(char* root, int* pi) {
//	if (*root != '#') {
//
//	}
//}
////int main() {
////	char* str = (char*)malloc(sizeof(char) * 101);
////	scanf("%s", str);
////	int pi = 0;
////	TreeNode* root = TreeCreate(str, &pi);
////	Inorder(root);
////	return 0;
////}
//
//void Inorder(TreeNode* root)
//{
//	Stack s;
//	while (root == NULL || !StackEmpty(&s)) {
//		while (root != NULL) {
//			StackPush(&s, root);
//			root = root->left;
//		}
//		printf("%d", StackPeek(&s));
//		TreeNode* top = StackPeek(&s);
//		root = top->right;
//	}
//}

#include<stdio.h>
#include<malloc.h>
typedef struct BTNode {
	char _data;
	struct BTNode* _left;
	struct BTNode* _right;
}BTNode;

void Inorder(BTNode* root) 
{
	if (root) 
	{
		Inorder(root->_left);
		printf("%c ", root->_data);
		Inorder(root->_right);
	}
}
BTNode* CreateBTree(char* str, int* pi)
{
	if (str[*pi] != '#') 
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = str[*pi];
		++(*pi);
		root->_left = CreateBTree(str, pi);
		++(*pi);
		root->_right = CreateBTree(str, pi);
		return root;
	}
	else 
		return NULL;
}
int main() 
{
	char str[101];
	int i = 0;
	scanf("%s", str);
	//����������
	BTNode* root = CreateBTree(str, &i);
	//�����������
	Inorder(root);
	printf("\n");
	return 0;
}