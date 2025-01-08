#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayGrid(char grid[3][3]);
int checkWin(char grid[3][3]);
void playerMove(char grid[3][3], char symbol);

int main() {
    char grid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int turn = 0;
    int winner = 0;

    printf("Tic Tac Toe Game\n");

    while (turn < 9 && winner == 0) {
        displayGrid(grid);
        if (turn % 2 == 0) {
            printf("Player 1 (X) Turn:\n");
            playerMove(grid, 'X');
        } else {
            printf("Player 2 (O) Turn:\n");
            playerMove(grid, 'O');
        }
        winner = checkWin(grid);
        turn++;
    }

    displayGrid(grid);
    if (winner == 1) {
        printf("Player 1 (X) Wins!\n");
    } else if (winner == 2) {
        printf("Player 2 (O) Wins!\n");
    } else {
        printf("It's a Draw!\n");
    }

    return 0;
}

void displayGrid(char grid[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", grid[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWin(char grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ') {
            return grid[i][0] == 'X' ? 1 : 2;
        }
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ') {
            return grid[0][i] == 'X' ? 1 : 2;
        }
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ') {
        return grid[0][0] == 'X' ? 1 : 2;
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ') {
        return grid[0][2] == 'X' ? 1 : 2;
    }
    return 0;
}

void playerMove(char grid[3][3], char symbol) {
    int row, col;
    while (1) {
        printf("Enter row (0-2) and column (0-2): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ') {
            grid[row][col] = symbol;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}
