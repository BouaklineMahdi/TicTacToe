#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
int isMoveValid(char board[3][3], int row, int col);
int checkForWinner(char board[3][3]);
int isBoardFull(char board[3][3]);

int main() {
    char board[3][3];
    int row, col, currentPlayer = 1, moveCount = 0, winner;

    initializeBoard(board);

    do {
        // Display the current state of the board
        displayBoard(board);

        // Determine the current player (1 or 2)
        currentPlayer = (currentPlayer == 1) ? 2 : 1;

        // Get the player's move (row)
        do {
            printf("Player %d, enter the row (0 to 2): ", currentPlayer);
            scanf("%d", &row);
        } while (row < 0 || row >= 3);

        // Get the player's move (column)
        do {
            printf("Player %d, enter the column (0 to 2): ", currentPlayer);
            scanf("%d", &col);
        } while (col < 0 || col >= 3);

        // Check if the chosen move is valid
        if (!isMoveValid(board, row, col)) {
            continue;  // If not valid, ask the player to enter their move again
        }

        // Place X or O on the board
        board[row][col] = (currentPlayer == 1) ? 'X' : 'O';

        // Increment the move count
        moveCount++;

        // Check for a winner
        winner = checkForWinner(board);

        // Check for a tie
        if (moveCount == 9 && winner == 0) {
            printf("It's a tie!\n");
            break;
        }

    } while (winner == 0);

    // Display the final state of the board
    displayBoard(board);

    // Declare the winner or announce a tie
    if (winner != 0) {
        printf("Player %d wins!\n", winner);
    }

    return 0;
}

// Initialize the Tic-Tac-Toe board
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Check if the specified move is valid
int isMoveValid(char board[3][3], int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        printf("Invalid move. Try again.\n");
        return 0;
    }
    return 1;
}

// Check for a winner or a tie
int checkForWinner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            || (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return (board[i][i] == 'X') ? 1 : 2; // 1 for player X, 2 for player O
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return (board[1][1] == 'X') ? 1 : 2; // 1 for player X, 2 for player O
    }

    return 0; // No winner yet
}