#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    // Get input from teller
    do
    {
        change = get_float("Change Owed: ");
    }
    while (change < 0.0);

    //Convert dollars to cents
    float m = change * 100;

    //Round the cents
    int n = round(m);

    int counter = 0;

    //Begin counting coins
    while (n >= 25)
    {
        counter += 1;
        n = n - 25;
    }

    while (n >= 10)
    {
        counter += 1;
        n = n - 10;
    }

    while (n >= 05)
    {
        counter += 1;
        n = n - 05;
    }

    while (n >= 01)
    {
        counter += 1;
        n = n - 01;
    }

    // Print the number of coins needed to copmlete the transaction
    printf("%i coins\n", counter);
}