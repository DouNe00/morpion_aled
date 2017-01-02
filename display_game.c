#include <ncurses.h>

int main(int argc, char **argv) {

  int size_board, startx, starty;
  if (argc != 2) {
    printf("Usage : %s <size of the board>\n", argv[0]);
    exit(1);
  }
  size_board = atoi(argv[1]);
  /* init curses */
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  starty = (LINES - size_board * 5) / 2;
  startx = (LINES - size_board * 5) / 2;
  board(stdscr, starty, startx, size_board, size_board, 5, 3);
  imMovingBitchies(stdscr, starty, startx, 5, 3, startx, starty);
  clear();
  exit(0);
  endwin();
  return 0;
}

void test(WINDOW *win, int starty, int startx, int tile_width, int tile_height,
          int cursorx, int cursory) {
  int value = getch();

  refresh();
  if (value == KEY_UP) {
    cursorx -= tile_width + 1;
    move(cursorx, cursory);
    return (imMovingBitchies(win, starty, startx, tile_width, tile_height,
                             cursorx, cursory));
  } else if (value == KEY_DOWN) {
    cursorx += tile_width + 1;
    move(cursorx, cursory);
    return (imMovingBitchies(win, starty, startx, tile_width, tile_height,
                             cursorx, cursory));
  } else if (value == KEY_LEFT) {
    cursory -= tile_height + 1;
    move(cursorx, cursory);
    return (imMovingBitchies(win, starty, startx, tile_width, tile_height,
                             cursorx, cursory));
  } else if (value == KEY_RIGHT) {
    cursory += tile_height + 1;
    move(cursorx, cursory);
    return (imMovingBitchies(win, starty, startx, tile_width, tile_height,
                             cursorx, cursory));
  }
}

void imMovingBitchies(WINDOW *win, int starty, int startx, int tile_width,
                      int tile_height, int cursorx, int cursory) {
  int value = getch();

  refresh();
  if (value == KEY_UP) {
    cursory -= tile_height + 2;
    move(cursory, cursorx);
    return (imMovingBitchies(win, starty, startx, tile_width, tile_height,
                             cursorx, cursory));
  } else if (value == KEY_DOWN) {
    cursory += tile_height + 2;
    move(cursory, cursorx);
    return (imMovingBitchies(win, starty, startx, tile_width, tile_height,
                             cursorx, cursory));
  } else if (value == KEY_LEFT) {
    cursorx -= tile_width + 4;
    move(cursory, cursorx);
    return (imMovingBitchies(win, starty, startx, tile_width, tile_height,
                             cursorx, cursory));
  } else if (value == KEY_RIGHT) {
    cursorx += tile_width + 4;
    move(cursory, cursorx);
    return (imMovingBitchies(win, starty, startx, tile_width, tile_height,
                             cursorx, cursory));
  }
}

void board(WINDOW *win, int starty, int startx, int lines, int cols,
           int tile_width, int tile_height) {
  int endy, endx, i, j;

  endy = starty + lines * tile_height;
  endx = startx + cols * tile_width;

  for (j = starty; j <= endy; j += tile_height)
    for (i = startx; i <= endx; ++i)
      mvwaddch(win, j, i, ACS_HLINE);
  for (i = startx; i <= endx; i += tile_width)
    for (j = starty; j <= endy; ++j)
      mvwaddch(win, j, i, ACS_VLINE);
  mvwaddch(win, starty, startx, ACS_ULCORNER);
  mvwaddch(win, endy, startx, ACS_LLCORNER);
  mvwaddch(win, starty, endx, ACS_URCORNER);
  mvwaddch(win, endy, endx, ACS_LRCORNER);
  for (j = starty + tile_height; j <= endy - tile_height; j += tile_height) {
    mvwaddch(win, j, startx, ACS_LTEE);
    mvwaddch(win, j, endx, ACS_RTEE);
    for (i = startx + tile_width; i <= endx - tile_width; i += tile_width)
      mvwaddch(win, j, i, ACS_PLUS);
  }
  for (i = startx + tile_width; i <= endx - tile_width; i += tile_width) {
    mvwaddch(win, starty, i, ACS_TTEE);
    mvwaddch(win, endy, i, ACS_BTEE);
  }
  wrefresh(win);
}
