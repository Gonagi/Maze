#include <stdio.h>
#include "pos.h"
#include "stack.h"
#include "Windows.h"

#define MAX 4
#define PATH 0			// 지나갈 수 있는 위치
#define WALL 1			// 지나갈 수 없는 위치
#define vISITED 2		// 이미 방문한 위치
#define BACKTRACKED 3	// 방문했다가 되돌아 나온 위치

int Maze[MAX][MAX];
int Size;	// 미로의 크기

void Read_maze();
void Print_maze();
void Textcolor(int);	// 출력 글자 색 변경
enum ColorType { WHITE = 15, BLUE = 9, GREEN = 10, YELLOW = 14 }COLOR;	// 흰 파 초 노

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