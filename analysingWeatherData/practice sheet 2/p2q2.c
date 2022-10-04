/*  Program to read in numbers and get their average.

    Written by JD, 5.2.2021.
*/


#include <stdio.h>
#include <stdlib.h>
#include "library.h"

#define MAX_SIZE 10


int main(void)
{
    double average = 0;
/*  Result of the average function  */

    int numbers[MAX_SIZE];
/*  Numbers to be averaged  */

/*  Read in the numbers, ...  */
    enterNumbers(numbers, MAX_SIZE);

/*  ... get the average ...  */
    average = avg(numbers, MAX_SIZE);

/*  ... and print out the result.  */
    printf("\nThe average is: %.2f.\n", average);

    return 0;
}
