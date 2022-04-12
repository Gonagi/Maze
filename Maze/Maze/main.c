#include <stdio.h>
#include <Windows.h>
#include "pos.h"
#include "stack.h"

#define MAX 4
#define PATH 0			// 지나갈 수 있는 위치			// 초록
#define WALL 1			// 지나갈 수 없는 위치			// 빨강
#define vISITED 2		// 이미 방문한 위치				// 노랑
#define BACKTRACKED 3	// 방문했다가 되돌아 나온 위치		// 파랑

int Maze[MAX][MAX];
int Size;	// 미로의 크기

void Read_maze();
void Print_maze();
void Textcolor(int);	// 출력 글자 색 변경
enum ColorType { RED = 4*16, BLUE = 9*16, GREEN = 10*16, YELLOW = 14*16 }COLOR;	// 흰 파 초 노

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
			case 0: Textcolor(GREEN); printf("□"); break;
			case 1: Textcolor(RED); printf("□"); break;
			case 2: Textcolor(YELLOW); printf(" "); break;
			case 3: Textcolor(BLUE); printf(" "); break;
			}
			// printf("%d ", Maze[i][j]);
		}
		printf("\n");
	}
}

void Textcolor(int colorNum)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
	//SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}