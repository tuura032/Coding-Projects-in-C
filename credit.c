// Credit works to detect if a credit card number is valid, and then determines what type of credit card it is (VISA, AMEX, Mastercard)

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)

{
    long long i;
    int x, counter;
    do
    {
        i = get_long_long("Credit Card Number: ");
    }
    while (i < 1);

    long long extracopy = i;
    long long l = i;    // make a copy of variable i
    l = (l / 10);       //Moves over to 2nd to last number on cc
    unsigned int j = ((l % 10) * 2); //2nd to last # * 2

    //Splits 2nd to last number into two digits and adds them together
    if (j > 9)
    {
        counter = (j % 10) + 1;
    }

    //Sets counter to counter to 2nd to last * 2
    else
    {
        counter = j;
    }

    //Get Sum of changed numbers (the ones multiplied by 2)
    while (l != 0)
    {
        l = l / 100;
        unsigned k = ((l % 10) * 2);
        while (k > 9)
        {
            k = (k % 10) + 1;
        }
        for (x = 0; x < k; x++)
        {
            counter += 1;
        }
    }

    //Start New Counter, set it to last digit of CC
    int counter2 = i % 10;

    // Get Sum of the unchanged Numbers
    while (i != 0)
    {
        i = i / 100;
        unsigned m = i % 10;
        for (x = 0; x < m; x++)
        {
            counter2 += 1;
        }
    }


    //Add together all values in checksum
    int sum = counter + counter2;


    // Print Invalid if card is invalid
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }

    //Determine which card type if checksum passed
    if (sum % 10 == 0)
    {
        long long test = extracopy;
        int amextest = test / 10000000000000;
        int visatest13 = test / 1000000000000;
        int visatest16 = test / 1000000000000000;
        int mct = test / 100000000000000;
        if (amextest == 34 || amextest == 37)
        {
            printf("AMEX\n");
            return 0;
        }
        if (visatest13 == 4)
        {
            printf("VISA\n");
            return 0;
        }
        if (visatest16 == 4)
        {
            printf("VISA\n");
            return 0;
        }
        if (mct == 51 || mct == 52 | mct == 53 | mct == 54 | mct == 55)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
         printf("INVALID\n");
        }
    }
}
