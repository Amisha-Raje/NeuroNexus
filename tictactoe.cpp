#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
void displayBoard(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, char player, int row, int col);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
void switchPlayer(char& currentPlayer);
bool playAgain();
void makeComputerMove(vector<vector<char>>& board, char computerPlayer);
int main() {
    srand(static_cast<unsigned int>(time(0)));
    do {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';
        bool gameWon = false;
        bool gameDraw = false;

        do {
            displayBoard(board);

            if (currentPlayer == 'X') {
                int row, col;
                cout << "X move (row and column): ";
                cin >> row >> col;

                if (makeMove(board, currentPlayer, row, col)) {
                    gameWon = checkWin(board, currentPlayer);
                    gameDraw = checkDraw(board);
                    switchPlayer(currentPlayer);
                } else {
                    cout << "Invalid move! Try again." << endl;
                }
            } else {
                cout << "0 is making its move..." << endl;
                makeComputerMove(board, currentPlayer);
                gameWon = checkWin(board, currentPlayer);
                gameDraw = checkDraw(board);
                switchPlayer(currentPlayer);
            }

        } while (!gameWon && !gameDraw);

        displayBoard(board);

        if (gameWon) {
            if (currentPlayer == 'X') {
                cout << "Congratulations! 0 win!" << endl;
            } else {
                cout << "Congratulations! X win!" << endl;
            }
        } else {
            cout << "It's a draw! Well played!" << endl;
        }

    } while (playAgain());

    return 0;
}


void displayBoard(const vector<vector<char>>& board) {
   // cout << "    "<<endl;
    cout<<"    0   1   2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << "   ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "   -----------" << endl;
        }
    }
    cout << endl;
}



bool makeMove(vector<vector<char>>& board, char player, int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false; 
    }

    board[row][col] = player;
    return true;
}

bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true; 
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true; 
    }

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
   
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void makeComputerMove(vector<vector<char>>& board, char computerPlayer) {
 
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
              
                board[i][j] = computerPlayer;
                if (checkWin(board, computerPlayer)) {
                    return; 
                }
                
                board[i][j] = ' ';
            }
        }
    }

    // Check for blocking opponent's winning moves
    char opponentPlayer = (computerPlayer == 'X') ? 'O' : 'X';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
              
                board[i][j] = opponentPlayer;
                if (checkWin(board, opponentPlayer)) {
                   
                    board[i][j] = computerPlayer;
                    return;
                }
               
                board[i][j] = ' ';
            }
        }
    }

    // If no winning or blocking move is found, make a random move
    do {
        int row = rand() % 3;
        int col = rand() % 3;
        if (board[row][col] == ' ') {
            board[row][col] = computerPlayer;
            return;
        }
    } while (true);
}


bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
