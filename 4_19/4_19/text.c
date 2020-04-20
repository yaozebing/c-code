//#include"Heap.h"
//void HeapInit(Heap* hp, HPDataType* a, int n)
//{
//	int i;
//	assert(hp && a);
//	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
//	hp->_size = n;
//	hp->_capacity = n;
//
//	for (i = 0; i < n; ++i)
//	{
//		hp->_a[i] = a[i];
//	}
//
//	// 建堆： 从最后一个非叶子节点开始进行调整
//	// 最后一个非叶子节点，按照规则： （最后一个位置索引 - 1） / 2
//	// 最后一个位置索引： n - 1
//	// 故最后一个非叶子节点位置： (n - 2) / 2
//	for (i = (n - 2) / 2; i >= 0; --i)
//	{
//		AdjustDown(hp->_a, hp->_size, i);
//	}
//}
//void AdjustDown(HPDataType* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		// 选左右孩纸中大的一个
//		if (child + 1 < n
//			&& a[child + 1] > a[child])
//		{
//			++child;
//		}
//
//		//如果孩子大于父亲，进行调整交换 
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}