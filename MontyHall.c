#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void program_Menu();
void game_Mode();
void research_Mode();
int random_Generator();


int main()
{
    program_Menu();

    return 0;
}

void program_Menu()
{
    int userInput;

    /* Prompting the user to enter an option */
    printf("\nPlease choose an option:\n");
    printf("\t1.  Game Mode\n");
    printf("\t2.  Research Mode\n");
    printf("\t3.  Exit\n");

    scanf("%d", &userInput);

    switch (userInput)
    {
        case 1:
            /* Calling the game_Mode function */
            game_Mode();
            break;

        case 2:
            /* Calling the research_Mode function */
            research_Mode();
            break;

        case 3:
            /* Terminating the program */
            break;

        default:
            printf("Error! Invalid input. Please try again.\n");
            /* Reprompting the user to choose an option */
            program_Menu();
    }
}

void game_Mode()
{
    static int numberOfWins=0;
    static int numberOfGames=0;

    int firstDoor, revealedDoor, prizeDoor, switchDoors, finalDoor, j, wins;

    /* Prompting the user to choose a door */
    printf("\nIt's game time! \nHere you have three doors, one of which hides a prize, the other two hide nothing.\n\n\tPlease choose a door:\n");
    printf("\t\tDoor 1\n");
    printf("\t\tDoor 2\n");
    printf("\t\tDoor 3\n");

    scanf("%d", &firstDoor);

    /* Reprompting the user to choose an option until it is within the given range */
    while (firstDoor < 1 || firstDoor > 3)
    {
        printf("Error! Invalid input. Please Try again.\n");
        scanf("%d", &firstDoor);
    }

    /* Assigning a random number (given by the random_Generator function to the prize door and the revealed door */
    prizeDoor = random_Generator();
    revealedDoor = random_Generator();

    if (revealedDoor)
        {
            /* Recalculating the revealed door until it is not equal to the prize door or the user's choice */
            while ((revealedDoor == prizeDoor) || (revealedDoor == firstDoor))
            {
                revealedDoor = random_Generator();
            }

            /* Prompting the user to choose whether to switch doors or stick with their first choice */
            printf("Door %d does not contain a prize... \nWould you like to switch your door?\n", revealedDoor);
            printf("\t1. Yes! Switch doors!\n");
            printf("\t2. No! Stick with my current door!\n");

            scanf("%d", &switchDoors);

            switch (switchDoors)
            {
                case 1:
                    for(j = 1; j <= 3; j++)
                    {
                        if ((j != revealedDoor) && (j != firstDoor))
                            finalDoor = j;
                    }
                    break;

                case 2:
                    finalDoor = firstDoor;
                    break;

                default:
                    printf("Error! Invalid input! Please re-enter your choice: \t");
                    scanf("%d", &switchDoors);
            }

            if (finalDoor == prizeDoor)
            {
                numberOfWins++;
                numberOfGames++;

                printf("Congratulations! You won!\n\n");
                printf("You have played %d games and won %d times\n", numberOfGames, numberOfWins);
            }

            else
            {
                numberOfGames++;

                printf("Sorry, you lost! The prize was behind door %d\n\n", prizeDoor);
                printf("You have played %d games and won %d times", numberOfGames, numberOfWins);
            }
        }

    program_Menu();
}

void research_Mode()
{
    float wins;
    int strategy;
    int N, i;
    int prizeDoor;
    float percentage;

    wins = 0;

    /* Prompting the user to choose which strategy they would like to simulate */
    printf("\nWhich strategy would you like to simulate?\n");
    printf("\t1. Never switch\n");
    printf("\t2. Always switch\n");

    scanf("%d", &strategy);

    /* Reprompting the user to choose an option until it is within the given range */
    while (strategy < 1 || strategy > 2)
    {
        printf("Error! Invalid input! Please enter again:\t");
        scanf("%d", &strategy);
    }

    /* Prompt user to enter total amount of games they would like to simulate */
    printf("Please enter the total number of games you would like to simulate: \t");
    scanf("%d", &N);

    /* Reprompting the user to enter an integer until it is greater than or equal to one */
    while (N<1)
    {
        printf("Invalid input! Please enter again:\t");
        scanf("%d", &N);
    }

    for (i=0; i<N; i++)
    {
        prizeDoor = random_Generator();

        if (strategy == 1)
        {
            if (prizeDoor == 1)
            {
                wins++;
            }
        }

        else if (strategy == 2)
        {
            if (prizeDoor != 1)
            {
                wins++;
            }
        }
    }

    /* Calculating the percentage of games won out of the total number simulated */
    percentage = (wins/N)*100.0;

    printf("\n\t%2.2f games were won out of %d games played\n\n", wins, N);
    printf("\tThe percentage of games won is therefore %2.2f%%\n\n", percentage);

    program_Menu();

}

int random_Generator()
{
    /* Randomly generating a number between 1 and 3 */
    return 1+rand()%3;
}
