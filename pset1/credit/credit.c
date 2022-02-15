#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cc = 0;
    long ccnum = 0;
    long ccnum2 = 0;
    int digits = 0;
    int evenodd = 0;
    int checksum = 0;
    int v = 0;
    int m = 0;
    int a = 0;
    int check = 0;
    int num = 0;
    cc = get_long("Number: ");                                                  //input credit card number
    ccnum = cc;                                                                 //set new variable "ccnum" to value of "cc"
    for (digits = 0; ccnum > 0; digits++)                                       //digit counter
    {
        ccnum = ccnum / 10;
    }
    if (digits != 13 && digits != 15 && digits != 16)                           //valid length check
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        ccnum2 = cc;                                                            //reset variable "ccnum" with value of "cc"
        if (ccnum2 / 1000000000000 == 4 || ccnum2 / 1000000000000000 == 4)      //check if first digit is 4 on a 15 or 16 digit number
        {
            v = 1;                                                           //set visa flag to 1(true)
            m = 0;                                                           //set mastercard flag to 0(false)
            a = 0;                                                           //set amex flag to 0(false)
        }
        else if (ccnum2 / 100000000000000 == 51 || ccnum2 / 100000000000000 == 52 || ccnum2 / 100000000000000 == 53
        || ccnum2 / 100000000000000 == 54 || ccnum2 / 100000000000000 == 55)    //check if first digits in a 16 digit number are 51,52,53,54, or 55
        {
            v = 0;                                                          //set visa flag to 0(false)
            m = 1;                                                          //set mastercard flag to 1(true)
            a = 0;                                                          //set amex flag to 0(false)
        }
        else if (ccnum2 / 10000000000000 == 34 || ccnum2 / 10000000000000 == 37)  //check if first digits in a 15 digit number are 34, or 35
        {
            v = 0;                                                  //set visa flag to 0(false)
            m = 0;                                                  //set mastercard flag to 0(flase)
            a = 1;                                                  //set amex flag to 1(true)
        }
    }
    for (evenodd = 1; evenodd <= digits; evenodd++)                 //cycle digits from right to left marking the first as odd(1), and the next as even(2), and so on
    {
        num = ccnum2 % 10;
        if (evenodd % 2 == 0)                                       //luhns algorithm
        {
            num = num * 2;
            if (num >= 10)
            {
                num = num - 9;
            }
        }
        checksum = checksum + num;                                  //building checksum
        ccnum2 = ccnum2 / 10;
    }
    if (checksum % 10 == 0)                                         //evaluate checksum
    {
        check = 1;                                                  //check flag to true(1)
    }
    else
    {
        check = 0;                                              //check flag to false(0)
    }
    if (check + v == 2)                                             //if check flag and visa flag are true
    {
        printf("VISA\n");
    }
    else if (check + m == 2)                                        //if check flag and mastercard flag are true
    {
        printf("MASTERCARD\n");
    }
    else if (check + a == 2)                                    //if check flag and amex flag are true
    {
        printf("AMEX\n");
    }
    else                                                        //otherwise
    {
        printf("INVALID\n");
    }
}