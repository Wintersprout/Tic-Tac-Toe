#pragma once
class Board
{
private:
	char boardData[10]{};
public:
	Board();
	void drawBoard();
	int updateBoard(char symbol, int pos);
	bool isWinner(char symbol);
	bool isSpaceEmpty(int pos);
	bool isFull();
	void clearSpace(int pos);
	void clearBoard();
};

