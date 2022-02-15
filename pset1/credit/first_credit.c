#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cc;
    long ccnum;
    int digits;
    int lastnum;
    int digits2;
    int checksum;
    int visa;
    int amx;
    int mc;
    

    do
    {
        cc = get_long ("Number: ");                             //input credit card number
        ccnum = cc;                                             //set new variable "ccnum" to value of "cc"
        for (digits = 0; ccnum > 0; digits++)                   //digit counter
        {
            ccnum = ccnum/10;
        }
    }
    while (digits != 13 && digits != 15 && digits != 16);       //malicious user check
    
    
    if (digits == 13 && digits == 15 && digits == 16)
    {
        printf("ngfnhfh\n");
    }
    else
    {
        printf("INVALID\n");
    }



    ccnum = cc;                                                 //reset variable "ccnum" with value of "cc"
    checksum = 0;                                               //set variable "checksum" to zero

        for (digits2 = 1; digits2 <= digits + 1; digits2++)     //count digits again starting at value of 1 so the 'count' of the last digit will be 1, and next to last will be 2
        {
            lastnum = ccnum %10;                                //isolate last number in "ccnum" as an interger

            if (digits2 %2 == 0)                                //to flag every other number counting last digit backwards
            {
                    checksum = checksum + lastnum * 2;          //build checksum as variable "checksum", doubling, then adding every other digit from second to last counitng backwards
                    printf("checksum: %i\n", checksum);     //kill after test
            }
            else
            {
                checksum = checksum + lastnum;                  //build checksum adding every other digit starting from the last digit counting backwards
            }
            ccnum = ccnum/10;                                   //move to next digit back
        }


}