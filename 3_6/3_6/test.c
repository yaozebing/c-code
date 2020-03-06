#include<stdio.h>
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int *ptr = (int*)(&a + 1);
//	//a隐式转换成了数组指针，+1指针指向末尾元素的后一个字节，再强制转换成int*指针
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	//2，5，数组是不能+1的，于是隐式转换成int*型，+1后成为一个指针指向第二个元素的指针
//	return 0;
//}

//struct Test
//{
//	int Num;
//	char *pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//};
//
// 
//int main()
//{
//	struct Test *p = (struct Test*)0x100000;
//	//假设p 的值为0x100000
//	//%p:打印一个指针变量的内容（地址），习惯上都是用16进制表示的
//	printf("%p ", p + 0x1);
//	//此时p + 0x1相当于p + 1，p是一个结构体指针， + 0x1后相当于跳过了一个结构体大小的字节数，所以跳过20个字节，因为p的地址已经假设成0x100000，是十六进制，再加20不是0x100020，而是100014
//	printf("%p ", (unsigned long)p + 0x1);
//	//强制转换使p由一个指针变成了一个单纯的整数100000，再加一就是100001
//	printf("%p ", (unsigned int*)p + 0x1);
//	//强制转换使p由结构体指针struct Test*变成一个int*型指针，+1后跳过的是一个int*型指针大小的字节，所以是100004
//	return 0;
//}

int main()
{
	int a[4] = { 1,2,3,4 };
	int *ptr1 = (int*)(&a + 1);
	//&a为数组指针int(*)[4],+1后指向数组末尾元素的下一个字节，强制转换成int*，所以p是一个int*型
	int *ptr2 = (int*)((int)a + 1);
	//a本来是数组名，但数组名和指针可以隐式转换，所以此时就是把指针强制转换成int型变量，
	printf("%x ", ptr1[-1]);
	//4，数组的下标是不可以为负的，但是指针运算可以，此时ptr[-1]=>*（ptr-1），ptr本来指向末尾元素的下一个字节，-1后指向了4，以十六进制输出后依旧为4
	printf("%x ", *ptr2);
	//2000000，
	return 0;
}