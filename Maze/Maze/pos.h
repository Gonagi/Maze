#pragma once
#define HAVE_STRUCT_MOVE_TO

#include <stdio.h>
#include <stdbool.h>
#define MAX 16

int Maze[MAX][MAX];

typedef struct position {
	int x, y;
}Pos;

Pos Move_to(Pos, int);
bool Movable(Pos, int);

