#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("Change owed:");                     //get input "change", for changed owed
    }
    while (change <= 0);                                        //malicious user check

    int cents = round (change * 100);                           //round change*100 (to convert float "change" to interger "cents")

    int q = 0;                                                  //set quarter count to zero
    int d = 0;                                                  //set dime count to zero
    int n = 0;                                                  //set nickle count to zero
    int p = 0;                                                  //set penny count to zero

        do
        if (cents >= 25)                                        //quarter counter
        {
            cents = cents - 25;
            q++;
        }
        while (cents >= 25 && cents > 0);

        do
        if (cents >= 10)                                        //dime counter
        {
            cents = cents - 10;
            d++;
        }
        while (cents >= 10 && cents > 0);

        do
        if (cents >= 5)                                         //nickle counter
        {
            cents = cents - 5;
            n++;
        }
        while (cents >= 5 && cents > 0);

        do
        if (cents >= 1)                                         //penny counter
        {
            cents = cents - 1;
            p++;
        }
        while (cents >= 1 && cents > 0);

    int coins = q + d + n + p;                                  //set "coins" to total amount of coin used
    printf("%i\n", coins);                                      //print "coin" for number of coins used output
}