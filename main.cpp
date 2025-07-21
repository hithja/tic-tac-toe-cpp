#include <iostream>
using namespace std;

const int BOARD_SIZE = 9;

void instruction() {
    cout << "The board: " << endl;
    cout << "| 0 | 1 | 2 |\n| 3 | 4 | 5 |\n| 6 | 7 | 8 |\n";
}

void initBoard(char (&board)[BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = ' ';
    }
}

void showBoard(char board[BOARD_SIZE]) {
    cout << endl;
    for (int i = 0; i < BOARD_SIZE; i+=3) {
        cout << "| " << board[i] << " | " << board[i+1] << " | " << board[i+2] << " | ";
        cout << endl;
    }
}

bool isLegal(int pos, char board[BOARD_SIZE]) {
    return board[pos] == ' ';
}

bool makeMove(char (&board)[BOARD_SIZE], char figure, int pos) {
    if (isLegal(pos, board)) {
        board[pos] = figure;
        return true;
    }
    return false;
}

bool isBoardFull(char board[BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == ' ') {
            return false;
        } 
        
    }
    return true;
}

char isWin(char board[BOARD_SIZE]) {
    const int WIN_ROWS[8][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4,6} };
    
    for (int i = 0; i < 8; i++)
    {
        if ((board[WIN_ROWS[i][0]] != ' ') && (board[WIN_ROWS[i][0]] == board[WIN_ROWS[i][1]]) && (board[WIN_ROWS[i][1]] == board[WIN_ROWS[i][2]])) {
            return board[WIN_ROWS[i][0]];
        }
    }
    
    return ' ';
}

int computerMove(char board[BOARD_SIZE]) {
    int BEST_MOVES[9] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

    for (int &x: BEST_MOVES) {
        if (isLegal(x, board)) {
            return x;
        }
    }
}

int main() {
    char board[BOARD_SIZE];
    initBoard(board);

    instruction();

    do
    {
        test:
        cout << "[X] Enter position: ";
        int pos;
        cin >> pos;
        if (!(pos > 8 || pos < 0)) {
            makeMove(board, 'X', pos);
            showBoard(board);
        }
        else {
            cout << "Invalid position!" << endl;
            goto test;
        }

        if (isWin(board) != ' ') {
            cout << isWin(board) << " is the winner!" << endl;
            break;
        }

        makeMove(board, 'O', computerMove(board));
        showBoard(board);
        if (isWin(board) != ' ') {
            cout << isWin(board) << " is the winner!" << endl;
            break;
        }

    } while (!isBoardFull(board));
    

    return 0;
}