#include <iostream>
#include <vector>

using namespace std;

// Function to print the tic-tac-toe board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 5; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < 5; ++j) {
                if (j % 2 == 0) {
                    cout << " " << board[i / 2][j / 2] << " ";
                }
                else {
                    cout << "|";
                }
            }
        }
        else {
            cout << "-----------";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// Function to play the game
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize an empty 3x3 board
    char currentPlayer = 'X';
    int position;

    // Game loop
    while (true) {
        cout << "Player " << currentPlayer << "'s turn. Enter a position (1-9): ";
        cin >> position;

        // Adjust position to 0-based indexing
        position--;

        // Check if the selected position is valid and empty
        int row = position / 3;
        int col = position % 3;
        if (position >= 0 && position < 9 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Print the updated board
            printBoard(board);

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check if the board is full (tie)
            bool isFull = true;
            for (const auto& row : board) {
                for (char cell : row) {
                    if (cell == ' ') {
                        isFull = false;
                        break;
                    }
                }
                if (!isFull) {
                    break;
                }
            }
            if (isFull) {
                cout << "It's a tie!" << endl;
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

// Main function
int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player X starts the game." << endl;

    printBoard(vector<vector<char>>(3, vector<char>(3, ' '))); // Print an empty board with boundaries

    playGame();

    return 0;
}
