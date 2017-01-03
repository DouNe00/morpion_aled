#ifndef STACK_H_
#define STACK_H_

#define STACK_MAX 100

typedef struct {
    char  data[STACK_MAX];
    int  size;
} Stack;

void Stack_Init(Stack *S);
char Stack_Top(Stack *S);
void Stack_Push(Stack *S, char d);
void Stack_Pop(Stack *S);

#endif
