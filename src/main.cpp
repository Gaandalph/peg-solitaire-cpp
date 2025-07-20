//
// Created by kaana on 20.07.2025.
//
#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    cout << "=== Peg Solitaire Game ===" << endl;
    cout << "'+' = peg, 'o' = empty space, 'X' = invalid area" << endl;
    cout << "Enter moves as: fromRow fromCol toRow toCol" << endl;
    cout << "Enter -1 -1 -1 -1 to quit" << endl;

    // Oyunu başlat
    Game game;

    // Ana oyun döngüsü
    while (!game.isGameOver()) {
        cout << "\n" << string(40, '=') << endl;

        game.displayBoard();

        if (game.isGameWon()) {
            cout << "\n🎉 CONGRATULATIONS! You won! Only 1 peg left! 🎉" << endl;
            break;
        }

        // Geçerli hamleleri göster
        auto validMoves = game.getValidMoves();
        cout << "\nAvailable moves (" << validMoves.size() << " total):" << endl;

        if (validMoves.empty()) {
            cout << "No valid moves available. Game Over!" << endl;
            break;
        }

        // İlk 5 geçerli hamleyi göster
        for (size_t i = 0; i < min(validMoves.size(), size_t(5)); i++) {
            cout << "  (" << validMoves[i].first.first << ","
                 << validMoves[i].first.second << ") -> ("
                 << validMoves[i].second.first << ","
                 << validMoves[i].second.second << ")" << endl;
        }

        if (validMoves.size() > 5) {
            cout << "  ... and " << (validMoves.size() - 5) << " more moves" << endl;
        }

        //FOR MOVE
        int fromRow, fromCol, toRow, toCol;
        cout << "\nEnter your move (fromRow fromCol toRow toCol): ";
        cin >> fromRow >> fromCol >> toRow >> toCol;

        // FOR EXIT
        if (fromRow == -1 && fromCol == -1 && toRow == -1 && toCol == -1) {
            cout << "Thanks for playing!" << endl;
            break;
        }

        if (game.makeMove(fromRow, fromCol, toRow, toCol)) {
            cout << "✓ Move successful!" << endl;
        } else {
            cout << "✗ Invalid move! Try again." << endl;
            cout << "Rules: " << endl;
            cout << "- Jump over an adjacent peg to an empty space" << endl;
            cout << "- Can only move horizontally or vertically" << endl;
            cout << "- Must jump exactly 2 spaces" << endl;
        }
    }

    cout << "\n" << string(40, '=') << endl;
    cout << "GAME FINISHED!" << endl;
    game.showGameStats();

    if (game.isGameWon()) {
        cout << "\n🏆 PERFECT! You are a Peg Solitaire Master! 🏆" << endl;
    } else if (game.getPegsLeft() <= 5) {
        cout << "\n👏 Great job! Very few pegs left!" << endl;
    } else {
        cout << "\n💪 Good effort! Try again for a better score!" << endl;
    }

    return 0;
}