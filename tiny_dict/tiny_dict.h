/*
 * tiny_dict.h
 *
 *  Created on: Jul 11, 2017
 *      Author: senchuk
 */

#define SENTENCE_MAX 3
#define ENTRY_MAX 50

/* the following typedefs are just used to simplify
 * how we refer to the sturucture. Just think of
 * typedefs as aliasas.  The first typedef replaces
 * the declaration struct dict-enrty with dict-entry.
 * The second makes it simpler to refer to a dict-entry
 * pointer. */
typedef struct dict_entry dict_entry;
typedef dict_entry *dict_entryp;
struct dict_entry {
	char keyword[80];
	char sentence[SENTENCE_MAX][80];
} dictionary[ENTRY_MAX];

int entry_count=0;
