#include"game.h"
void menu()
{
	printf("*********************\n");
	printf("******* 1.game ******\n");
	printf("******  0.over ******\n");
	printf("*********************\n");
}
void game()
{
	srand((unsigned)time(NULL));
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	SetBoard(mine, ROW, COL);
	CheckBoard(mine, show, ROW, COL);
}
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("input choice:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("over\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("input wrong\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}