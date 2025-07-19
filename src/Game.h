//
// Created by kaana on 19.07.2025.
//

#ifndef GAME_H
#define GAME_H
#include <vector>
using namespace std;


class Game {
private:
    vector<vector<char>> board;

    int rows;
    int cols;

    int pegsLeft;

    bool gameOver;

    bool isValidPosition(int row, int col) const;
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const;
    void removePeg(int row, int col);
    void addPeg(int row, int col);

public:

    Game();

    Game(int rows, int cols);

    ~Game();

    void initializeBoard();
    void resetGame();

    bool makeMove(int fromRow, int fromCol, int toRow, int toCol);

    bool isGameWon() const;
    bool isGameOver() const;
    bool hasValidMoves() const;


    void displayBoard() const;
    void printBoard() const;

    int getPegsLeft() const;
    int getBoardRows() const;
    int getBoardCols() const;

    vector<vector<int>> getBoard() const;

    vector<pair<pair<int,int>, pair<int, int>>> getValidMoves() const;

    void showGameStats() const;

};



#endif //GAME_H
