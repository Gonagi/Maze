#include "stack.h"
#include "pos.c"

struct node {
	Item x, y;
	Node next;
};

struct stack {
	Node top;
};

Node Create_node()
{
	Node new_node = (Node)malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Error in Create_node : node could not be created.");
	new_node->x = NULL;
	new_node->y = NULL;
	new_node->next = NULL;

	return new_node;
}

Stack Create_stacK()
{
	Stack new_stack = (Stack)malloc(sizeof(struct stack));
	if (new_stack == NULL)
		terminate("Error in create_stack : stack oould not be created.");
	new_stack->top = NULL;

	return new_stack;
}

bool Is_empty(Stack stack)
{
	return stack->top == NULL;
}

void Push(Stack stack, Pos cur)
{
	Node new_node = Create_node();
	new_node->x = cur.x;
	new_node->y = cur.y;

	if (Is_empty(stack))
		stack->top = new_node;

	else {
		new_node->next = stack->top;
		stack->top = new_node;
	}
}

Pos Peek(Stack stack)
{
	if (Is_empty(stack))
		terminate("Error in Peek : Stack is empty.");

	Pos cur;
	cur.x = stack->top->x;
	cur.y = stack->top->y;

	return cur;
}

Pos Pop(Stack stack)
{
	if (Is_empty(stack))
		terminate("Error in Pop : Stack is empty.");
	Node old_node = stack->top;
	Pos old_cur;
	old_cur.x = old_node->x;
	old_cur.y = old_node->y;

	stack->top = old_node->next;

	Remove_node(old_node);
	if (Is_empty(stack))
		Remove_stack(stack);

	return old_cur;
}

void Remove_node(Node old_node)
{
	free(old_node);
	old_node->x = NULL;
	old_node->y = NULL;
	old_node->next = NULL;
}

void Remove_stack(Stack stack)
{
	free(stack);
	stack->top = NULL;
}

void Print_stack(Stack stack)
{
	if (Is_empty(stack))
		printf("stack is empty.\n");
	else {
		Node node = stack->top;

		printf("Stack : ");
		while (node != NULL) {
			printf("(%d, %d)", node->x, node->y);
			node = node->next;

			if (node == NULL)
				printf("\n\n");
			else
				printf(" --> ");
		}
	}
}

void terminate(char* message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}