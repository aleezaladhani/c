#include <stdio.h>

int main()
{
    /* Assigning memory space to the grade entered */
    int grade;

    /* Promping and allowing users to input integers for their grade */
    printf("\nPlease enter your grade in the form of a percentage: \t");
    scanf("%d", &grade);

    /* Nested if/else structures to find and print what letter grade the user earned. */
    if (grade >= 90)
        printf("You get a 10. \n\n");
    else if (grade >= 85)
        printf("You get a 9. \n\n");
    else if (grade >= 80)
        printf("You get an 8. \n\n");
    else if (grade >= 75)
        printf("You get a 7. \n\n");
    else if (grade >= 70)
        printf("You get a 6. \n\n");
    else if (grade >= 65)
        printf("You get a 5. \n\n");
    else if (grade >= 60)
        printf("You get a 4. \n\n");
    else if (grade >= 55)
        printf("You get a 3. \n\n");
    else if (grade >= 50)
        printf("You get a 2. \n\n");
    else if (grade >= 40)
        printf("You get a 1. \n\n");
    else if (grade <= 39)
        printf("You get a 0. \n\n");

    return 0;
}
