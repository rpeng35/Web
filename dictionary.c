// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

#define N 1000

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// const unsigned int N = 1;

// Hash table
node *table[N];

unsigned int num_words = 0;
bool is_loaded = false;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char check_word[strlen(word)];
    strcpy(check_word, word);
    for (int i = 0; check_word[i] != '\0'; i++)
    {
        check_word[i] = tolower(check_word[i]);
    }
    int index = hash(check_word);
    if (table[index] != NULL)
    {
        for (node *nodeptr = table[index]; nodeptr != NULL; nodeptr = nodeptr->next)
        {
            if (strcmp(nodeptr->word, check_word) == 0)
            {
                return true;
            }
        }
    }
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            n = word[i] - 'a' + 1;
        }
        else
        {
            n = 27;
        }
        hash = ((hash << 3) +  n) % N;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        fprintf(stderr, "file does not exist!\n");
        return false;
    }
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    char word[LENGTH + 1];
    node *new_nodeptr;
    while (fscanf(dict, "%s", word) != EOF)
    {
        num_words++;
        do
        {
            new_nodeptr = malloc(sizeof(node));
            if (new_nodeptr == NULL)
            {
                free(new_nodeptr);
            }
        }
        while (new_nodeptr == NULL);
            
        strcpy(new_nodeptr->word, word);
        int index = hash(word);
        new_nodeptr = table[index];
        table[index] = new_nodeptr;

    }
    fclose(dict);
    is_loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (!is_loaded)
    {
        return 0;
    }
    return num_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (!is_loaded)
    {
        return false;
    }
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *ptr = table[i];
            while (ptr != NULL)
            {
                node *predptr = ptr;
                ptr = ptr->next;
                free(predptr);
            }
        }
        
    }
    return true;
}
