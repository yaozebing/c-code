#include"game.h"

void InitBoard(char board[ROWS][COLS], int  rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}	
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------------------------");
	printf("\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------------------------");
	printf("\n");
}
void SetBoard(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int num = EASY;
	while (num)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			num--;
		}
	}
}
int AroundNum(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x][y - 1] + mine[x - 1][y] +
		mine[x + 1][y + 1] + mine[x][y + 1] + mine[x + 1][y] +
		mine[x - 1][y + 1] + mine[x + 1][y - 1] - 8 * mine[x][y];
}
void ZeroLine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
    int ret = 0;
    ret = AroundNum(mine, x, y);
	if (x >= 0 && y >= 0 && x < ROWS && y < COLS)
		{
			if (ret == 0)
			{
				show[x][y] = ' ';
				if (mine[x][y + 1] == '0' && show[x][y + 1] == '*')
				{
					ZeroLine(mine, show, x, y + 1);
				}
				if (mine[x][y - 1] == '0' && show[x][y - 1] == '*')
				{
					ZeroLine(mine, show, x, y - 1);
				}
				if (mine[x - 1][y] == '0' && show[x - 1][y] == '*')
				{
					ZeroLine(mine, show, x - 1, y);
				}
				if (mine[x + 1][y] == '0' && show[x + 1][y] == '*')
				{
					ZeroLine(mine, show, x + 1, y);
				}
				if (mine[x + 1][y + 1] == '0' && show[x + 1][y + 1] == '*')
				{
					ZeroLine(mine, show, x + 1, y + 1);
				}
				if (mine[x - 1][y - 1] == '0' && show[x - 1][y - 1] == '*')
				{
					ZeroLine(mine, show, x - 1, y - 1);
				}				
				if (mine[x + 1][y - 1] == '0' && show[x + 1][y - 1] == '*')
				{
					ZeroLine(mine, show, x + 1, y - 1);
				}
				if (mine[x - 1][y + 1] == '0' && show[x - 1][y - 1] == '*')
				{
					ZeroLine(mine, show, x - 1, y + 1);
				}
			}
			else
			{
				show[x][y] = ret + '0';
			}
		}
}
void CheckBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int ret = 0;
	int x = 0;
	int y = 0;
	int num = 0;
	while (ret < ROW*COL - EASY)
	{
		printf("输入排查坐标\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("炸死\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
			    ZeroLine(mine, show, x, y);
				DisplayBoard(show, row, col);
				ret++;
			}
		}
		else
		{
			printf("input wrong\n");
		}
	}
	if (ret == ROW * COL - EASY)
	{
		printf("胜利\n");
	}
}


