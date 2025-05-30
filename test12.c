#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int board[MAX][MAX];
int N;

void printSolution() {
    printf("One of the solutions:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
        printf("\n");
    }
}

bool isSafe(int row, int col) {
    // Check this row (left side)
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal (left)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal (left)
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(int col) {
    if (col >= N)
        return true; // All queens placed

    for (int row = 0; row < N; row++) {
        if (isSafe(row, col)) {
            board[row][col] = 1; // Place queen

            if (solveNQueens(col + 1))
                return true; // Next column

            board[row][col] = 0; // Backtrack
        }
    }

    return false; // No valid position found
}

int main() {
    printf("Enter value of N (N <= 10): ");
    scanf("%d", &N);

    if (solveNQueens(0))
        printSolution();
    else
        printf("No solution exists.\n");

    return 0;
}
