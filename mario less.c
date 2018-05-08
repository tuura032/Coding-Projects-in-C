#include <stdio.h>
#include <cs50.h>


int main(void)
{
    // Prompt user for pyramid height between 0 and 23 blocks
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    // Print out this many rows
    for (int line = 0; line < height; line++)
    {
        //Print out this many columns
        for (int space = height - line; space > 1; space--)
        {
            printf(" ");
        }
        for (int hash = 0; hash < line + 2; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
