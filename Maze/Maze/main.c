#include <stdio.h>
#include "pos.h"
#include "stack.h"
#include "Windows.h"

#define MAX 100
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

	return 0;
}

void Read_maze()
{

}

void Print_maze()
{

}

void Textcolor(int colorNum)
{
	SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}