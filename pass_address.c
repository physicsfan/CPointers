/* pass_address.c */
/* program investigates the use of pointers to perform the "pass by reference"
   operation in order to exchange the contents of two memory locations */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap(int *, int *);

int main(void)
{
  int shella=10, shellb=20;
  printf("Before swap, shella holds %d and shellb holds %d.\n", shella, shellb);
  swap(&shella, &shellb);
  printf("After swap, shella holds %d and shellb holds %d.\n", shella, shellb);

  return EXIT_SUCCESS;
}


void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
