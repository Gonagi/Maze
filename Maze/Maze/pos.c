#include "pos.h"
#include "stack.h"


Pos Move_to(Pos cur, int dir)
{
	
	switch (dir){
		case 0: cur.x--; break;	// ºÏ
		case 1: cur.y--; break;	// µ¿
		case 2: cur.x++; break;	// ³²
		case 3: cur.y++; break;	// ¼­	
	}
	if (cur.x < 0 || cur.y < 0) {
		printf("Error in Move_to.\n");
		exit(1);
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
		case 0: cur.x--; break;	// ºÏ
		case 1: cur.y--; break;	// µ¿
		case 2: cur.x++; break;	// ³²
		case 3: cur.y++; break;	// ¼­
	}

	if (cur.x < 0 || cur.y < 0)
		return false;

	switch (Maze[cur.x][cur.y]) {
		case 0: return true;
		case 1:case 2: case 3: return false;
	}
}
