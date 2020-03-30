#include"slist.h"

int main()
{
	SListNode* plist;
	plist = NULL;
	//SListPrint(plist);

	SListPushBack(&plist, 5);
	SListPrint(plist);
	SListPushBack(&plist, 6);
	SListPrint(plist);
	SListPushBack(&plist, 7);
	SListPrint(plist);

	SListPushFront(&plist, 3);
	SListPrint(plist);
	SListPushFront(&plist, 2);
	SListPrint(plist);
	SListPushFront(&plist, 1);
	SListPrint(plist);

	//SListPopBack(&plist);
	//SListPrint(plist);
	//SListPopBack(&plist);
	//SListPrint(plist);

	//SListPopFront(&plist);
	//SListPrint(plist);
	//SListPopFront(&plist);
	//SListPrint(plist);

	//SListFind(plist, 3);
	//SListFind(plist, 6);
	//SListFind(plist, 9);

	//SListNode* cur = SListFind(plist, 3);
	//
	//SListInsertAfter(cur, 4);
	//SListPrint(plist);

	//SListEraseAfter(cur);
	//SListPrint(plist);
	//SListEraseAfter(cur);
	//SListPrint(plist);
	//SListEraseAfter(cur);
	//SListPrint(plist);

	//SListDestory(plist);
	return 0;
}
