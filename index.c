/* index.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  int int_array[5] = {1,2,3,4,5};
  int i = 0;

  int *int_ptr;

  printf("The address of int_array is %p.\n", int_array);
  printf("The value of the 2nd member is %d.\n",
	 int_array[1]);
  printf("The value of the 3rd member is %d.\n",
	 *(int_array+2));

  int_ptr = int_array;

  printf("The address of int_ptr is now %p.\n", int_ptr);
  printf("The value of the 2nd member is %d.\n",
	 *(int_ptr+1));
  printf("The value of the 3rd member is %d.\n",
	 *(int_ptr+2));

  return 0;
}
