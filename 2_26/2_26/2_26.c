#define _CRT_SECURE_NO_WARNINGS_

//#include<stdio.h>
//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d ,%d", a + b, c);
//	return 0;
//}

#include<stdio.h>
int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (a = 0; a < 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((b == 2) + (a == 3)) == 1 && 
							((b == 2) + (e == 4)) == 1 && 
							((c == 1) + (d == 2)) == 1 && 
							((c == 5) + (d == 3)) == 1 && 
							((e == 4) + (a == 1) == 1))
						{
							if (120 == (a*b*c*d*e))
							{
								printf("%d %d %d %d %d ", a, b, c, d, e );
							}
						}
					}
				}
			}
		}
	}
	return 0;
}