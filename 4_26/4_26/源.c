#include"BTree.h"

int main() {
	char str[] = "abc##de#g##f###";
	int i = 0;
	BTNode* root = BinaryTreeCreate(str, &i);

	printf("preǰ��\n");
	BinaryTreePrevOrderNor(root);

	printf("in����\n");
	BinaryTreeInOrder(root);
	
	printf("post����\n");
	BinaryTreePostOrder(root);
	
	printf("����IO\n");
	BinaryTreeLevelOrder(root);

	
	i = BinaryTreeLeafSize(root);
	printf("��Ҷ�ӵ���Ϊ%d\n", i);

	i = BinaryTreeSize(root);
	printf("�ܽڵ���%d\n", i);

	printf("��g���в��ң��������ؽ�����\n");
	BTNode* f = BinaryTreeFind(root, 'g');
	printf("%c\n", f->_data);

	printf("�鿴�Ƿ�Ϊ��ȫ���������Ǵ�ӡ1�����Ǵ�ӡ0\n");
	i = BinaryTreeComplete(root);
	printf("%d\n", i);

	BinaryTreeDestory(&root);
	BinaryTreePrevOrderNor(root);

	return 0;
}