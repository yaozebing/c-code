#include<stdio.h>
#include<string.h>
//int main()
//{
//	char* p = "abcdef";
//	printf("%d ", sizeof(p));
//	//4,p��һ��ָ�룬���ԣ�32λϵͳ�У�ָ�붼���ĸ��ֽ�
//	printf("%d ", sizeof(p + 1));
//	//4����ʱp+1ָ��ڶ���Ԫ�أ�������һ��ָ��
//	printf("%d ", sizeof(*p));
//	//1������ָ��p�����ݣ�ָ��ָ���ַ�����Ԫ�أ����ú���a
//	printf("%d ", sizeof(p[0]));
//	//1��C������ָ������������Ի���ת����p[0]����Ԫ��a��char��
//	printf("%d ", sizeof(&p));
//	//4,p��char*����ȡ��ַ����char**������ָ������Ϊ����ָ��
//	printf("%d ", sizeof(&p + 1));
//	//4,p��char*��ͬ�ϣ�char**��һ������ָ��
//	printf("%d ", sizeof(&p[0] + 1));
//	//4, �ȿ�p[0]������Ԫ�أ�ȡ��ַΪ��Ԫ��ָ�룬�ټ�һ�ǵڶ���Ԫ��ָ�룬ָ���ĸ��ֽ�
//
//	printf("%d ", strlen(p));
//	//6,p��char*���ͣ�ָ��һ���ַ���
//	printf("%d ", strlen(p + 1));
//	//5��ͬ�ϣ�����+1���ָ��ڶ���Ԫ����
//	printf("%d ", strlen(*p));
//	//UB��*p�õ�a��Ϊchar�ͣ�����ʽת����char*���ͣ����ʵ�ַΪ97�ķǷ��ڴ�
//	printf("%d ", strlen(p[0]));
//	//UB���õ�a�����ʷǷ��ڴ�
//	printf("%d ", strlen(&p));
//	//UB���õ�char**������strlen��ʼ��p�ĵ�ַ��ʼ��ȡ�ڴ�
//	printf("%d ", strlen(&p + 1));
//	//UB��ͬ��
//	printf("%d ", strlen(&p[0] + 1));
//	//5,&p[0]�õ���Ԫ��ָ�룬+1���ǵڶ���Ԫ��ָ��
//	return 0;
//}

int main()
{
	int a[3][4] = { 0 };
	//���Կ���һ��һά���飬������Ԫ�أ�ÿ��Ԫ����һ�����ĸ�Ԫ�ص�����
	printf("%d ", sizeof(a));
	//48,a����������
	printf("%d ", sizeof(a[0][0]));
	//4,a[0][0]�ǵ�һ��int��Ԫ��
	printf("%d ", sizeof(a[0]));
	//16,a[0]�ǵ�һ������Ԫ�أ��������ĸ�int�ͱ���
	printf("%d ", sizeof(a[0] + 1));
	//4,a[0]��int[4]�ͣ�+1��ʽת����int*�ͣ�ָ��ָ���һ�еڶ��е�Ԫ�أ�ָ�����ĸ��ֽ�
	printf("%d ", sizeof(*(a[0] + 1)));
	//4,a[0]��int[4]�ͣ�+1��ʽת����int*�ͣ�ָ��ָ���һ�еڶ��е�Ԫ�أ����ú���int�ͣ���СΪ�ĸ��ֽ�
	printf("%d ", sizeof(a + 1));
	//4,��ʽת����ָ��a[0][1]��ָ�룬ָ���С���ֽ�
	printf("%d ", sizeof(*(a + 1)));
	//4,��ʽת����ָ��a[0][1]��ָ�룬���ú���int�ͣ���СΪ4���ֽ�
	printf("%d ", sizeof(&a[0] + 1));
	//4,a[0]��int[4]�ͣ�����&a[0]������ָ�룬+1����Ȼ��ָ��
	printf("%d ", sizeof(*(&a[0] + 1)));
	//16,a[0]��int[4]�ͣ�����&a[0]������ָ�룬+1����Ȼ��ָ�룬ָ��ڶ���Ԫ��a[1]
	printf("%d ", sizeof(*a));
	//16,a��ʽת������ָ����Ԫ�ص�ָ�룬�ٽ��е���
	printf("%d ", sizeof(a[3]));
	//16,sizeof��һ�������������ʱ���Ѿ�������ֵ��������ʱ�൱��ִ����  printf("%d",16);
	printf("%d ", a[3]);
	//UB,��ʱԽ�����
	return 0;
}
