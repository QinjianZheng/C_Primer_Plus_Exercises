#ifndef STACK_H__
#define STACK_H__

#include "list.h"

typedef List Stack;

void InitializeStack(Stack *);
bool StackIsEmpty(Stack *);
bool StackIsFull(Stack *);
bool Push(Item, Stack *);
bool Pop(Item * , Stack *);


#endif

