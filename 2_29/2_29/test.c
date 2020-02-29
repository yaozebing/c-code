#include<stdio.h>
#include<stdbool.h>
bool judge(int nums[4][4], int target)
{
	int x = 0;
	int y = 3;
	while (1)
	{
		if (target > nums[x][y] && x < 4)
		{
			x++;
		}
		else if (target < nums[x][y] &&y>0)
		{
			y--;
		}
		else if (target == nums[x][y])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	int nums[4][4] = { {1,2,3,4},{5,8,9,10},{9,10,11,12},{13,14,15,16} };
	int target = 7;
	int a = judge(nums, 7);
	printf("%d", a);
	return 0;
}