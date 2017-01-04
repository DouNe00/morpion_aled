#include"displayFunctions.h"

void initCurses(void) {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
}

void initWindowBorders(WINDOW *field, WINDOW *stack_content) {

	box(field, 0, 0);
	box(stack_content, 0, 0);

	wrefresh(field);
	wrefresh(stack_content);

}

void displayGrid(WINDOW *field, int size) {
	int starty, startx, endy, endx, i, j;
	starty = (LINES - size * tile_height) / 2;
	startx = (COLS - right_column_width - size * tile_width) / 2;
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

void updateCursor(WINDOW *field, Stack *board, int size, int ch, int *cursor_x, int *cursor_y) {

	int min_y = (LINES - (size - 1) * tile_height) / 2;
	int min_x = (COLS - right_column_width - (size - 1) * tile_width) / 2;
	int max_y = min_y + (size - 1) * tile_height;
	int max_x = min_x + (size - 1) * tile_width;

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
	wrefresh(field);
}

void displayErrorEmpty(WINDOW *field) {
	mvwprintw(field, 6, 2, "Vous ne pouvez pas retirer un element d'un pile vide, jouer de nouveau");
	wrefresh(field);
}

void removeErrorEmpty(WINDOW *field) {
	mvwprintw(field, 6, 2, "                                                                      ");
	wrefresh(field);
}

void displayGameInfo(WINDOW *field, int size, int game_mode, int earthquake, int turn) {
	if (game_mode == 1) {
		mvwprintw(field, 2, 2, "Tictactoe. Mode Vue du dessus. Seisme : %d. Joueur %d.", earthquake, turn % 2 + 1);
	}
	else {
		mvwprintw(field, 2, 2, "Tictactoe. Mode 3d. Seisme : %d. Joueur %d.", earthquake, turn % 2 + 1);
	}
	mvwprintw(field, 4, 2, "q pour quitter, p pour poser, r pour retirer, fleches pour deplacer le curseur");
wrefresh(field);
}

/* TODO : seg fault and keep cursor at the top left of the window */
void displayStackData(WINDOW *stack_window, int cursor_y, int cursor_x, Stack *board, int size) {
	int position_tile = coordToTile(size, cursor_y, cursor_x);
	int i;
	wclear(stack_window);
	box(stack_window, 0, 0);
	for(i = board[position_tile].size - 1; i >= 0; i--) {
		mvwprintw(stack_window, i, 2, "%c", board[position_tile].data[i]);
	}
	wrefresh(stack_window);
}
