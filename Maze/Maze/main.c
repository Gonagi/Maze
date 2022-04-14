#include <stdio.h>
#include <Windows.h>
#include "pos.h"
#include "stack.h"

#define MAX 3
#define PATH 0			// 지나갈 수 있는 위치			// 초록
#define WALL 1			// 지나갈 수 없는 위치			// 빨강
#define VISITED 2		// 이미 방문한 위치				// 노랑
#define BACKTRACKED 3	// 방문했다가 되돌아 나온 위치		// 파랑

int Size;	// 미로의 크기

void Read_maze();
void Print_maze();
void Textcolor(int, int);   // 출력 글자 색 변경
enum ColorType { WHITE = 15, BLACK = 0, RED = 4, BLUE = 9, GREEN = 10, YELLOW = 14 }COLOR;    // 흰 검 파 초 노


int main()
{
	Stack stack = Create_stacK();
	Pos cur;	// 현재 위치
	cur.x = 0;
	cur.y = 0;
	
	Read_maze();
	while (1) {
		Maze[cur.x][cur.y] = VISITED;
		if (cur.x == MAX - 1 && cur.y == MAX - 1) {	// 출구
			printf("Found the path.\n");
			break;
		}
		
		bool forwarded = false;
		for (int dir = 0; dir < 4; dir++) {
			if (Movable(cur, dir)) {
				Push(stack, cur);
				cur = Move_to(cur, dir);
				forwarded = true;
				break;
			}
		}
		if (!forwarded) {
			Maze[cur.x][cur.y] = BACKTRACKED;
			if (Is_empty(stack)) {
				printf("No path exists.\n");
				break;
			}
			cur = Pop(stack);
		}
	}
	Print_maze();
	return 0; 
}

void Read_maze()
{
	FILE* fp = NULL;
	fopen_s(&fp, "test.txt", "r");

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
			case 0: Textcolor(BLACK, GREEN); printf("□"); break;
			case 1: Textcolor(BLACK, RED); printf("□"); break;
			case 2: Textcolor(BLACK, YELLOW); printf("□"); break;
			case 3: Textcolor(BLACK, BLUE); printf("□"); break;
			}
			// printf("%d ", Maze[i][j]);
		}
		printf("\n");
	}
	Textcolor(WHITE, BLACK);
}

void Textcolor(int forground, int background)
{
	int color = forground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}