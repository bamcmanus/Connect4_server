#include "player.h"
#include "board.h"
#include <string>
#include <sstream>
#include <limits>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

constexpr auto DEPTH = 2;

using namespace std;

// Checks if the game is over
bool Ai::is_terminal(Board& b)
{
	return b.winning_move(RED) || b.winning_move(BLACK) || b.is_draw();
}

// Randomly returns a column move
int Ai::get_random_move()
{
	return rand() % 7;
	// ensure valid move
}

// Minimax algorithm for deciding best move, returns column of best move
int Ai::get_minimax_move(Board& b, int depth, bool is_ai, int& best_move)
{
	if (b.is_draw())
		return 0;
	else if (b.winning_move(BLACK))
		return numeric_limits<int>::max();
	else if (b.winning_move(RED))
		return numeric_limits<int>::min();;

	if (depth == 0)
		return ((is_ai) ? b.score(BLACK) : b.score(RED));

	if (is_ai)
	{
		int best_value = numeric_limits<int>::min();
		for (int col = 0; col < COLS; ++col)
		{
			if (b.is_legal(col))
			{
				b.make_move(col, BLACK);
				int value = get_minimax_move(b, depth - 1, !is_ai, best_move);
				if (value > best_value)
				{
					best_value = value;
					best_move = col;
				}
				b.undo(col);
			}
		}
		return best_value;
	}
	else
	{
		int best_value = numeric_limits<int>::max();
		for (int col = 0; col < COLS; ++col)
		{
			if (b.is_legal(col))
			{
				b.make_move(col, RED);
				int value = get_minimax_move(b, depth - 1, !is_ai, best_move);
				if (value < best_value)
				{
					best_value = value;
				}
				b.undo(col);
			}
		}
		return best_value;
	}
}


// Greedy algorithm uses single move look ahead to determine the best move, returns colum of best move
int Ai::get_greedy_move(Board& b, const int piece)
{
	int best_score = numeric_limits<int>::min();
	int score = 0;
	int best_col = rand() % 7;
	for (int col = 0; col < COLS; ++col)
	{
		if (b.is_legal(col))
			b.make_move(col, piece);
		else
			continue;
		score = b.score(piece);
		if (score > best_score)
		{
			best_score = score;
			best_col = col;
		}
		b.undo(col);
	}
	return best_col;
}