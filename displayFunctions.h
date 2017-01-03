#ifndef DISPLAY_FUNCTIONS_H_
#define DISPLAY_FUNCTIONS_H_

#include<ncurses.h>
#include"const.h"
#include"stack.h"

void initCurses(void);

void initWindowBorders(WINDOW *field, WINDOW *stack_content);

void displayGrid(WINDOW *field, int size);

void updateCursor(WINDOW *field, Stack *board, int size, int ch, int *cursor_x, int *cursor_y);

#endif
