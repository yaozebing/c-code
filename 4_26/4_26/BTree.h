#pragma once
#include"Stack_Queue.h"
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi) {
	if (a[*pi] != '#') {
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		(*pi)++;
		root->_left = BinaryTreeCreate(a, pi);
		(*pi)++;
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else {
		return NULL;
	}
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root) {
	if (*root) {
		BinaryTreeDestory(&((*root)->_left));
		BinaryTreeDestory(&((*root)->_right));
		free(*root);
		*root = NULL;
	}
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return NULL;
	}
	if (root->_left == NULL && root->_right == NULL) {
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	if (root == NULL) {
		return NULL;
	}
	if (root->_data == x) {
		return root;
	}
	BTNode* l = BinaryTreeFind(root->_left, x);
	BTNode* r = BinaryTreeFind(root->_right, x);
	if (l == NULL) {
		return r;
	}
	return l;
}
// 二叉树前序遍历 
void BinaryTreePrevOrderNor(BTNode* root) {
	Stack s;
	stackInit(&s, 100);
	BTNode* cur = root;
	BTNode* top;
	while (cur != NULL || stackEmpty(&s) != 1) {
		while (cur != NULL) {
			printf("%c ", cur->_data);
			stackPush(&s, cur);
			cur = cur->_left;
		}
		top = stackTop(&s);
		stackPop(&s);
		cur = top->_right;
	}
	printf("\n");
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root) {
	BTNode* cur = root;
	BTNode* top;
	Stack s;
	stackInit(&s, 100);
	if (root == NULL) {
		stackDestory(&s);
		return NULL;
	}
	while (cur != NULL || stackEmpty(&s) != 1) {
		while (cur != NULL) {
			//存入栈
			stackPush(&s, cur);
			cur = cur->_left;
		}
		//获取栈顶元素
		top = stackTop(&s);
		printf("%c ", top->_data);
		stackPop(&s);
		//访问右子树
		cur = top->_right;
	}
	printf("\n");
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root) {
	Stack s;
	stackInit(&s, 100);
	BTNode* prev = NULL;
	BTNode* cur = root;
	BTNode* top = NULL;
	while (cur != NULL || stackEmpty(&s) != 1) {
		while (cur != NULL) {
			//将节点入栈
			stackPush(&s, cur);
			cur = cur->_left;
		}
		top = stackTop(&s);
		if (prev == top->_right || top->_right == NULL) {
			printf("%c ", top->_data);
			prev = top;
			stackPop(&s);
		}
		else {
			cur = top->_right;
		}
	}
	printf("\n");
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root) {
	Queue q;
	queueInit(&q);
	BTNode* cur = root;
	queuePush(&q, cur);
	while (queueEmpty(&q) != 1) {
		cur = queueFront(&q);
		if (cur->_left != NULL) {
			queuePush(&q, cur->_left);
		}
		if (cur->_right != NULL) {
			queuePush(&q, cur->_right);
		}
		printf("%c ", cur->_data);
		queuePop(&q);
	}
	printf("\n");
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root) {
	Queue q;
	queueInit(&q);
	queuePush(&q, root);
	while (!queueEmpty(&q)) {
		BTNode* f = queueFront(&q);
		queuePop(&q);
		if (f != NULL) {
			queuePush(&q, f->_left);
			queuePush(&q, f->_right);
		}
		else {
			break;
		}
	}
	while (!queueEmpty(&q)) {
		BTNode* f = queueFront(&q);
		if (f) {
			return 0;
		}
		else {
			queuePop(&q);
		}
	}
	return 1;
}