
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

struct TURN{
    int peg;
    int pos;
    int occ;
};

struct PLAYER{
    int name[20];
    int turn;
};

int CoinToss()
{
    int coin;
    int coinresult;
    char coinSide[5];
    int playerSide;

    srand(time(0));
    coin = (rand() % 10) + 1;


    printf("\nTo make the game fair between players, Player 1, heads or tails? ");
    scanf("%s", coinSide);

    if (strcmp(coinSide, "tails")==0)
    {
        playerSide = 1; // player 1 guesses odd
    }
    else
    {
        playerSide = 0; // player 1 guesses even
    }
        

    coinresult = coin % 2;

    if (coinresult == playerSide) 
    {
        printf("Player 1 goes first\n"); // if correct guess
        return 1;
    }
    else
    {
        printf("Player 2 goes first\n"); // if incorrect guess
        return 2;
    }

}

int checkPeg(int *peg, int turn, int pegUsed)
{
    int i;
    for(i=0;i<turn;i++)
    {
        if (pegUsed == peg[i])
            return 1;
    }

    return 0;
}

int checkPos(int *pos, int turn, int posUsed)
{
    int i;
    for(i=0;i<turn;i++)
    {
        if (posUsed == pos[i])
            return 1;
    }

    return 0;
}
void Turn(struct TURN *gameTurn, int turn, int *gameonGoing, int *peg, int *pos)
{
    int pegUsed;
    int posUsed;
    printf("PEGS YOU CAN USE: \n");
    printf("USED PEGS: \n");
    printf("=====================================\n");
    printf("|           |           |           |\n");
    printf("|     %i    |     %i    |     %i    |\n");
    printf("|    %s    |    %s    |     %s    |\n");
    printf("|___________|___________|___________|\n");
    printf("|           |           |           |\n");
    printf("|     %i    |     %i    |     %i    |\n");
    printf("|     %s    |     %s    |     %s    |\n");
    printf("|___________|___________|___________|\n");
    printf("|           |           |           |\n");
    printf("|     %i    |     %i    |     %i    |\n");
    printf("|     %s    |     %s    |     %s    |\n");
    printf("|___________|___________|___________|\n");
    
    printf("Enter the peg you want to use: ");
    scanf("%i", &pegUsed);

    while(checkPeg(peg, turn, pegUsed) == 1)
    {
        printf("That Peg is already used!! Please try again... \n");
        printf("Enter the peg you want to use: ");
        scanf("%i", &pegUsed);
    }

    peg[turn-1] == pegUsed; // store the current peg to the peg array

    printf("Enter the position you want to use: ");
    scanf("%i", &pegUsed);

    while(checkPeg(peg, turn, pegUsed) == 1)
    {
        printf("That Position is already occupied!! Please try again... \n");
        printf("Enter the peg you want to use: ");
        scanf("%i", &pegUsed);
    }

    
}

int main()
{
    struct TURN gameTurn[9];

    int peg[9]; // pegs used
    int pos[9]; // pos used

    struct PLAYER player1;
    struct PLAYER player2;

    //  determines who's the turn A and turn B
    int firstPlayer; 

    // used to check whos the winner
    int winner = 0;

    // game condition
    int gameonGoing = TRUE;
    int turn = 0;
    int turnMod;

    printf("Enter Player 1 name: ");
    scanf("%s", player1.name);
    printf("Enter Player 2 name: ");
    scanf("%s", player2.name);

    
    firstPlayer = CoinToss();
    
     
    if (firstPlayer == 1) // player 1 goes first, player 2 goes second
    {
        printf("Player %s, you are TURN A. \n", player1.name); 
        player1.turn = 1; //  meaning player 1 wins at ODD turn

        printf("Player %s, you are TURN B. ", player2.name);
        player2.turn = 0; //  meaning player 2 wins at EVEN turn
    }
    else // player 2 goes first, player 1 goes second
    {
        printf("Player %s, you are TURN A. ", player2.name);
        player2.turn = 1; //  meaning player 2 wins at ODD turn

        printf("Player %s, you are TURN B. ", player1.name);
        player1.turn = 0; //  meaning player 1 wins at EVEN turn
    }

    while(gameonGoing == TRUE && turn < 9 && winner == 0)
    {
        turn++;
        if (firstPlayer == 1)
        {
            if (turn % 2 == 1)
            {
                printf("Turn A: Player %s", player1);
                Turn(gameTurn, turn, &gameonGoing, peg , pos);
            }
            else
            {
                printf("Turn A: Player %s", player2);
                Turn(gameTurn, turn, &gameonGoing, peg , pos);
            }
        }
        else
        {
            if (turn % 2 == 1)
            {
                printf("Turn A: Player %s", player2);
                Turn(gameTurn, turn, &gameonGoing, peg , pos);
            }
            else
            {
                printf("Turn A: Player %s", player1);
                Turn(gameTurn, turn, &gameonGoing, peg , pos);
            }
        }
        
    }
}