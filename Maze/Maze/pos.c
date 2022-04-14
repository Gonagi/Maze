#include "pos.h"
#include "stack.h"


Pos Move_to(Pos cur, int dir)
{
	
	switch (dir){
	case 0: cur.x++; break;	// ºÏ
	case 1: cur.y++; break;	// µ¿
	case 2: cur.x--; break;	// ³²
	case 3: cur.y--; break;	// ¼­
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
	case 0: cur.x++; break;	// ºÏ
	case 1: cur.y++; break;	// µ¿
	case 2: cur.x--; break;	// ³²
	case 3: cur.y--; break;	// ¼­
	}

	switch (Maze[cur.x][cur.y]) {
		case 0: case 2: case 3: return true;
		case 1: return false;
	}
}
