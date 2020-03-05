#include<stdio.h>
#include<string.h>
//int main()
//{
//	char* p = "abcdef";
//	printf("%d ", sizeof(p));
//	//4,p是一个指针，所以，32位系统中，指针都是四个字节
//	printf("%d ", sizeof(p + 1));
//	//4，此时p+1指向第二个元素，依旧是一个指针
//	printf("%d ", sizeof(*p));
//	//1，调用指针p的内容，指针指向字符串首元素，调用后是a
//	printf("%d ", sizeof(p[0]));
//	//1，C语言中指针和数组名可以互相转换，p[0]是首元素a，char型
//	printf("%d ", sizeof(&p));
//	//4,p是char*，再取地址就是char**，二级指针依旧为二级指针
//	printf("%d ", sizeof(&p + 1));
//	//4,p是char*，同上，char**加一，依旧指针
//	printf("%d ", sizeof(&p[0] + 1));
//	//4, 先看p[0]，是首元素，取地址为首元素指针，再加一是第二个元素指针，指针四个字节
//
//	printf("%d ", strlen(p));
//	//6,p是char*类型，指向一个字符串
//	printf("%d ", strlen(p + 1));
//	//5，同上，但是+1后就指向第二个元素了
//	printf("%d ", strlen(*p));
//	//UB，*p得到a，为char型，又隐式转换成char*类型，访问地址为97的非法内存
//	printf("%d ", strlen(p[0]));
//	//UB，得到a，访问非法内存
//	printf("%d ", strlen(&p));
//	//UB，得到char**，于是strlen开始从p的地址开始读取内存
//	printf("%d ", strlen(&p + 1));
//	//UB，同上
//	printf("%d ", strlen(&p[0] + 1));
//	//5,&p[0]得到首元素指针，+1后是第二个元素指针
//	return 0;
//}

int main()
{
	int a[3][4] = { 0 };
	//可以看成一个一维数组，有三个元素，每个元素是一个有四个元素的数组
	printf("%d ", sizeof(a));
	//48,a是整个数组
	printf("%d ", sizeof(a[0][0]));
	//4,a[0][0]是第一个int型元素
	printf("%d ", sizeof(a[0]));
	//16,a[0]是第一个数组元素，里面有四个int型变量
	printf("%d ", sizeof(a[0] + 1));
	//4,a[0]是int[4]型，+1隐式转换成int*型，指针指向第一行第二列的元素，指针是四个字节
	printf("%d ", sizeof(*(a[0] + 1)));
	//4,a[0]是int[4]型，+1隐式转换成int*型，指针指向第一行第二列的元素，调用后是int型，大小为四个字节
	printf("%d ", sizeof(a + 1));
	//4,隐式转换成指向a[0][1]的指针，指针大小四字节
	printf("%d ", sizeof(*(a + 1)));
	//4,隐式转换成指向a[0][1]的指针，调用后是int型，大小为4个字节
	printf("%d ", sizeof(&a[0] + 1));
	//4,a[0]是int[4]型，所以&a[0]是数组指针，+1后仍然是指针
	printf("%d ", sizeof(*(&a[0] + 1)));
	//16,a[0]是int[4]型，所以&a[0]是数组指针，+1后仍然是指针，指向第二个元素a[1]
	printf("%d ", sizeof(*a));
	//16,a隐式转换成了指向首元素的指针，再进行调用
	printf("%d ", sizeof(a[3]));
	//16,sizeof是一个运算符，编译时就已经推理出值，在运行时相当于执行了  printf("%d",16);
	printf("%d ", a[3]);
	//UB,此时越界访问
	return 0;
}

