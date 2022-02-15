// A program that encrypts a message using a substitution algrothm
//
// Anthony-Fournier 10/2020 for Harvardx cs50 pset2
//                                                                                                  // BEGIN
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{                                                                                                   // Check that argc has only 2 arguments...
    if (argc != 2)                                                                                  // argv[0] will be "substitition" and...
    {                                                                                               // argv[1] will be the key
        printf("Bad Syntax\nUsage: ./substitution key\n");                                           // Display to user with expected sytax
        return 1;                                                                                   // Error 'bad syntax'
    }
    if (strlen(argv[1]) != 26)                                                                      // Check length of argv[1] is 26
        {
            printf("Invalid Key\nValue of key must contain exactly 26 alphabetic characters\n");    // Display error to user with solution
            return 1;                                                                               // Error 'invalid key'
        }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)                                                // Counts each char of argv[1]
    {
        if (isalpha(argv[1][i]) == 0)                                                               // Check if argv[1][i] is a letter
        {
            printf("Non-alphabetical key\nValue of key must contain only alphabetic characters\n"); // Display to user with solution
            return 1;                                                                               // Error 'non-alphabetical key'
        }
        for (int j = 0; j != n; j++ )                                                               // Looping to check against each other...
        {                                                                                           // char in argv[1] for repeats and...
            if (argv[1][i] == argv[1][j] && j != i)                                                 // that the 'chars' are not checked...
            {                                                                                       // against themselves
                printf("Repeat in Value\nValue of key must contain 26 unique letters\n");           // Display to user with soulution
                return 1;                                                                           // Error 'repeat value'
            }
        }
    }
    char abc[27] = "abcdefghijklmnopqrstuvwxyz";
    int key[27];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        key[i] = tolower(argv[1][i]);                                                               // Copy argv[1] to key whaile changeing to all lowercase
    }
    string p = get_string("plaintext : ");                                                          // Get user input, plaintext p
    printf("ciphertext: ");
    char c;
    for (int i = 0; i < strlen(p); i++)                                                             // The p loop (for every char in p)
    {
        if (isalpha(p[i]))
        {
            for (int j = 0; j < 26; j++)                                                            // p[i] does for each letter in the alphabet, in order
            {
                if (p[i] == abc[j] || p[i] == (abc[j] - 32))                                        // Find what letter p[i] is in array abc
                {
                    if (p[i] > 90)                                                                  // If it's lowercase
                    {
                        c = key[j];                                                                 // Find that spot in array key
                    }
                    else                                                                            // If it's uppercase
                    {
                        c = key[j] - 32;                                                            // Find that spot in array and reduce by 32
                    }
                    printf("%c", c);                                                                // Print c
                }
            }
        }
        else                                                                                        // if not letter
        {
            printf("%c", p[i]);                                                                     // print as is
        }
    }
    printf("\n");
    return 0;
}