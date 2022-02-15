#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("height? ");                               // get input "height"
    }
    while (height < 1 || height > 8);                               //malicious user check


    for (int rows = 0; rows < height; rows++)                       //do for each row and count until row is equal to height
    {
        for (int spaces = 0; spaces < height - rows -1; spaces++)   //print 'space' character(s) for columns
        {                                                           //in row from top down, and count
            printf(" ");
        }

        for (int columns = 0; columns < rows + 1; columns++)        // count and print '#'(s) in columns after spaces in current row
        {
            printf("#");                                            //also print 2 'space' characters after the '#' characters
        }
        printf("  ");                                               //print the gap
        
        
        for (int columns2 = 0; columns2 < rows + 1; columns2++)
        {
            printf("#");
        }
        
        
        printf("\n");                                               //next row
    }

}
