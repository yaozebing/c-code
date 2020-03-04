#include<stdio.h>
#include<string.h>
//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d ",sizeof(a));
//	//16,一个int型变量4个字节，此时a是表示整个数组
//	printf("%d ", sizeof(a+0));
//	//4,数组是不能加数字的，此时a隐式转换成了指针，在32位系统中，指针都是4个字节;
//	printf("%d ", sizeof(*a));
//	//4,a是数组名，但同时也是首元素地址，此时a由数组隐式转换成了指向首元素的指针，再加*调用，就是第一个元素的字节大小
//	printf("%d ", sizeof(a + 1));
//	//4，数组是不能加数字的，此时a隐式转换成了指向第二个元素的指针，在32位系统中，指针都是4个字节
//	printf("%d ", sizeof(a[1]));
//	//4，a[1]是第二个元素大小
//	printf("%d ", sizeof(&a));
//	//4，此时&a是一个int(*)[4],即一个数组指针，32位系统下都是4个字节
//	printf("%d ", sizeof(*&a));
//	//16，&a是数组指针，加*调用后就是整个数组了，数组大小为16
//	printf("%d", sizeof(&a + 1));
//	//4，&a是一个int(*)[4],即一个数组指针，指针加一，仍然是一个指针，在32位系统中，指针都是4个字节
//	printf("%d", &a[0]);
//	//4,此时是一个int*的指针，4个字节
//	printf("%d", &a[0] + 1);
//	//4,此时是一个int*的指针，4个字节
//	return 0;
//}

//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	//注意此处是字符数组，不是字符串，字符串基于字符数组实现，是一个特殊的字符数组，以'\0'结尾
//	printf("%d ", sizeof(arr));
//	//6,求数组大小，一个char型一个字节，六个字符
//	printf("%d ", sizeof(arr + 0));
//	//4，数组是不能加数字的，但指针可以，此处数组名隐式转换成指针，在32位系统中，指针都是4个字节
//	printf("%d ", sizeof(*arr));
//	//1,数组隐式转换成指针，再进行调用，即首元素大小，char型一个字节
//	printf("%d ", sizeof(arr[1]));
//	//1,第二个元素大小
//	printf("%d ", sizeof(&arr));
//	//4,得到一个char(*)[6]数组指针,32位系统中，指针都是四个字节
//	printf("%d ", sizeof(*arr + 1));
//	//4,得到一个char(*)[6]数组指针,32位系统中，指针都是四个字节
//	printf("%d ", sizeof(&arr[0] + 1));
//	//4,得到一个char*指针，32位系统中，指针都是四个字节
//	
//	printf("%d ", strlen(arr));
//	//随机数，隐式转换成首元素地址，针对一个不是字符串的数组进行strlen操作（本质上因为数组下标访问越界），未定义行为（简称UB）
//	printf("%d ", strlen(arr + 0));
//	//随机数，隐式转换成首元素指针,UB
//	printf("%d ", strlen(*arr));
//	//随机数，arr是数组，无法调用，此时是隐式转换成了首元素指针，再进行调用后得到的是char型的a，a的ASCII码是97，strlen()把97当成一个地址进行访问，大概率无法访问（非法内存）
//	//代码中创建的变量，才是合法内存，除此之外，都是非法内存
//	//如果非法访问内存，则是UB
//	printf("%d ", strlen(arr[1]));
//	//UB，表示第二个元素，同上
//	printf("%d ", strlen(&arr));
//	//随机数，得到一个char(*)[6],字符指针，UB
//	printf("%d ", strlen(&arr + 1));
//	//随机数，得到一个char(*)[6],字符指针，+1后跳过整个数组
//	printf("%d ", strlen(&arr[0] + 1));
//	//UB，得到第二个元素指针，会访问非法内存
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	//此时arr表示的是字符串，末尾是有'\0'的
//	printf("%d ", sizeof(arr));
//	//7，sizeof求的内存大小，要包括'\0';
//	printf("%d ", sizeof(arr + 0));
//	//4,隐式转换成首元素指针，32位系统指针4字节
//	printf("%d ", sizeof(*arr));
//	//1，数组名不能调用，加*后arr隐式转换成首元素指针，调用后是'a',大小为一个字节
//	printf("%d ", sizeof(arr[1]));
//	//1,表示第二个元素，char型大小一字节
//	printf("%d ", sizeof(&arr));
//	//4,&arr表示char(*)[7],指针都是4字节
//	printf("%d ", sizeof(&arr + 1));
//	//4,&arr表示char(*)[7],+1后跳过整个数组，但指针都是四字节
//	printf("%d ", sizeof(&arr[0] + 1));
//	//4，&arr[0]表示的是首元素指针，+1后还是指针，指针四字节
//
//	printf("%d ", strlen(arr));
//	//6,arr为字符串，strlen()需要char*类型，隐式转换成指针，并读取字符串长度
//	printf("%d ", strlen(arr + 0));
//	//6,隐式转成指针，读取字符串长度
//	printf("%d", strlen(*arr));
//	//崩溃，*arr表示a，不是char*，UB，会读取非法内存
//	printf("%d", strlen(arr[1]));
//	//崩溃，得到b，原因同上
//	printf("%d", strlen(&arr));
//	//6，得到的是char(*)[7],是数组指针，碰巧数组指针位置和首元素指针位置一样
//	printf("%d", strlen(&arr + 1));
//	//随机数，得到的是char(*)[7],是数组指针，+1后跳过整个数组，传入的是字符串后的地址，UB
//	printf("%d", strlen(&arr[0] + 1));
//	//5，&arr[0]表示首元素指针，+1后是指向b的指针
//	return 0;
//}

int main()
{

}