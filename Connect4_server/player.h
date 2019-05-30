#pragma once
#include "board.h"

enum type { random, greedy, minimax };

class player
{
protected:
	int _game_piece;																// integer for game piece: 0 = empty, 1 = red, 2 = black

public:
	player() { _game_piece = 0; };													// Base class constructor
	virtual int get_piece() { return _game_piece; };								// Getter for a game piece
	virtual void set_game_piece(const int game_piece) { _game_piece = game_piece; };// Sets game piece type
};


class Ai : public player
{
private:
	type t;																	// Enum type for random, greedy or minimax AI

public:
	bool is_terminal(Board& b);												// Checks if game is over														// Gets move based on type
	int get_random_move();                                                  // Generates a random move
	int get_greedy_move(Board& b, const int piece);                         // Greedy Ai looks ahead for best move
	int get_minimax_move(Board& b, int depth, bool is_ai, int& best_move);  // Minimax algorithm to generate move
};

