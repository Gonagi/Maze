#include <stdio.h>
#include <Windows.h>
#include "pos.h"
#include "stack.h"

#define MAX 16
#define PATH 0			// ������ �� �ִ� ��ġ			// �ʷ�
#define WALL 1			// ������ �� ���� ��ġ			// ����
#define vISITED 2		// �̹� �湮�� ��ġ				// ���
#define BACKTRACKED 3	// �湮�ߴٰ� �ǵ��� ���� ��ġ		// �Ķ�

int Maze[MAX][MAX];
int Size;	// �̷��� ũ��

void Read_maze();
void Print_maze();
void Textcolor(int, int);	// ��� ���� �� ����
enum ColorType { WHITE = 15, BLACK = 0, RED = 4, BLUE = 9, GREEN = 10, YELLOW = 14}COLOR;	// �� �� �� ��

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
		for (int j = 0; j < MAX; j++) {
			switch (Maze[i][j]) {
			case 0: Textcolor(BLACK, GREEN); printf("��"); break;
			case 1: Textcolor(BLACK, RED); printf("��"); break;
			case 2: Textcolor(BLACK, YELLOW); printf("��"); break;
			case 3: Textcolor(BLACK, BLUE); printf("��"); break;
			}
		}
		printf("\n");
	}
	Textcolor(WHITE, BLACK);
	printf("aaa");
}

void Textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}