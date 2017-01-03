#ifndef STACK_H_
#define STACK_H_

#include"const.h"
#include<stdio.h>

typedef struct {
    int  data[STACK_MAX];
    int  size;
} Stack;

void Stack_Init(Stack *S);
int Stack_Top(Stack *S);
void Stack_Push(Stack *S, int c);
int Stack_Pop(Stack *S);

#endif
