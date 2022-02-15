// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536;

int dict_size = 0;
bool loaded = false;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // copy word into array
    int length = strlen(word);
    char temp_word[length + 1];
    // make word lowercase
    for (int i = 0; i < length; i++)
    {
        temp_word[i] = tolower(word[i]);
    }
    // add /0 to end of array
    temp_word[strlen(word)] = '\0';
    // hash word
    int hashnum = hash(temp_word);
    //assign place node to first node
    node *place = table[hashnum];
    // check until end of list
    while (place != NULL)
    {
        if (strcmp(place->word, temp_word) == 0)
        {
            return true;
        }
        //else echeck next node
        else
        {
            place = place->next;
        }
    }
    return false;
}

// Hashes word to a number
// source = reddit user delipity https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn
unsigned int hash(const char *word)
{
    int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
        return hash % N;
    }
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char word [LENGTH + 1];
    // open dictionary
    FILE *dict;
    dict = fopen(dictionary, "r");
    // NULL check
    if (dict == NULL)
    {
        return false;
    }
    // read words from dictionary
    while (true)
    {
        // allocate memory for node for each word
        node *dict_node = malloc(sizeof(node));
        // NULL check
        if (dict_node == NULL)
        {
            return false;
        }
  
        // write words from dict into dict_node->
        fscanf(dict, "%s", dict_node->word);
        dict_node->next = NULL;
        // Stop at eof
        if (feof(dict))
        {
            free(dict_node);
            break;
        }
        dict_size++;
        //hash string
        int hash_num = hash(dict_node->word);
        node *top_node = table[hash_num];
        // if empty, insert first node
        if (top_node == NULL)
        {
            table[hash_num] = dict_node;
        }
        // else, add node to begining of list
        else
        {
            dict_node->next = table[hash_num];
            table[hash_num] = dict_node;
        }
    }
    // close dictionary
    fclose(dict);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded != true)
    {
        return 0;
    }
    else
    {
        return dict_size;
    }

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *place = table[i];
        while (place != NULL)
        {
            node *temp = place;
            place = place->next;
            free(temp);
            loaded = false;
        }
    }
    return true;
}
