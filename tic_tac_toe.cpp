
#include <iostream>
using namespace std;

char board[9] = {'1','2','3','4','5','6','7','8','9'};

// Display the game board
void displayBoard()
{
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << "\n";
}

// Check whether a player has won
bool checkWinner()
{
    int win[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (int i = 0; i < 8; i++)
    {
        if (board[win[i][0]] == board[win[i][1]] &&
            board[win[i][1]] == board[win[i][2]])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int choice;
    char player = 'X';
    int moves = 0;

    cout << "===== TIC-TAC-TOE GAME =====\n";

    while (moves < 9)
    {
        displayBoard();

        cout << "Player " << player;
        cout << ", enter position (1-9): ";
        cin >> choice;

        // Check valid position
        if (choice < 1 || choice > 9)
        {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        // Check whether position is already occupied
        if (board[choice - 1] == 'X' || board[choice - 1] == 'O')
        {
            cout << "Position already occupied! Try again.\n";
            continue;
        }

        // Place player's symbol
        board[choice - 1] = player;
        moves++;

        // Check winner
        if (checkWinner())
        {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        // Change player
        if (player == 'X')
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }
    }

    displayBoard();
    cout << "Game Draw!\n";

    return 0;
}

