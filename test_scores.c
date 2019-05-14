/* test_scores.c */
/* This program will allow the user to enter up to 100 test scores. Once scores
   are entered, they will be sorted and the average, high and low score will be
   calculated. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  /* all of your same data types grouped together. */
  double score_array[100];
  double entered_score=0.0, temp=0.0;
  double high=0.0, low=100.0, average=0.0, sum=0.0;

  int i=0,j=0,good_input=0, bad_input=0;
  int score_cnt=0;

  char user_input[256];

  /* loop until the user types a -1 or there are 100 scores */
  while ((entered_score != -1.0) && (score_cnt < 100))
    {
      good_input = 0; /* set to false */

      /* error check user input: allow user to enter characters
      and then check the characters and convert as necessary. */
      while (!good_input)
	{
	  bad_input = 0;
	  printf("\nEnter a score (-1 to stop): ");
	  /* scan a character string into the character array
	     user_input. */
	  scanf("%s", user_input);

	  /* check all the characters in the string for the
	     occurence of an alpha or control char.
	     **** Notice the end condition of the for loop,
	     *(user_input + i). This is the pointer method for
	     accessing array element i in the user_input array. */
	  for (i = 0; *(user_input+i); ++i)
	    {
	      /* if the character is a letter or cntrl
		 character this is bad input */
	      if ((isalpha(*(user_input+i))) ||
		  (iscntrl(*(user_input+i))))
		bad_input = 1;
	      if (bad_input) break;
	    }

	  if (!bad_input)
	    {
	      /* translate the string to a float */
	      entered_score = atof(user_input);
	      /* error check float */
	      if (((entered_score>0) &&
		   (entered_score<=100)) ||
		  (entered_score == -1))
		good_input = 1;
	      else
		good_input = 0;
	    }
	  else
	    {
	      /* print an error and try again */
	      printf("Incorrect input. Try again (-1 to quit).\n");
	      good_input = 0;
	    }
	} /* While not good input */

      if (entered_score != -1)
	{
	  /* now have good input, add it to the array */
	  score_array[score_cnt] = entered_score;
	  score_cnt++;

	}
    } /* while not -1 or a 100 scores entered */

  if (score_cnt)
    {
      /* before sorting calculate the average, high and low */
      for (i = 0; i < score_cnt; i++)
	{
	  sum += *(score_array+i);
	  if (*(score_array+i) > high)
	    high = *(score_array+i);
	  if (*(score_array+i) < low)
	    low = *(score_array+i);
	}

      average = sum/score_cnt;

      /* now lets sort the scores using the bubble sort */
      /* slow but ok for small data sets */
      for (i = 1; i < score_cnt; ++i)
	{
	  for (j = score_cnt-1; j >= i; --j)
	    {
	      if (*(score_array+j-1) > *(score_array+j))
		{
		  temp = *(score_array+j-1);
		  *(score_array+j-1) = *(score_array+j);
		  *(score_array+j) = temp;
		} /* end if */
	    } /* for */
	} /* for */

      /* print the results */
      printf("Number of scores entered was %d.\n", score_cnt);
      printf("The sorted list of scores:\n");
      for (i = 0; i < score_cnt; i++)
	printf("\t%f\n", *(score_array+i));

      printf("The high score was %f.\n", high);
      printf("The low score was %f.\n", low);
      printf("The averag score was %f.\n", average);
    } /* if any scores */
  else
    printf("No scores entered. Bye.\n");

  return EXIT_SUCCESS;
}
