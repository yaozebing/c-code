/*
����˼·��
����������Ĺ����й���ÿһ���ڵ�
*/
#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>

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
		//��ǰ�ڵ�ǿգ��򴴽���ǰ�ڵ�
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = str[*pi];
		//�ַ�λ������ƶ�һ��λ��
		++(*pi);
		//����������
		root->_left = CreatBTree(str, pi);
		//�ַ�λ������ƶ�һ��λ��
		++(*pi);
		//����������
		root->_right = CreatBTree(str, pi);
		return root;
	}
	else
		return NULL;  //����ǿսڵ㣬�򷵻�NULL
}

int main()
{
	char str[101] = "asdhfmaufqfhsdmfhsdf";
	int i = 0;
	//�����ַ���
	//����������
	BTNode* root = CreatBTree(str, &i);
	//�����ӡ������
	Inorder(root);
	printf("\n");
	return 0;
}
