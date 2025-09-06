#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    int movesCount;

    void initializeBoard() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';
    }

    void printBoard() {
        cout << "\n";
        cout << "  0   1   2\n";
        for (int i = 0; i < 3; i++) {
            cout << i << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << " ---+---+---\n";
        }
        cout << "\n";
    }

    bool isValidMove(int row, int col) {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer &&
                board[i][1] == currentPlayer &&
                board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer &&
                board[1][i] == currentPlayer &&
                board[2][i] == currentPlayer)
                return true;
        }
        // Check diagonals
        if (board[0][0] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][0] == currentPlayer)
            return true;

        return false;
    }

    bool checkDraw() {
        return movesCount == 9;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void saveGameToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Error opening file for writing.\n";
            return;
        }
        file << currentPlayer << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                file << board[i][j];
            }
            file << "\n";
        }
        file.close();
        cout << "Game saved to " << filename << "\n";
    }

    void loadGameFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file for reading.\n";
            return;
        }
        file >> currentPlayer;
        string line;
        getline(file, line); // consume newline after currentPlayer
        for (int i = 0; i < 3; i++) {
            getline(file, line);
            for (int j = 0; j < 3; j++) {
                board[i][j] = line[j];
            }
        }
        // Count moves
        movesCount = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != ' ') movesCount++;
        file.close();
        cout << "Game loaded from " << filename << "\n";
    }

public:
    TicTacToe() {
        initializeBoard();
        currentPlayer = 'X';
        movesCount = 0;
    }

    void play() {
        cout << "Welcome to Tic-Tac-Toe!\n";
        cout << "Player 1: X\nPlayer 2: O\n";
        printBoard();

        while (true) {
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (!isValidMove(row, col)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;
            movesCount++;
            printBoard();

            if (checkWin()) {
                cout << "Player " << currentPlayer << " wins! Congratulations!\n";
                break;
            }

            if (checkDraw()) {
                cout << "Game is a draw!\n";
                break;
            }

            switchPlayer();
        }
    }

    void save(const string& filename) {
        saveGameToFile(filename);
    }

    void load(const string& filename) {
        loadGameFromFile(filename);
        printBoard();
    }
};

int main() {
    TicTacToe game;

    char choice;
    cout << "Do you want to load a saved game? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        game.load("tictactoe_save.txt");
    }

    game.play();

    cout << "Do you want to save the game? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        game.save("tictactoe_save.txt");
    }

    return 0;
}