#include "pos.h"
#include "stack.h"


Pos Move_to(Pos cur, int dir)
{
	switch (dir){
		case 0: cur.x--; break;	// ��
		case 1: cur.y++; break;	// ��
		case 2: cur.x++; break;	// ��
		case 3: cur.y--; break;	// ��	
	}
	if (cur.x < 0 || cur.y < 0 || cur.x >= MAX || cur.y >= MAX)	// �̷� ���� �Ѿ��
		terminate("Error in Move_to.");

	return cur;
}

bool Movable(Pos cur, int dir)
{
	switch (dir) {
		case 0: cur.x--; break;	// ��
		case 1: cur.y++; break;	// ��
		case 2: cur.x++; break;	// ��
		case 3: cur.y--; break;	// ��
	}

	if (cur.x < 0 || cur.y < 0 || cur.x >= MAX || cur.y >= MAX || Maze[cur.x][cur.y] != 0) {
		// �̷� ���� �Ѿ�ų� �� �� ���� �� (1 2 3)
		if (cur.x == MAX)
			cur.x--;
		else if (cur.x < 0)
			cur.x++;
		else if (cur.y == MAX)
			cur.y--;
		else if (cur.y < 0)
			cur.y++;

		return false;
	}

	if(Maze[cur.x][cur.y] == 0)	// �� �� �ִ� �� (�ʷ� 0 )�̶��
		switch (Maze[cur.x][cur.y]) {
			case 0: return true;	// �ʷ�
			case 1: case 2:	case 3: return false;	// ���� ��� �Ķ�
	}
}
