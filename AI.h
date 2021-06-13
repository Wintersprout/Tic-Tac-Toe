#pragma once
class AI
{
private:
	char symbol{ 'X' };
	char opponent{ 'O' };
	int winningMove(Board b, char symbol);
	int cornerMove(Board b);
	int centerMove(Board b);
	int sideMove(Board b);
public:
	char getSymbol();
	void makeMove(Board &b);
};

