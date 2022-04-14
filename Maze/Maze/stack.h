#ifndef STACK_H
#define STACK_H

#endif
#include <stdio.h>
#include <stdlib.h>		//EXIT_FAILURE
#include <stdbool.h>	// bool
#include "pos.h"

typedef int Item;
typedef struct node* Node;
typedef struct stack* Stack;

Node Create_node();
Stack Create_stacK();
bool Is_empty(Stack);
void Push(Stack, Pos);
Pos Peek(Stack);
Pos Pop(Stack);
void Remove_node(Node);
void Remove_stack(Stack);
void Print_stack(Stack);
void terminate(char*);