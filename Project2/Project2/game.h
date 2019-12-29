#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY 10

void InitBoard(char board[ROWS][COLS], int  rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetBoard(char board[ROWS][COLS], int row, int col);
void CheckBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
