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

int coordToTile(int size_board, int cursor_y, int cursor_x) {
	int min_y = (LINES - (size_board - 1) * tile_height) / 2;
	int min_x = (COLS - right_column_width - (size_board - 1) * tile_width) / 2;

	int board_y = (cursor_y - min_y) / tile_width;
	int board_x = (cursor_x - min_x) / tile_height;

	return (board_y * size_board + board_x);
}

void moveAdd(int cursor_y, int cursor_x, int turn, Stack* board, int size_board, WINDOW *field) {
	int position_tile = coordToTile(size_board, cursor_y, cursor_x);
	int player = turn % 2 + 1;
	if(player == 1) {
		Stack_Push(&board[position_tile], PLAYER_1);
	}
	else {
		Stack_Push(&board[position_tile], PLAYER_2);
	}
	mvwaddch(field, cursor_y, cursor_x, Stack_Top(&board[position_tile]));
	wrefresh(field);
}

void moveRemove(int cursor_y, int cursor_x, int turn, Stack* board, int size_board, WINDOW *field) {
	int position_tile = coordToTile(size_board, cursor_y, cursor_x);
	Stack_Pop(&board[position_tile]);
	mvwaddch(field, cursor_y, cursor_x, Stack_Top(&board[position_tile]));
	wrefresh(field);
}

int checkWin(int size, int game_mode, Stack *board) {
	return 0;
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

	/* init cursor position to top left tile */
	int ch, game_over = 0, turn = -1, cursor_x, cursor_y;
	cursor_y = (LINES - (size_board - 1) * tile_height) / 2;
	cursor_x = (COLS - right_column_width - (size_board - 1) * tile_width) / 2;

  while( (ch=getch()) != 'q' && !game_over ) {
		if (ch != 'p' && ch != 'r') {
			updateCursor(field, boardData, size_board, ch, &cursor_x, &cursor_y);
		}
		else if(ch == 'p') {
			moveAdd(cursor_y, cursor_x, ++turn, boardData, size_board, field);
			game_over = checkWin(size_board, game_mode, boardData);
		}
		else {
			moveRemove(cursor_y, cursor_x, ++turn,boardData, size_board, field);
			game_over = checkWin(size_board, game_mode, boardData);
		}
	}
  endwin();
}

/*


while( (ch = getch()) != 'q' || game_turn ) {
  updateCursor(field, boardData, size_board, ch, &cursor_x, &cursor_y);
}

endwin();
*/
