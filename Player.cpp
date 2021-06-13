#include "Board.h"
#include "Player.h"

char Player::getSymbol()
{
	return symbol;
}

int Player::makeMove(Board& b, int pos)
{
	return b.updateBoard(symbol, pos);
}
