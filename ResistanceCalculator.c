#include <stdio.h>
#include <math.h>

#define CALCULATE_RESISTANCE 1
#define HELP_MENU 2
#define EXIT 3

int program_Menu();
int calculating_Resistance();
int help_Menu();


int main()
{
    program_Menu();

    return 0;
}


int program_Menu()
{
    int userInput;

    /* Prompting the user to enter an option */
    printf("\nPlease choose an option:\n");
    printf("\t1.  Calculate resistance value\n", CALCULATE_RESISTANCE);
    printf("\t2.  Help\n", HELP_MENU);
    printf("\t3.  Exit\n", EXIT);

    scanf("%d", &userInput);

    switch (userInput)
    {
        case CALCULATE_RESISTANCE:
            /* Calling the calculating_Resistance function */
            calculating_Resistance();
            break;

        case HELP_MENU:
            /* Calling the help_Menu function */
            help_Menu();
            break;

        case EXIT:
            /* Terminating the program */
            break;

        default:
            printf("Error! Invalid input. Please Try again.\n");
            /* Reprompting the user to choose an option */
            program_Menu();
    }
    return 0;
}


int calculating_Resistance()
{
    float band_1, band_2;
    int band_3, band_4;
    float resistance;

    printf("\nCalculating the Resistance Value\n");

    /* Printing the Resistor color code table */
    printf("\n\tHere is a chart for your reference.\n");
    printf("\t\tColour\t   1st Band\t   2nd Band\t   3rd Band(M)\t   4th Band (T)\n");
    printf("\t\tBlack\t\t0\t\t0\t\t0\n\t\tBrown\t\t1\t\t1\t\t1\n\t\tRed\t\t2\t\t2\t\t2\n\t\tOrange\t\t3\t\t3\t\t3\n\t\tYellow\t\t4\t\t4\t\t4\n\t\tGreen\t\t5\t\t5\t\t5\n\t\tBlue\t\t6\t\t6\t\t6\n\t\tViolet\t\t7\t\t7\t\t7\n\t\tGrey\t\t8\t\t8\t\t8\n\t\tWhite\t\t9\t\t9\t\t9\n\t\tGold\t\t\t\t\t\t-1\t\t5\n\t\tSilver\t\t\t\t\t\t-2\t\t10\n\n");

    /* Prompting the user to enter their resistor colours */
    printf("Please enter the colours of your resistance bands with the values in the above table.\n");

    scanf("%f", &band_1);
    scanf("%f", &band_2);
    scanf("%d", &band_3);
    scanf("%d", &band_4);

    /* Reprompting the user to input the band 1 value if the current one is invalid */
    while ( band_1<0 || band_1>9 )
    {
        printf("Whoops! That is not an option for band 1, try again\n");
        printf("Please enter the colour of your first resistance band:\n");
        scanf("%f", &band_1);
    }

    /* Reprompting the user to input the band 2 value if the current one is invalid */
    while ( band_2<0 || band_2>9 )
    {
        printf("Whoops! That is not an option for band 2, try again\n");
        printf("Please enter the colour of your second resistance band:\n");
        scanf("%f", &band_2);
    }

    /* Reprompting the user to input the band 3 value if the current one is invalid */
    while ( band_3<-2 || band_3>9 )
    {
        printf("Whoops! That is not an option for band 3, try again\n");
        printf("Please enter the colour of your third resistance band:\n");
        scanf("%d", &band_3);
    }

    /* Reprompting the user to input the band 4 value if the current one is invalid */
    while ( band_4!=5 && band_4!=10 )
    {
        printf("Whoops! That is not an option for band 4, try again\n");
        printf("Please enter the colour of your fourth resistance band:\n");
        scanf("%d", &band_4);
    }

    /* Calculating resistance in GigaOhms */
    if (band_3==9)
        {
            resistance = (band_1 * 10) + band_2;
            printf("The resistance value is %2.0f ~ %d GigaOhms\n", resistance, band_4);
        }

    /* Calculating resistance in MegaOhms */
    else if ((band_3 < 9) && (band_3 > 6))
    {
        band_3 = band_3 - 6;
        resistance = band_1 + (band_2 * 0.10);
        printf("The resistance value is %2.1f x10^%d ~ %d MegaOhms\n", resistance, band_3, band_4);
    }
    else if (band_3==6)
    {
        resistance = (band_1 * 10) + band_2;
        printf("The resistance value is %2.0f ~ %d MegaOhms\n", resistance, band_4);
    }

    /* Calculating resistance in KiloOhms */
    else if ((band_3 < 6) && (band_3 > 3))
    {
        band_3 = band_3 - 3;
        resistance = band_1 + (band_2 * 0.10);
        printf("The resistance value is %2.1f x10^%d ~ %d KiloOhms\n", resistance, band_3, band_4);
    }
    else if (band_3==3)
    {
        resistance = (band_1 * 10) + band_2;
        printf("The resistance value is %2.0f ~ %d KiloOhms\n", resistance, band_4);
    }

    /* Calculating resistance in Ohms */
    else if ((band_3 < 3) && (band_3 > 0))
    {
        resistance = band_1 + (band_2 * 0.10);
        printf("The resistance value is %2.1f x10^%d ~ %d Ohms\n", resistance, band_3, band_4);
    }
    else if (band_3==0)
    {
        resistance = band_1 + (band_2 * 0.10);
        printf("The resistance value is %2.0f ~ %d Ohms\n", resistance, band_4);
    }
    else
    {
        resistance = band_1 + (band_2 * 0.10);
        printf("The resistance value is %2.1f x10^%d ~ %d Ohms\n", resistance, band_3, band_4);
    }

    program_Menu();

    return 0;
}


int help_Menu()
{
    printf("\nHelp Menu\n\n");

    printf("This program is used to simulate a resistor in the sense that when given the four band colours, it will calculate the resistance between the two ends in it's circuit.\n\n");

    printf("It begins by providing three options:\n");
    printf("\n\tPlease choose an option:\n");
    printf("\t\t1.  Calculate resistance value\n");
    printf("\t\t2.  Help\n");
    printf("\t\t3.  Exit\n");

    /* Explaining the three options */
    printf("\nWhen option 1 is entered, the program will begin the resistor simulation.\n");
    printf("\tWhen calculating the resistance, a chart is provided for reference as to what numbers to input for each colour. \n\tHere, the first two columns represent the colours of the bands.\n\tThe third column represents the multiplier (x10^n) where 10 and 11 are representing -1 and -2 respecively.\n\tThe fourth column represents the tolerance of the resistor, also known as the accuracy of the resistor with 1 and 2 representing plus or minus 5 and 10 respectively.\n");
    printf("\tThe program will print the resistance in the easiest form to read by converting ohms to kilo, mega, and giga ohms as required.\n\n");

    printf("When option 2 is entered, this help menu will be opened and explains both how to use the program and how the program works.\n");
    printf("\nWhen option 3 is entered, the program will be terminated.\n");

    /* Reprompting the user to choose an option */
    printf("\nLet's get started!");

    program_Menu();

    return 0;
}
