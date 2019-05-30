#include "Connect4.h"
#include "player.h"
#include "board.h"
//#include <unistd.h>
#include <sstream>
#include <time.h>

constexpr auto DEPTH = 2;

using namespace std;

// Game manager switches based on main menu option
void Connect4::play()
{
	srand(time(0));

	bool option = true;

	int turn = rand() % 2;
	int move = 0;
	int who_won = 0;

	Board b;

	player1.set_game_piece(RED);
	player2.set_game_piece(BLACK);
	cpu.set_game_piece(BLACK);

	switch (1) //fix this
	{
	case 1:
		do
		{
			if (turn == 1)
			{
				do {
					//move = player1.get_move();
					who_won = 1;
				} while (!b.make_move(move, player1.get_piece()));
				turn = 2;
			}
			else
			{
				do
				{
				//	move = player2.get_move();
					who_won = 2;
				} while (!b.make_move(move, player2.get_piece()));
				turn = 1;
			}
		} while (!b.is_winner(move));

		break;

	case 2:
		do
		{
			if (turn == 1)
			{
				do {
					//move = player1.get_move();
					who_won = 1;
				} while (!b.make_move(move, player1.get_piece()));
				turn = 2;
			}
			else
			{
				do
				{
					move = cpu.get_random_move();
					who_won = 2;
				} while (!b.make_move(move, player2.get_piece()));
				turn = 1;
			}
		} while (!b.is_winner(move));

		break;

	case 3:
		do
		{
			if (turn == 1)
			{
				do {
					//move = player1.get_move();
					who_won = 1;
				} while (!b.make_move(move, player1.get_piece()));
				turn = 2;
			}
			else
			{
				do
				{
					move = cpu.get_greedy_move(b, cpu.get_piece());
					who_won = 2;
				} while (!b.make_move(move, cpu.get_piece()));
				turn = 1;
			}
		} while (!b.is_winner(move));

		break;

	case 4:
		do
		{
			if (turn == 1)
			{
				do {
					//move = player1.get_move();
					who_won = 1;
				} while (!b.make_move(move, cpu.get_piece()));
				turn = 2;
			}
			else
			{
				do
				{
					cpu.get_minimax_move(b, DEPTH, true, move);
					who_won = 2;
				} while (!b.make_move(move, cpu.get_piece()));
				turn = 1;
			}
		} while (!b.is_winner(move));

		break;
	}
}

int main()
{
	return 0;
}