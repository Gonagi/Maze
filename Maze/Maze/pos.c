#include "pos.h"
#include "stack.h"


Pos Move_to(Pos cur, int dir)
{
	switch (dir){
		case 0: cur.x--; break;	// 북
		case 1: cur.y++; break;	// 동
		case 2: cur.x++; break;	// 남
		case 3: cur.y--; break;	// 서	
	}
	if (cur.x < 0 || cur.y < 0 || cur.x >= MAX || cur.y >= MAX)	// 미로 범위 넘어서면
		terminate("Error in Move_to.");

	return cur;
}

bool Movable(Pos cur, int dir)
{
	switch (dir) {
		case 0: cur.x--; break;	// 북
		case 1: cur.y++; break;	// 동
		case 2: cur.x++; break;	// 남
		case 3: cur.y--; break;	// 서
	}

	if (cur.x < 0 || cur.y < 0 || cur.x >= MAX || cur.y >= MAX || Maze[cur.x][cur.y] != 0) {
		// 미로 범위 넘어서거나 갈 수 없는 길 (1 2 3)
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

	if(Maze[cur.x][cur.y] == 0)	// 갈 수 있는 길 (초록 0 )이라면
		switch (Maze[cur.x][cur.y]) {
			case 0: return true;	// 초록
			case 1: case 2:	case 3: return false;	// 빨강 노랑 파랑
	}
}
