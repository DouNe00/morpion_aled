#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "stack.h"
#include "displayFunctions.h"
#include "const.h"

void initBoard(WINDOW *field, Stack *board, int size, int num_elem);

void gameSettings(char *argv[], int *size, int *game_mode, int *earthquake);

void playGame(int size_board, int num_elem, int game_mode, int earthquake);

void moveAdd(int cursor_y, int cursor_x, int turn, Stack *board, int size_board, WINDOW *field);

void moveRemove(int cursor_y, int cursor_x, int turn, Stack *board, int size_board, WINDOW *field);

int checkWin(int size, int game_mode, Stack *board);

int coordToTile(int size_board, int cursor_y, int cursor_x);

#endif
