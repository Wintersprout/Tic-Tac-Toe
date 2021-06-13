#include "Board.h"
#include <iostream>

Board::Board()
{
	for (int i = 0; i < 10; i++)
		boardData[i] = ' ';
}

void Board::drawBoard()
{
	std::cout << "\n\t" << boardData[7] << '|' << boardData[8] << '|' << boardData[9] << '\n';
	std::cout << '\t' << '-' << '+' << '-' << '+' << '-' << '\n';
	std::cout << '\t' << boardData[4] << '|' << boardData[5] << '|' << boardData[6] << '\n';
	std::cout << '\t' << '-' << '+' << '-' << '+' << '-' << '\n';
	std::cout << '\t' << boardData[1] << '|' << boardData[2] << '|' << boardData[3] << "\n\n";
}

int Board::updateBoard(char symbol, int pos)
{// Returns 0 if update fails
	if (!(pos > 0 && pos < 10))
	{
		return 0; // Must be a number between 1 and 9
	}
	if (boardData[pos] == ' ') // Space must be empty
	{
		boardData[pos] = symbol;
		return 1;
	}
	else
		return 0;
}

bool Board::isWinner(char symbol)
{
	return ((boardData[7] == symbol && boardData[8] == symbol && boardData[9] == symbol) ||
		(boardData[4] == symbol && boardData[5] == symbol && boardData[6] == symbol) ||
		(boardData[1] == symbol && boardData[2] == symbol && boardData[3] == symbol) ||
		(boardData[7] == symbol && boardData[4] == symbol && boardData[1] == symbol) ||
		(boardData[8] == symbol && boardData[5] == symbol && boardData[2] == symbol) ||
		(boardData[9] == symbol && boardData[6] == symbol && boardData[3] == symbol) ||
		(boardData[7] == symbol && boardData[5] == symbol && boardData[3] == symbol) ||
		(boardData[9] == symbol && boardData[5] == symbol && boardData[1] == symbol));
}

bool Board::isSpaceEmpty(int pos)
{
	return boardData[pos] == ' ';
}
bool Board::isFull()
{
	for (int i = 1; i < 10; i++)
		if (boardData[i] == ' ')
			return false;
	return true;
}

void Board::clearSpace(int pos)
{
	boardData[pos] = ' ';
}

void Board::clearBoard()
{
	for (int i = 1; i < 10; i++)
		boardData[i] = ' ';
}
