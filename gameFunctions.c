#include "gameFunctions.h"

void initBoard(WINDOW *field, Stack *board, int size, int num_elem) {
	int i;
	for(i = 0; i < num_elem; i++) {
		Stack_Init(&board[i]);
		Stack_Push(&board[i], EMPTY);
	}
	displayGrid(field, size);
}

void gameSettings(char *argv[], int *size_board, int *game_mode, int *earthquake) {
  /* this function is supposed to be called only with atleast 4 elements in argv */
  *size_board = atoi(argv[1]);
  *game_mode = atoi(argv[2]);
  *earthquake = atoi(argv[3]);
}

void playGame(int size_board, int num_elem, int game_mode, int earthquake) {
  initCurses();
  /* arbitrary marges */
  if( size_board * tile_height > LINES - 5 || size_board * tile_width > COLS - 15) {
    printf("Failled to launch, window is too small\n");
    exit(1);
  }
  printw("Press q to exit");
  refresh();

  Stack boardData[num_elem];

  WINDOW *field = newwin(LINES, COLS - right_column_width, 0, 0);
  WINDOW *stack_content = newwin(LINES, right_column_width, 0, COLS - right_column_width);

  initWindowBorders(field, stack_content);
  initBoard(field, boardData, size_board, num_elem);

  getch();
  endwin();
}

/*
int ch, game_turn = 1, cursor_x, cursor_y;
cursor_y = (LINES - (size_board - 1) * tile_height) / 2;
cursor_x = (COLS - right_column_width - (size_board - 1) * tile_width) / 2;

while( (ch = getch()) != 'q' || game_turn ) {
  updateCursor(field, boardData, size_board, ch, &cursor_x, &cursor_y);
}

endwin();
*/
