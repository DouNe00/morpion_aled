#ifndef DISPLAY_FUNCTIONS_H_
#define DISPLAY_FUNCTIONS_H_

#include<ncurses.h>
#include"const.h"
#include"stack.h"
#include"gameFunctions.h"

void initCurses(void);

void initWindowBorders(WINDOW *field, WINDOW *stack_content);

void displayGrid(WINDOW *field, int size);

void displayErrorEmpty(WINDOW *field);

void removeErrorEmpty(WINDOW *field);

void displayGameInfo(WINDOW *field, int size, int game_mode, int earthquake, int turn);

void updateCursor(WINDOW *field, Stack *board, int size, int ch, int *cursor_x, int *cursor_y);

void displayStackData(WINDOW *stack_window, int cursor_y, int cursor_x, Stack *board, int size);

#endif
