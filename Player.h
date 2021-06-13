#pragma once

class Player
{
private:
	char symbol{ 'O' };
public:
	char getSymbol();
	int makeMove(Board& b, int pos);
};

