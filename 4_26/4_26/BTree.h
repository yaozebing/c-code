#pragma once
#include"Stack_Queue.h"
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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
// ����������
void BinaryTreeDestory(BTNode** root) {
	if (*root) {
		BinaryTreeDestory(&((*root)->_left));
		BinaryTreeDestory(&((*root)->_right));
		free(*root);
		*root = NULL;
	}
}
// �������ڵ����
int BinaryTreeSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return NULL;
	}
	if (root->_left == NULL && root->_right == NULL) {
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// ����������ֵΪx�Ľڵ�
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
// ������ǰ����� 
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
// �������������
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
			//����ջ
			stackPush(&s, cur);
			cur = cur->_left;
		}
		//��ȡջ��Ԫ��
		top = stackTop(&s);
		printf("%c ", top->_data);
		stackPop(&s);
		//����������
		cur = top->_right;
	}
	printf("\n");
}
// �������������
void BinaryTreePostOrder(BTNode* root) {
	Stack s;
	stackInit(&s, 100);
	BTNode* prev = NULL;
	BTNode* cur = root;
	BTNode* top = NULL;
	while (cur != NULL || stackEmpty(&s) != 1) {
		while (cur != NULL) {
			//���ڵ���ջ
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
// �������
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
// �ж϶������Ƿ�����ȫ������
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