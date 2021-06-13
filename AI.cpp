#include "Board.h"
#include "Player.h"
#include "AI.h"
#include <iostream>
#include <vector>

int AI::winningMove(Board b, char symbol)
{
	// Returns position for a winning move or 0 if there is none.
	for (int i = 1; i < 10; i++)
	{
		if (!b.updateBoard(symbol, i))
			// Position occupied.
			continue;
		if (b.isWinner(symbol))
			return i;
		else
			// Reset move
			b.clearSpace(i);
	}
	return 0;
}

int AI::cornerMove(Board b)
{
	// Returns position for a corner move or 0 if there is none.
	const int corner[]{ 1, 3, 7, 9 };
	std::vector<int> move;
	int size{};
	if (b.isSpaceEmpty(corner[0]))
	{
		move.push_back(corner[0]);
		size++;
	}
	if (b.isSpaceEmpty(corner[1]))
	{
		move.push_back(corner[1]);
		size++;
	}
	if (b.isSpaceEmpty(corner[2]))
	{
		move.push_back(corner[2]);
		size++;
	}
	if (b.isSpaceEmpty(corner[3]))
	{
		move.push_back(corner[3]);
		size++;
	}
	if (size == 0)
		return 0;

	return move[rand() % size];
}
int AI::sideMove(Board b)
{
	const int side[]{ 2, 4, 6, 8 };
	std::vector<int> move;
	int size{};
	if (b.isSpaceEmpty(side[0]))
	{
		move.push_back(side[0]);
		size++;
	}
	if (b.isSpaceEmpty(side[1]))
	{
		move.push_back(side[1]);
		size++;
	}
	if (b.isSpaceEmpty(side[2]))
	{
		move.push_back(side[2]);
		size++;
	}
	if (b.isSpaceEmpty(side[3]))
	{
		move.push_back(side[3]);
		size++;
	}
	if (size == 0)
		return 0;

	return move[rand() % size];
}
int AI::centerMove(Board b)
{
	if (b.isSpaceEmpty(5))
		return 5;
	else
		return 0;
}
char AI::getSymbol()
{
	return symbol;
}
void AI::makeMove(Board &b)
{
	
	int win = winningMove(b, symbol);
	int lose = winningMove(b, opponent);
	int corner = cornerMove(b);
	int center = centerMove(b);
	int side = sideMove(b);
	// Check for winning moves
	if (win)
		b.updateBoard(symbol, win);
	// Check for opponent's winning moves
	else if (lose)
		b.updateBoard(symbol, lose);
		// Check for corner moves
	else if (corner)
		b.updateBoard(symbol, cornerMove(b));
		// Check for center moves
	else if (center)
		b.updateBoard(symbol, centerMove(b));
		// Check for side moves
	else if (side)
		b.updateBoard(symbol, sideMove(b));
}
