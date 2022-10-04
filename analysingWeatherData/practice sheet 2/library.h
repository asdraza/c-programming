/*  This file is the header file for library.c.
    Written by JD, 5.2.2021.
*/


#ifndef LAB2_LIBRARY_H
#define LAB2_LIBRARY_H

/*  This function allows the user to enter a set of integers from the standard input.
    It takes as input:
      - numbers: the numbers to be entered;
      - maxSize: maximum number of numbers to be entered.
*/


double avg(int numbers[], int size);
/*  This function calculates the average of a set of integers.
    It takes as input: 
      - numbers: array holding the numbers to be averaged;
      - size: the number of numbers to be averaged.
    It returns the result of the average function.
*/
void insertNumbers(int numbers[], int maxSize);

#endif  //LAB2_LIBRARY_H
