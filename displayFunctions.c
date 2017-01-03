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
