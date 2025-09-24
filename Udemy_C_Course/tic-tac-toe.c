#include <stdio.h>
#include <stdlib.h>

int welcomeMessage();
int gameMenu();
int displayBoard(char board[]);
int playerMove(int player, char board[]);
int checkGameState(char board[]);

int main()
{
    welcomeMessage();

    int selection = 1;
    selection = gameMenu();
    while (selection == 1)
    {
        char board[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int player = 1;
        int winner = 0;
        int moves = 1;
        while (winner == 0 && moves < 10)
        {
            displayBoard(board);
            playerMove(player, board);
            displayBoard(board);
            winner = checkGameState(board);
            if (winner == 0)
            {
                player = player == 1 ? 2 : 1;
            }
            moves = moves + 1;
        }
        if (winner == 1)
        {
            printf(" Player %d Wins! \n", player);
        }
        else
        {
            printf("Cat's games!\n");
        };
        selection = gameMenu();
    }
    return 0;
}

int welcomeMessage()
{
    printf("Welcome To Tic-Tac-Toe in C!\n");
    return 0;
}

int gameMenu()
{
    int selection = 0;
    printf("Enter 1 to play a game or any other key to quit: ");
    scanf("%d", &selection);
    return selection;
}

int displayBoard(char board[])
{
    printf("\n");
    printf("         Tic-Tac-Toe   \n");
    printf("player 1 = X     player 2 = O \n");
    printf("----------------------------- \n");

    printf("\n");

    int i;
    for (i = 0; i < 9; i = i + 3)
    {
        printf("         %c | %c | %c \n", board[i], board[i + 1], board[i + 2]);
        if (i < 6)
        {
            printf("         --- --- ---\n");
        }
    }
    printf("\n");
}

int playerMove(int player, char board[])
{
    int move = 0;
    do
    {
        printf("Select and open space number: ");
        scanf("%d", &move);
        if (move > 0 && move <= 9)
        {
            char number = move + '0';
            if (board[move - 1] == number)
            {
                board[move - 1] = player == 1 ? 'X' : 'O';
            }
            else
            {
                printf("Invalid move. \n");
                move = 0;
            }
        }
        else
        {
            printf("Invalid move.\n");
            move = 0;
        }
    } while (move == 0);
    return 0;
}

int checkGameState(char board[])
{
    int winner = 0;
    if (
        (board[0] == board[1] && board[1] == board[2]) || // Check row 1
        (board[3] == board[4] && board[4] == board[5]) || // Check row 2
        (board[6] == board[7] && board[7] == board[8]) || // Check row 3
        (board[0] == board[3] && board[3] == board[6]) || // Check col 1
        (board[1] == board[4] && board[4] == board[7]) || // Check col 2
        (board[2] == board[5] && board[5] == board[8]) || // Check col 3
        (board[0] == board[4] && board[4] == board[8]) || // Check cross 1
        (board[2] == board[4] && board[4] == board[6])    // Check cross 2
    )
    {
        winner = 1;
    }

    return winner;
}
