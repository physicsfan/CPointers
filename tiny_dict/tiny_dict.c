/*
 * tiny_dict.c - a fixed length dictionary
 *
 *  Created on: Jul 11, 2017
 *      Author: senchuk
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tiny_dict.h"

/* ***************************************************
 * FUNCTION NAME: clean_stdin
 * PURPOSE: flushes the \n out of the buffer because
 *    fflush(stdin) is not defined. But fflush(stdout)
 *    is ok.
 * INPUT: none
 * OUTPUT: none
 * AUTHOR: ASMS
 * ************************************************** */
void clean_stdin()
{
    int c;

    do {
      c = getchar();
    } while (c != '\n' && c != EOF);
}
/* **************************************************
 * FUNCTION NAME: get_definition
 * PURPOSE: uses gets to receive input of a definition
 * 	from the user.
 * INPUT: none.
 * OUTPUT: a dict_entry structure.
 * AUTHOR: ASMS
 * ************************************************* */
dict_entry get_definition()
{
        int i;
	dict_entry out_entry;

	printf("\n Enter keyword: ");
 	fflush(stdout);
	/* since out_entry is a local structure variable and
	 * not a structure pointer we access
	 * its members using the dot operator.
	 */
	gets(out_entry.keyword);
        fseek(stdin,0,SEEK_END);

	printf("\n Enter definition of up to %d lines.", SENTENCE_MAX);
	fflush(stdout);
	for (i = 0; i < SENTENCE_MAX; i++)
	{
		printf("\n Line %d: ", i+1);
		fflush(stdout);
		gets(out_entry.sentence[i]);
		fseek(stdin,0,SEEK_END);
	}
	return(out_entry);
}
/* ***************************************************
 * FUNCTION NAME: display_entry
 * PURPOSE: prints to stdout the members of the dictionary
 * 	structure.
 * INPUT: display_rec - a pointer to a dict_entry structure.
 * OUTPUT: none.
 * AUTHOR: ASMS
   *************************************************** */
/* display_entry.
 * Notice that display_rec is a structure pointer.  This will
 * change how we access the members of the structure.
 */
void display_entry(dict_entryp display_rec)
{

	int i;

	/* since display_rec is a structure pointer we use
	 * the arrow operator to access the members.
	 */
	printf("Keyword: %s\n", display_rec->keyword);
	fflush(stdout);
	for (i = 0; i < SENTENCE_MAX; i++)
	{
		printf("%s\n", display_rec->sentence[i]);
	}
}

/* ***************************************************
 * FUNCTION NAME: list_entries
 * PURPOSE: to print all the dictionary entries currently
 * 	in the dictionary.
 * INPUT: none.
 * OUTPUT: none.
 * AUTHOR: ASMS
   *************************************************** */
/* list_entries */
void list_entries()
{
	int i;

	printf("Dictionary Entries\n");

	/* dictionary is a global array of structures so we
	 * access it with the dot operator. */
	for (i=0; i < entry_count; i++)
		printf("%s\n", dictionary[i].keyword);
	
	printf("****** End of Entries ******\n");
}

/* ****************************************************
 * FUNCTION NAME: find_entry
 * PURPOSE: locates an entry in the dictionary array of
 * 	 structures that matches the keyword passed in.
 * INPUT: keyword - a character string.
 * OUTPUT: an integer which is the index if the matching
 *   entry in the array of dictionary structures.
 * AUTHOR: ASMS
 * *************************************************** */
int find_entry(char *keyword)
{
	int i;

	for (i=0; i < entry_count; i++)
	{
		if (!(strcmp(keyword,dictionary[i].keyword)))
			return(i);
	}
	return(-1);
}
/* ****************************************************
 * FUNCTION NAME: remove_entry
 * PURPOSE: removes a entry from the dictionary.
 * INPUT: entry_position - an integer specifying the position
 *   of the entry in the array "dictionary".
 * OUTPUT: none
 * AUTHOR: ASMS
 * *************************************************** */
void remove_entry(int entry_position)
{

	int i;
	
	/* Decrease the number of entries in the dictionary by one */ 
	entry_count--;

	/* Remove entry by shifting all subsequent entries up one position. 
	   This algorithm preserves the order of the dictionary. */
	for(i = entry_position; i < entry_count; i++)
	  *(dictionary + i) = *(dictionary + i + 1);

}
/* ****************************************************
 * FUNCTION NAME: main for tiny_dict.c
 * PURPOSE: present a menu of the available functions,
 *   retrieve the response from the user and call the
 *   appropriate function.
 * INPUT: none.
 * OUTPUT: none.
 * AUTHOR: ASMS
 * **************************************************** */
int main(void)
{
        int done=0, mistakes=0;
	int choice=0,idx=0;
	char display_kw[80];

	while (!done && mistakes != 3)
	{
		printf("<<<< Your-Webster >>>>\n");
		printf("1) enter a definition.\n");
		printf("2) list all entries.\n");
		printf("3) display an entry.\n");
		printf("4) remove an entry.\n");
		printf("5) exit.\n");
		printf("choice: ");
 		fflush(stdout);
		scanf("%d", &choice);
	        fseek(stdin,0,SEEK_END);			/* this is so the \n gets flushed
									out of the buffer */
		switch (choice)
		{
		case 1:
			if (entry_count < ENTRY_MAX)
			{
				dictionary[entry_count] = get_definition();
				entry_count++;
			}
			else
				printf("\n%d is Maximum number of entries!\n", ENTRY_MAX);
			break;
		case 2:
			list_entries();
			break;
		case 3:
			printf("\n Enter keyword to display: ");
			fflush(stdout);
			gets(display_kw);
			fseek(stdin,0,SEEK_END);
			if ((idx = find_entry(display_kw)) >= 0)
				display_entry(&(dictionary[idx]));
			else
				printf("\n %s not found.\n", display_kw);
			break;
		case 4:
			printf("\n Enter keyword to remove: ");
			fflush(stdout);
			gets(display_kw);
			fseek(stdin,0,SEEK_END);
			if ((idx = find_entry(display_kw)) >= 0)
			        remove_entry(idx);
			else
				printf("\n %s not found.\n", display_kw);
			break;
		case 5:
		        printf("\n Exitting...\n");
			done = 1;
			break;
		default:
			printf("\nInvalid choice - try again.\n");
			mistakes++;
		} /* switch */
	} /* while not done */

	return EXIT_SUCCESS;
}
