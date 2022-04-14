#ifndef __POS_H__
#define __POS_H__

typedef struct position {
	int x, y;
}Pos;

#endif

#include <stdio.h>
#include <stdbool.h>
#define MAX 16	//

int Maze[MAX][MAX];

Pos Move_to(Pos, int);
bool Movable(Pos, int);