#include <stdio.h>
#include <cs50.h>


//thinking of using a func, string and casting to make it easier for me
// char *str = string + (type) expression
int size(long a)
{
    //just a dumb way of getting the size
    int i = 0;
    long temp = a;
    int s;
    while (temp != 0)
    {
        temp /= 10;
        i++;
    }
    s = i;
    return s;
}

int checksum(long a)
{
    int s = size(a);
    //starting from the end
    //each even number ill multiply by 2 and add its digit up to sum1
    //each odd number ill add it up to sum2
    //add sum1 to sum 2 % 10 checking if its = to 0
    long temp = a;
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= s ; i++)
    {
        long t = temp % 10;
        temp /= 10;
        if (i % 2 == 0)
        {
            t *= 2;
            int t2 = t % 10;
            t /= 10;
            sum1 += t + t2;
        }
        else
        {
            sum2 += t;
        }
    }


    return (sum1 + sum2) % 10;

}

int main(void)
{
    /*
    American Express uses 15-digit numbers, start with 34 or 37
    MasterCard uses 16-digit numbers, start with 51, 52, 53, 54, or 55 (range)
    Visa uses 13- and 16-digit numbers, start with 4
    credit card checksum:
    Luhn’s Algorithm:
        Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
        Add the sum to the sum of the digits that weren’t multiplied by 2.
        If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    output : AMEX or MASTERCARD or VISA or INVALID
    input using get_long
    */


    long N = get_long("Number: ");

    int s = size(N);

    long temp = N;

    while (temp >= 100)
    {
        //getting the first 2 numbers
        temp /= 10;
    }

    if (checksum(N) == 0)
    {
        if ((temp == 34 || temp == 37) && s == 15)
        {
            printf("AMEX\n");
        }
        else if (temp >= 51 && temp <= 55 && s == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (temp / 10 == 4 && (s == 13 || s == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}