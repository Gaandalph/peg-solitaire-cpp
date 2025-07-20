# 🎯 Peg Solitaire Game

A classic **Peg Solitaire** puzzle game implemented in C++ with console interface.

## 📖 About

Peg Solitaire is a traditional board game puzzle where the goal is to remove pegs by jumping over them until only one peg remains on the board. This implementation features a 7x7 cross-shaped board with 32 initial pegs.

## ✨ Features

- **Console-based gameplay** with clear visual board representation
- **Move validation** system to ensure legal moves only
- **Interactive interface** with move suggestions
- **Game statistics** and win condition checking
- **Clean C++ object-oriented design**

## 🎮 How to Play

- `+` represents a peg
- `o` represents an empty space
- `X` represents invalid board areas

**Rules:**
- Jump over an adjacent peg to land in an empty space
- The jumped peg is removed from the board
- Moves can only be horizontal or vertical (no diagonal)
- You must jump exactly 2 spaces
- Goal: Remove all pegs except one!

## 🚀 Getting Started

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- Terminal/Command prompt

### Compilation & Running

```bash
# Clone the repository
git clone https://github.com/Gaandalph/SoloTest.git
cd SoloTest

# Compile the game
g++ src/main.cpp src/Game.cpp -o game.exe

# Run the game
./game.exe
```

### Example Move
```
Enter your move (fromRow fromCol toRow toCol): 1 3 3 3
```
This moves the peg from position (1,3) to position (3,3), removing the peg at (2,3).

## 🎯 Game Objective

Start with 32 pegs and try to end with only 1 peg remaining. The fewer pegs left, the better your score!

**Scoring:**
- 🏆 **1 peg left**: Perfect! You're a Peg Solitaire Master!
- 👏 **2-5 pegs left**: Great job! Very impressive!
- 💪 **6+ pegs left**: Good effort! Try again for a better score!

## 🏗️ Project Structure

```
SoloTest/
├── src/
│   ├── main.cpp      # Main game loop and user interface
│   ├── Game.cpp      # Game logic implementation
│   └── Game.h        # Game class header file
└── README.md         # This file
```

## 🔧 Technical Details

- **Language**: C++17
- **Design Pattern**: Object-Oriented Programming
- **Memory Management**: STL containers (vectors)
- **Input Validation**: Comprehensive move validation system

## 🤝 Contributing

Feel free to fork this project and submit pull requests for improvements!

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

---

**Enjoy the game!** 🎮 Try to beat the ultimate challenge of leaving just one peg!