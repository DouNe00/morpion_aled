#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include"const.h"
#include"gameFunctions.h"

int main(int argc, char *argv[]) {
	/* game settings */
	int size_board, num_elem, game_mode, earthquake;

	/* are all the parameters passed to the program ? */
	if(argc != 4)
	{
		printf("Usage : %s <size of the board> <game mode> <earthquake activation>\n",argv[0]);
		exit(1);
	}

	/* init settings values */
	gameSettings(argv, &size_board, &game_mode, &earthquake);
	num_elem = size_board * size_board;

	/* launch the game */
	playGame(size_board, num_elem, game_mode, earthquake);

	return 0;
}
