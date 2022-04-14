#include <stdio.h>
#include <Windows.h>
#include "pos.h"
#include "stack.h"

#define MAX 3
#define PATH 0			// ������ �� �ִ� ��ġ			// �ʷ�
#define WALL 1			// ������ �� ���� ��ġ			// ����
#define VISITED 2		// �̹� �湮�� ��ġ				// ���
#define BACKTRACKED 3	// �湮�ߴٰ� �ǵ��� ���� ��ġ		// �Ķ�

int Size;	// �̷��� ũ��

void Read_maze();
void Print_maze();
void Textcolor(int, int);   // ��� ���� �� ����
enum ColorType { WHITE = 15, BLACK = 0, RED = 4, BLUE = 9, GREEN = 10, YELLOW = 14 }COLOR;    // �� �� �� �� ��


int main()
{
	Stack stack = Create_stacK();
	Pos cur;	// ���� ��ġ
	cur.x = 0;
	cur.y = 0;
	
	Read_maze();
	while (1) {
		Maze[cur.x][cur.y] = VISITED;
		if (cur.x == MAX - 1 && cur.y == MAX - 1) {	// �ⱸ
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
			case 0: Textcolor(BLACK, GREEN); printf("��"); break;
			case 1: Textcolor(BLACK, RED); printf("��"); break;
			case 2: Textcolor(BLACK, YELLOW); printf("��"); break;
			case 3: Textcolor(BLACK, BLUE); printf("��"); break;
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