//
// Created by kaana on 19.07.2025.
//

#include "Game.h"

Game:: Game() : rows(7), cols(7), pegsLeft(0), gameOver(false) {
    initializeBoard();
}

Game::Game(int r, int c) : rows(r), cols(c), pegsLeft(0), gameOver(false) {
    board.resize(rows, vector<int>(cols, -1));
    initializeBoard();
}

Game:: ~Game() {

}

void Game::initializeBoard() {
    board.assign(rows, vector<int>(cols, -1));

    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0 ; j < cols ; j++) {
            if ((i >= 2 && i <= 4) || (j >= 2 && j <= 4)) {
                board[i][j] = 1 ;
                pegsLeft++;
            }
        }
    }

    boards[3][3] = 0;
    pegsLeft--;

    gameOver = false;
}

void Game::resetGame() {
    initializeBoard();
}

bool Game::isValidPosition(int row, int col) const {
    return (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] != -1);
}

bool Game::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
    if (!isValidPosition(fromRow, fromCol) || board[fromRow][fromCol] == 1)
        return false;

    if (!isValidPosition(toRow, toCol) || board[toRow][toCol] != 0)
        return false;

    int midRow = (fromRow + toRow)/2;
    int midCol = (fromCol + toCol)/2;

    return board[midRow][midCol] == 1 ;
}

bool Game::makeMove(int fromRow, int fromCol, int toRow, int toCol) {
    if (!isValidMove(fromRow, fromCol, toRow, toCol))
        return false;

    board[fromRow][fromCol] = 0 ;
    board[toRow][toCol] = 1 ;

    int midRow = (fromRow + toRow)/2;
    int midCol = (fromCol + toCol)/2;
    board[midRow][midCol] = 0;
    pegsLeft--;

    if (!hasValidMoves()) {
        gameOver = true;
    }

    return true;
}
