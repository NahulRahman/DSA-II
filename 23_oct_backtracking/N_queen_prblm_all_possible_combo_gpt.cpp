#include <iostream>
using namespace std;
#define N 8

int totalSolutions = 0;

void printBoard(int board[N][N]) {
    cout << "One specific combination way is" << endl << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    totalSolutions++;
    cout << endl;
}

bool isValid(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return false;
    }
    return true;
}

bool solveNQueen(int board[N][N], int col) {
    if (col >= N) {
        // When N queens are placed successfully, print the board
        printBoard(board);
        return false; // Continue searching for more solutions
    }
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (isValid(board, i, col)) {
            board[i][col] = 1;
            found = solveNQueen(board, col + 1) || found;
            board[i][col] = 0; // Backtrack
        }
    }
    return found;
}

int main() {
    int board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQueen(board, 0)) {
        cout << "Total solutions found: " << totalSolutions << endl;
    } else {
        cout << "Solution does not exist." << endl;
    }

    return 0;
}
