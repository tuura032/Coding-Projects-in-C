// Implements a dictionary's functionality
// helper functions for speller.c
// Loads a dictionary into a hash table and then checks the spelling of a word in a document to determine if it is speller properly.
// The associated program, speller.c, returns not only misspelled words, but also how  quickly "check" can iterate through my hash
// for each word in the document being checked.

#include <stdbool.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

typedef struct node
{
    // Data type
    char word[LENGTH + 1];
    // Pointer to another node of same type
    struct node *next;
}
node;

// Create the hashtable
node *hashtable[HASHTABLE_SIZE];
node* trav;

// Create Global hashcode, from dan bernstein.
unsigned long hashcode(const void *_word)
{
  const char *str = _word;
  unsigned long hash = 5381;
  int c;

  while ((c = *str++))
  {
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  }

  return hash % HASHTABLE_SIZE;
}



// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char lowerword[LENGTH + 1];
    int l = (strlen(word));
    for (int j = 0; j < l; j++)
    {
        lowerword[j] = tolower(word[j]);
    }
    lowerword[l] = '\0';

    //figure out which "bucket to search"
    unsigned long key2 = hashcode(lowerword);
    node *cursor = hashtable[key2];
    while (cursor != NULL)
    {
        if (strcmp(lowerword, cursor->word) == 0)
            return true;
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
unsigned long wordcount = 0;
bool load(const char *dictionary)
{
    // open file with words
    FILE* fp = fopen(dictionary, "r");
    if (!fp)
    {
        return false;
    }

    // Memory for head, trav, tempword
    char tempword[LENGTH + 1];
    // Get words from file (until EOF)
    while (fscanf(fp, "%s", tempword) != EOF)
    {
        // Increase word count and create node for new word
        node* node = malloc(sizeof(struct node));
            if (!node)
            {
                free(node);
                return false;
            }

        // Initialze new node
        strcpy(node->word, tempword);
        node->next = NULL;

        // Get index for where to store word
        unsigned long hash = hashcode(tempword);
        if (hashtable[hash] != NULL)
        {
            // Point new node to where hashtable node is pointing
            node->next = hashtable[hash];
        }

        // Initialize the hashtable; point index to n
        hashtable[hash] = node;

        wordcount++;
    }
    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Free memory
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        trav = hashtable[i];
        while (trav != NULL)
        {
            node *tmp = trav;
            trav = trav->next;
            free(tmp);
        }
    }
    return true;
}
