// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

typedef struct node
{
    char word [LENGTH + 1];
    struct node *next;
}
node;

const int N = 1;
node *hashtable[N];

unsigned int *p_counter;
unsigned int word_counter;

// Hashes word to a number
unsigned int hash_func(const char* word)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

struct node *getNewNode(const char *word)
{
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Could not access memory\n");
        unload();
        return false;
    }
    newNode -> next = NULL;
    strcpy(newNode -> word, word);
    return newNode;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    char nword[LENGTH + 1];
    int n = strlen(word);
    for(int i = 0; i < n + 1; i++)
    {
        nword[i] = tolower(word[i]);
    }
    
    node *cursor = hashtable[hash_func(nword)];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor -> word, nword) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor -> next;
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");

    if(file == NULL)
    {
        printf("Could not open %s\n", dictionary);
        return false;
    }

    word_counter = 0;
    char dword[47];
    unsigned int hash = 0;

    // Read strings from file one at a time
    while(fscanf(file, "%s", dword) != EOF)
    {
        hash = hash_func(dword);
        if(hashtable[hash] == NULL)
        {
            hashtable[hash] = getNewNode(dword);
            word_counter++;
        }
        else
        {
            node *newNode = getNewNode(dword);
            newNode -> next = hashtable[hash];
            hashtable[hash] = newNode;
            word_counter++;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    p_counter = &word_counter; 
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        node *cursor = hashtable[i];
        while(cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor -> next;
            free(tmp);
        }
    }
    return true;
}
