#pragma once
#include "board.h";
#include "player.h";

class Connect4
{
public:
	void play();        // Driver method manages game

private:
	Board game_board;   // Game board for connect 4
	player player1;      // Human player
	player player2;      // Human player
	Ai cpu;       // AI object
};

