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
//	// ���ѣ� �����һ����Ҷ�ӽڵ㿪ʼ���е���
//	// ���һ����Ҷ�ӽڵ㣬���չ��� �����һ��λ������ - 1�� / 2
//	// ���һ��λ�������� n - 1
//	// �����һ����Ҷ�ӽڵ�λ�ã� (n - 2) / 2
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
//		// ѡ���Һ�ֽ�д��һ��
//		if (child + 1 < n
//			&& a[child + 1] > a[child])
//		{
//			++child;
//		}
//
//		//������Ӵ��ڸ��ף����е������� 
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