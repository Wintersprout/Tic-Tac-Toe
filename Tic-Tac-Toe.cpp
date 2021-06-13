// Tic-Tac-Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board.h"
#include "Player.h"
#include "AI.h"

bool playAgain();

int main()
{
    std::cout << "Let\'s Play Tic-Tac-Toe!\n\n";
    Board t;
    Player me;
    AI pc;
    int win{}, lose{}, tie{};

    std::srand(std::time(0));
    
    bool turn{ 0 };
    bool gameOver{ false };
    int move{ 0 };
    
    while (!gameOver)
    {
        t.drawBoard();
        // Game loop
        while (!t.isFull())
        {
            // Getting players moves
            switch (turn)
            {
            case 0: // Player move
                std::cout << "\nMake your move (1-9): ";
                while (true)
                {
                    std::cin >> move;
                    // Validating input
                    if (!me.makeMove(t, move))
                    {
                        std::cout << "Invalid move! Please try again: ";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else
                        break;
                }
                break;
            case 1: // AI move
                std::cout << "\nThe computer is making its move ...\n";
                pc.makeMove(t);
                break;
            default:
                break;
            }
            t.drawBoard();
            turn ^= 1; // Switch turns

            // Check for winners
            if (t.isWinner(pc.getSymbol()))
            {
                std::cout << "You lose!\n";
                lose++;
                gameOver = true;
                break;
            }
            else if (t.isWinner(me.getSymbol()))
            {
                std::cout << "You win!\n";
                win++;
                gameOver = true;
                break;
            }
        }
        if (!gameOver)
        {
            std::cout << "Tie!\n";
            tie++;
        }
        std::cout << "--------------\n";
        std::cout << "| Scoreboard |\n";
        std::cout << "--------------\n";
        std::cout << "Win: " << win << " Lose: " << lose << " Tie: " << tie << std::endl;
        gameOver = playAgain();
        t.clearBoard();
    }
    std::cout << "Thank you for playing. Goodbye.\n";
}

bool playAgain()
{
    char again{};

    while (true)
    {
        std::cout << "\nWould you like to play again? (y/n) ";
        std::cin >> again;
        switch (again)
        {
        case 'y':
        case 'Y':
            return false;
        case 'N':
        case 'n':
            return true;
        default:
            std::cout << "Ops! Looks like your input is invalid.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}

// TODO
// - Sort symbols randomly
// - Merge AI's cornerMove, sideMove and centerMove in one function
// - Improve AI to get center when it should.