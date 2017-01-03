#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include"stack.h"

#define EMPTY '-'
#define PLAYER_1 'O'
#define PLAYER_2 'X'

#define tile_width 4
#define tile_height 2

void initBoard(WINDOW *field, Stack *board, int size, int num_elem);
void initCurses(void);
void initWindow(WINDOW *field, WINDOW *stack_content);
void updateBoard(WINDOW *field, Stack *board, int size, int ch, int *turn, int *cursor_x, int *cursor_y);

int main(int argc, char *argv[]) {
	int size_board, num_elem;

	if(argc != 2)
	{
		printf("Usage : %s <size of the board>\n",argv[0]);
		exit(1);
	}

	size_board = atoi(argv[1]);
	num_elem = size_board * size_board;

	Stack boardData[num_elem];

	initCurses();
	if( size_board * tile_height > LINES - 5 || size_board * tile_width > COLS - 15) {
		endwin();
		printf("Failled to initialize, window is too small\n");
		exit(1);
	}
	printw("Press F1 to exit");
	refresh();

	WINDOW *field = newwin(LINES, COLS - 6, 0, 0);
	WINDOW *stack_content = newwin(LINES, 6, 0, COLS - 6);

	initWindow(field, stack_content);
	initBoard(field, boardData, size_board, num_elem);

	int ch, game_turn = 1, cursor_x, cursor_y;
	cursor_y = (LINES - (size_board - 1) * tile_height) / 2;
	cursor_x = (COLS - 6 - (size_board - 1) * tile_width) / 2;

	while( (ch = getch()) != KEY_F(1) || game_turn ) {
		/*
		 * game_turn used both as turn counter and game result
		 * 0 for tie, -1 for player 1 victory, -2 for player 2 victory
		 */
		updateBoard(field, boardData, size_board, ch, &game_turn, &cursor_x, &cursor_y);
	}

	endwin();

	return 0;
}

void initCurses(void) {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
}

void displayGrid(WINDOW *field, int size) {
	int starty, startx, endy, endx, i, j;
	starty = (LINES - size * tile_height) / 2;
	startx = (COLS - 6 - size * tile_width) / 2;
	endy = starty + size * tile_height;
	endx = startx + size  * tile_width;

	for(j = starty; j <= endy; j += tile_height)
		for(i = startx; i <= endx; ++i)
			mvwaddch(field, j, i, ACS_HLINE);

	for(i = startx; i <= endx; i += tile_width)
		for(j = starty; j <= endy; ++j)
			mvwaddch(field, j, i, ACS_VLINE);

	mvwaddch(field, starty, startx, ACS_ULCORNER);
	mvwaddch(field, endy, startx, ACS_LLCORNER);
	mvwaddch(field, starty, endx, ACS_URCORNER);
	mvwaddch(field, 	endy, endx, ACS_LRCORNER);

	for(j = starty + tile_height; j <= endy - tile_height; j += tile_height) {
		mvwaddch(field, j, startx, ACS_LTEE);
		mvwaddch(field, j, endx, ACS_RTEE);
		for(i = startx + tile_width; i <= endx - tile_width; i += tile_width)
			mvwaddch(field, j, i, ACS_PLUS);
	}

	for(i = startx + tile_width; i <= endx - tile_width; i += tile_width) {
		mvwaddch(field, starty, i, ACS_TTEE);
		mvwaddch(field, endy, i, ACS_BTEE);
	}

	wrefresh(field);
}

void initBoard(WINDOW *field, Stack *board, int size, int num_elem) {
	int i;
	for(i = 0; i < num_elem; i++) {
		Stack_Init(&board[i]);
		Stack_Push(&board[i], EMPTY);
	}
	displayGrid(field, size);
}

void initWindow(WINDOW *field, WINDOW *stack_content) {

	box(field, 0, 0);
	box(stack_content, 0, 0);

	wrefresh(field);
	wrefresh(stack_content);

}

void updateBoard(WINDOW *field, Stack *board, int size, int ch, int *turn, int *cursor_x, int *cursor_y) {
	/* If not spacebar, they are moving */
	int min_y = (LINES - (size - 1) * tile_height) / 2;
	int min_x = (COLS - 6 - (size - 1) * tile_width) / 2;
	int max_y = min_y + (size - 1) * tile_height;
	int max_x = min_x + (size - 1) * tile_width;

	if(ch != ' '){

		switch (ch){

			case KEY_UP:
				if(*cursor_y > min_y){
					wmove(field,*cursor_y-=tile_height, *cursor_x);
				}
				break;

			case KEY_DOWN:
				if(*cursor_y < max_y){
					wmove(field,*cursor_y+=tile_height, *cursor_x);
				}
				break;

			case KEY_LEFT:
				if(*cursor_x > min_x){
					wmove(field,*cursor_y, *cursor_x-=tile_width);
				}
				break;
			case KEY_RIGHT:
				if(*cursor_x < max_x){
					wmove(field,*cursor_y, *cursor_x+=tile_width);
				}
				break;
		}
	}
	else {
		*turn += 1;
	}
	wrefresh(field);
}
