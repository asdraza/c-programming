/*  This file contains the code for the enterNumbers and avg functions.
    Written by JD, 5.2.2021.
*/


#include <stdio.h>
#include "library.h"


void enterNumbers(int numbers[], int maxSize)
/*  This function allows the user to enter a set of integers from the standard input.
    It takes as input:
      - numbers: the numbers to be entered;
      - maxSize: maximum number of numbers to be entered.
*/
{
    int i = 0;

    for(i =0;  i < maxSize;  i++)
    {
        printf("Enter a number (an integer): ");
        scanf("%d", &numbers[i]);
    }
}


double avg(int numbers[], int size)
/*  This function calculates the average of a set of integers.
    It takes as input: 
      - numbers: array holding the numbers to be averaged;
      - size: the number of numbers to be averaged.
    It returns the result of the average function.
*/
{
    int i = 0;
    double sum = 0;

    for(i = 0;  i < size;  i++)
        sum += numbers[i];

    return sum/size;
}
