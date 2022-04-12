#include <stdio.h>
#include "pos.h"
#include "stack.h"
#include "Windows.h"

#define MAX 4
#define PATH 0			// ������ �� �ִ� ��ġ
#define WALL 1			// ������ �� ���� ��ġ
#define vISITED 2		// �̹� �湮�� ��ġ
#define BACKTRACKED 3	// �湮�ߴٰ� �ǵ��� ���� ��ġ

int Maze[MAX][MAX];
int Size;	// �̷��� ũ��

void Read_maze();
void Print_maze();
void Textcolor(int);	// ��� ���� �� ����
enum ColorType { WHITE = 15, BLUE = 9, GREEN = 10, YELLOW = 14 }COLOR;	// �� �� �� ��

int main()
{
	Read_maze();
	Print_maze();
	return 0;
}

void Read_maze()
{
	FILE* fp = NULL;
	fopen_s(&fp, "maze.txt", "r");

	if (fp == NULL) {
		printf("Error in Read_maze");
		exit(1);
	}

	for (int i = 0; i < MAX; i++) 
		for (int j = 0; j < MAX; j++)
			fscanf_s(fp, "%d", &Maze[i][j]);

	fclose(fp);
}

void Print_maze()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			printf("%d ", Maze[i][j]);
		printf("\n");
	}
}

void Textcolor(int colorNum)
{
	SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}