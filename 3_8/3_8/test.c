#include<stdio.h>
char* my_strcat(char* des, const char* sou)
{
	if (des == NULL || sou == NULL)
	{
		return NULL;
	}//��鴫���ָ���Ƿ�Ϊ��
	char* p = des;//����ֻ��Ϊ���޸�desָ������ָ�򣬴���ʱ����Ҫ��des������
	while (*des != '\0')
	{
		des++;
	}//��des��ָ�����������Ԫ��������ĩβ'\0'��֮��ĸ�ֵ���Ŀ�������'\0'����
	while (*sou != '\0')
	{
		*des = *sou;
		des++;
		sou++;
	}//��souָ���ֵ����desָ��������������
	*des = '\0';//��'\0'����desָ�������
	return p;//���ص���des�����λ��
}
char* my_strcpy(char* des, const char* sou)
{
	if (des == NULL || sou == NULL)
	{
		return NULL;
	}//��鴫���ָ���Ƿ�Ϊ��
	char* p = des;//����ֻ��Ϊ���޸�desָ������ָ�򣬴���ʱ����Ҫ��des������
	while (*sou != '\0')
	{
		*des = *sou;
		des++;
		sou++;
	}//��souָ��Ԫ�ظ���desָ������
	//��ʱdesָ�����souָ���ַ�����ĩβλ�ã�����û��'\0'
	*des = '\0';//��'\0'����desָ�������
	return p;//���ص���des�����λ��
}
size_t my_strlen(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}//��鴫���ָ���Ƿ�Ϊ��
	int num = 0;
	while (*str != '\0')
	{
		num++;
		str++;
	}
	return num;
}
int main()
{
	char str1[100] = "haha";
	char str2[100] = "hehe";
	int num = 10;
	int num2 = 0;
	
	
	int* const p = num;
	//��������ָ���ָ���ܸĶ���ָ���д���ڴ��ַ���ܸı䣩
	const int* p = num;
	int const* p = num;
	//����������pָ����ڴ�ռ䲻�ܱ��޸�
	
	//p = &num2;
	//*p = num2;

	return 0;
}