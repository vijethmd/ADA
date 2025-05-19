#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];
int N;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int row) {
    if (row == N) {
        printSolution();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    printf("Enter the value of N (number of queens): ");
    scanf("%d", &N);

    if (N < 1 || N > MAX) {
        printf("N must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("\nSolutions to the %d-Queens problem:\n\n", N);
    solve(0);

    return 0;
}
