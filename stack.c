#include"stack.h"

void Stack_Init(Stack *S)
{
    S->size = 0;
    int i;
    for(i = 0; i < STACK_MAX; i++) {
      S->data[i] = EMPTY;
    }
}

int Stack_Top(Stack *S)
{
    if (S->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    }

    return S->data[S->size-1];
}

void Stack_Push(Stack *S, int c)
{
    if (S->size < STACK_MAX)
        S->data[S->size++] = c;
    else
        fprintf(stderr, "Error: stack full\n");
}

int Stack_Pop(Stack *S)
{
    if (S->size == 0) {
      fprintf(stderr, "Error: stack empty\n");
      return -1;
    }
    else  {
      int top = Stack_Top(S);
      S->data[--S->size] = EMPTY;
      return top;
    }

}
