// A program that computes the Coleman-Liau index value of a target string of input text
// index = 0.0588 * L - 0.296 * S - 15.8
//
// Anthony-Fournier 10/2020 for Harvardx cs50 pset2

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;
    string text = get_string("Text: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    float index = 0.0588 * (100 * (float)letters / (float)words) - 0.296 * (100 * (float)sentences / (float)words) - 15.8;
    int grade = round(index);
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}