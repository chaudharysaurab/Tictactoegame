🎮 Tic-Tac-Toe Game (C++ using DSA)

This project is a simple Tic-Tac-Toe game built using C++ and basic Data Structures & Algorithms (DSA) concepts.
It is a two-player console-based game where each player takes turns marking spaces on a 3x3 board with X or O. The first player to align three of their symbols horizontally, vertically, or diagonally wins the game. If the board is filled and no player has won, the game ends in a draw.

✨ Features

🟢 Two-player gameplay (Player X vs Player O).

🟢 Simple menu-driven console interface.

🟢 Input validation (prevents overwriting already filled positions).

🟢 Detects winner or draw automatically.

🟢 Demonstrates usage of arrays, loops, and condition checking.

⚙️ How It Works

The board is represented using a 2D array.

Players take turns entering their move by choosing a board position (1–9).

After every move, the program checks:

If a player has three in a row → declares a winner.

If the board is full without a winner → declares a draw.


🎯 Learning Objectives

Applying 2D arrays in real-world problems.

Understanding game logic and condition checking.

Practice with loops, functions, and modular programming in C++.

📸 Example Gameplay
Player 1 (X) - Player 2 (O)

 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9

Player 1, enter a number: 5

 X |   |  
---+---+---
   | O |  
---+---+---
   |   |  

Winner: Player 1 🎉
