#include <iostream>
using namespace std;

// Function to display the current state of the board
void displayBoard(char gameBoard[3][3]) {
    cout << "-----------------" << endl;
    for (int row = 0; row < 3; row++) {
        cout << " | ";
        for (int col = 0; col < 3; col++) {
            cout << gameBoard[row][col] << " | ";
        }
        cout << endl << "-----------------" << endl;
    }
}

// Function to check for a win or draw condition
int checkGameStatus(char gameBoard[3][3]) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if ((gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ') ||
            (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' ')) {
            return (gameBoard[i][0] == 'O' || gameBoard[0][i] == 'O') ? 1 : 2;
        }
    }
    // Check diagonals for a win
    if ((gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != ' ') ||
        (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != ' ')) {
        return (gameBoard[1][1] == 'O') ? 1 : 2;
    }

    // Check for draw
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (gameBoard[row][col] == ' ') {
                return 3; // Game is still ongoing
            }
        }
    }
    return 0; // Draw
}

// Function to manage the game play
void startGame() {
    char gameBoard[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player1Symbol, player2Symbol;
    int moveCount = 0;

    // Ensure valid input for player1's symbol
    do {
        cout << "Player 1, enter your choice (O or X): ";
        cin >> player1Symbol;
        if (player1Symbol != 'O' && player1Symbol != 'X') {
            cout << "Invalid choice. Please enter 'O' or 'X'." << endl;
        }
    } while (player1Symbol != 'O' && player1Symbol != 'X');

    // Assign the other symbol to player2
    player2Symbol = (player1Symbol == 'O') ? 'X' : 'O';
    cout << "Player 2, you are: " << player2Symbol << endl;

    // Display the initial empty board
    displayBoard(gameBoard);

    // Main game loop
    while (moveCount < 9) {
        int row, col;
        // Determine current player
        char currentPlayerSymbol = (moveCount % 2 == 0) ? player1Symbol : player2Symbol;
        cout << "Player " << ((moveCount % 2 == 0) ? "1" : "2") << " (" << currentPlayerSymbol << "), enter the row and column (0, 1, 2): ";
        cin >> row >> col;

        // Validate the move
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || gameBoard[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Place the player's symbol on the board
        gameBoard[row][col] = currentPlayerSymbol;
        displayBoard(gameBoard);

        // Check for win or draw
        int gameState = checkGameStatus(gameBoard);
        if (gameState == 1) {
            cout << "Player 1 (with O) won the game!" << endl;
            break;
        } else if (gameState == 2) {
            cout << "Player 2 (with X) won the game!" << endl;
            break;
        } else if (gameState == 0) {
            cout << "Game drawn." << endl;
            break;
        }
        moveCount++;
    }
}

int main() {
    int playAgain = 1;
    do {
        startGame();
        cout << "Do you want to play another game (yes - 1 / no - 0)? ";
        cin >> playAgain;
    } while (playAgain != 0);

    return 0;
}
