#include <vector>
#pragma once

static const int RED	= 1;
static const int BLACK	= 2;
static const int EMPTY	= 0;
static const int ROWS	= 6;
static const int COLS	= 7;

class Board
{
private:
	std::vector<std::vector<int>> _game_board;

public:
	Board();
	bool winning_move(const int piece);
	int score(const int piece);
	int horiz_score(const std::vector<int>, int);
	int vert_score(const std::vector<int>, int);
	int rdiag_score(const int piece);
	int ldiag_score(const int piece);
	int evaluate_window(const std::vector<int> window, const int piece);
	void new_board();
	bool is_legal(const int col) const;
	bool make_move(const int col, const int piece);
	void undo(const int col);
	char get_value(const int row, const int col);
	bool is_draw();
	bool is_winner(const int col);
	bool is_winner_horiz(const int col);
	bool is_winner_vert(const int col);
	bool is_winner_ldiag(const int col);
	bool is_winner_rdiag(const int col);
};

class NoValueException { };