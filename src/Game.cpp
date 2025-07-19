//
// Created by kaana on 19.07.2025.
//

#include "Game.h"
#include <iostream>
#include <cmath>

Game:: Game() : rows(7), cols(7), pegsLeft(0), gameOver(false) {
    initializeBoard();
}

Game::Game(int r, int c) : rows(r), cols(c), pegsLeft(0), gameOver(false) {
    board.resize(rows, vector<char>(cols, 'X'));
    initializeBoard();
}

Game:: ~Game() {

}

void Game::initializeBoard() {
    board.assign(rows, vector<char>(cols, 'X'));

    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0 ; j < cols ; j++) {
            if ((i >= 2 && i <= 4) || (j >= 2 && j <= 4)) {
                board[i][j] = 1 ;
                pegsLeft++;
            }
        }
    }

    board[3][3] = 'o';
    pegsLeft--;

    gameOver = false;
}

void Game::resetGame() {
    initializeBoard();
}

bool Game::isValidPosition(int row, int col) const {
    return (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] != 'X');
}

bool Game::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
    if (!isValidPosition(fromRow, fromCol) || board[fromRow][fromCol] == '+')
        return false;

    if (!isValidPosition(toRow, toCol) || board[toRow][toCol] != 'o')
        return false;

    int rowDiff = abs(toRow - fromRow);
    int colDiff = abs(toCol - fromCol);

    if (!((rowDiff == 2 && colDiff == 0) || (rowDiff == 0 && colDiff == 2))) {
        return false;
    }
    int midRow = (fromRow + toRow)/2;
    int midCol = (fromCol + toCol)/2;

    return board[midRow][midCol] == '+' ;
}

bool Game::makeMove(int fromRow, int fromCol, int toRow, int toCol) {
    if (!isValidMove(fromRow, fromCol, toRow, toCol))
        return false;

    board[fromRow][fromCol] = 'o';
    board[toRow][toCol] = '+' ;

    int midRow = (fromRow + toRow)/2;
    int midCol = (fromCol + toCol)/2;
    board[midRow][midCol] = 'o';
    pegsLeft--;

    if (!hasValidMoves()) {
        gameOver = true;
    }

    return true;
}

void Game::removePeg(int row, int col) {
    if (isValidPosition(row, col) && board[row][col] == '+') {
        board[row][col] = 'o';
        pegsLeft--;
    }
}

void Game::addPeg(int row, int col) {
    if (isValidPosition(row, col) && board[row][col] =='o') {
        board[row][col] == '+';
        pegsLeft++;
    }
}

bool Game::hasValidMoves() const {
    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0 ; j < cols ; j++) {
            if (board[i][j] == '+') {

                int directions[4][2] = {{-2,0}, {2,0}, {0,-2}, {-2,0}};
                for (int d = 0 ; d < 4 ; d++) {
                    int newRow = i + directions[d][0];
                    int newCol = j + directions[d][1];

                    if (isValidMove(i,j,newRow,newCol)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Game::displayBoard() const {
    cout << "\n ";
    for (int j = 0; j < cols; j++) {
        cout << j << " ";
    }
    cout << "\n";

    for (int i = 0; i < rows; i++) {
        cout << i << " ";
        for (int j = 0; j < cols; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nPegs left: " << pegsLeft << "\n";
}

void Game::printBoard() const {
    displayBoard();
}

int Game::getPegsLeft() const {
    return pegsLeft;
}

int Game::getBoardRows() const {
    return rows;
}
int Game::getBoardCols() const {
    return cols;
}

vector<pair<pair<int, int>, pair<int, int> > > Game::getValidMoves() const {
    vector<pair<pair<int,int>, pair<int, int>>> validMoves;

    for (int i = 0; i < rows ; i++) {
        for (int j = 0 ; j < cols ; j++) {
            if (board[i][j] == '+') {
                int directions[4][2] = {{-2,0},{2,0},{0,-2},{0,2}};
                for (int d = 0 ; d < 4 ; d++) {
                    int newRow = i + directions[d][0];
                    int newCol = j + directions[d][1];
                    if (isValidMove(i,j,newRow,newCol)) {
                        validMoves.push_back({{i,j}, {newRow,newCol}});
                    }
                }
            }
        }
    }
    return validMoves;
}
bool Game::isGameWon() const {
    return (pegsLeft == 1);
}

bool Game::isGameOver() const {
    return gameOver || isGameWon();
}

