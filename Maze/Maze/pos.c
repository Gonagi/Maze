#include "pos.h"
#include "stack.h"


Pos Move_to(Pos cur, int dir)
{
	
	switch (dir){
	case 0: cur.x++; break;	// ��
	case 1: cur.y++; break;	// ��
	case 2: cur.x--; break;	// ��
	case 3: cur.y--; break;	// ��
	}
	return cur;
	
	//Pos next;
	//next.x = cur.x + offset[dir][0];
	//next.y = cur.y + offset[dir][1];

	//return next;
}

bool Movable(Pos cur, int dir)
{
	switch (dir) {
	case 0: cur.x++; break;	// ��
	case 1: cur.y++; break;	// ��
	case 2: cur.x--; break;	// ��
	case 3: cur.y--; break;	// ��
	}

	switch (Maze[cur.x][cur.y]) {
		case 0: case 2: case 3: return true;
		case 1: return false;
	}
}
