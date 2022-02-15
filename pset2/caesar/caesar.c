// A program that encrypts a message using Caesar's algrothm
// c[i] = (p[i] + k) % 26
// Anthony-Fournier 10/2020 for Harvardx cs50 pset2

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)                                                              // Check that argc has only 2 arguments for argv[]
    {                                                                           // argv[0] will be caesar and argv[1] will be the key value of k
        printf("Bad Syntax\nUsage: ./caesar key\n");                            // Display to user with expected sytax
        return 1;                                                               // Error 'bad syntax'
    }
    int k = atoi(argv[1]);                                                      // Sets int k to converted int value of argv[1]

    for (int i = 0, n = strlen(argv[1]); i < n; i++)                            //counts each digit of argv[1]
        {
            if (isdigit(argv[1][i]) == 0)                                       //checks if it is a digit
            {
                printf("Non-interger key\nValue of key must be a interger");    // Display to user with solution
                return 1;                                                       // Error 'non-iterger key'
            }
        }

    if (k < 0 )                                                                 // Check that value of k is non-negative
    {
        printf("Negative Key\nValue of key must be a non-negative interger\n"); // Display error to user with solution
        return 1;                                                               // Error 'negative value for k'
    }
    else
    {
        string p = get_string("plaintext : ");                                  // Get string input p
        printf("ciphertext: ");
    for (int i = 0, n = strlen(p); i < n; i++)                                  // Do for each character in the string p
    {
        if (islower(p[i]))                                                     // Lower case
        {
            printf("%c", (((p[i] - 'a') + k) % 26) + 'a');                      // Apply Caesar's algorthm, shift by 'a' and print char
        }
        else if (isupper(p[i]))                                                 // Upper case
        {
            printf("%c", (((p[i] - 'A') + k) % 26) + 'A');                      // Apply Caesar's algorthm, shift by 'A' and print char
        }
        else
        {
            printf("%c", p[i]);                                                 // Leave non-letter char as is and print
        }
    }
    printf("\n");                                                               // New Line
    return 0;                                                                   // Program funtioned as expected
    }
}