#include"BTree.h"

int main() {
	char str[] = "abc##de#g##f###";
	int i = 0;
	BTNode* root = BinaryTreeCreate(str, &i);

	printf("pre前序\n");
	BinaryTreePrevOrderNor(root);

	printf("in中序\n");
	BinaryTreeInOrder(root);
	
	printf("post后序\n");
	BinaryTreePostOrder(root);
	
	printf("层序IO\n");
	BinaryTreeLevelOrder(root);

	
	i = BinaryTreeLeafSize(root);
	printf("节叶子点数为%d\n", i);

	i = BinaryTreeSize(root);
	printf("总节点数%d\n", i);

	printf("对g进行查找，并将返回结果输出\n");
	BTNode* f = BinaryTreeFind(root, 'g');
	printf("%c\n", f->_data);

	printf("查看是否为完全二叉树，是打印1，不是打印0\n");
	i = BinaryTreeComplete(root);
	printf("%d\n", i);

	BinaryTreeDestory(&root);
	BinaryTreePrevOrderNor(root);

	return 0;
}