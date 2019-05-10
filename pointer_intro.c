/* pointer_intro.c */
/*
  Synopsis:
  The program declares a pointer variable to hold an 
  address of an integer. Then it declares an integer variable 
  "my_int", which is a continer that holds an integer.  After 
  assigning the integer to the variable, the program prints out 
  the address of the integer.  This is the unique memory address 
  where the integer is stored.  Since a pointer can store the 
  address of another container, we can put the address of integer 
  variable into the integer pointer.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{ 
  /* declare pointers and variables */
  int *integer_pointer;
  int myint;

  /* assign my_int */
  myint = 100;

  /* print address */
  printf("The address of myint is %p.\n", &myint);

  /* assign address of myint to integer_pointer */
  integer_pointer = &myint;

  /* print address held in pointer */
  printf("The integer_pointer holds the address %p.\n",
	 integer_pointer);

  return EXIT_SUCCESS;
}
