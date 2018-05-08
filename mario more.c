#include <stdio.h>
#include <cs50.h>

// Create a pyramid in Mario with variable height
int main(void)
{
    // Prompt user for height of pyramid between 0 and 23 blocks
    int height;
    do
    {
        height = get_int("height: ");
    }
    while (height < 0 || height > 23);

    // Determines number of rows
    for (int i = 0; i < height; i++)
    {
        // Print spaces for left pyramid
        for (int space = i + 1; space < height; space++)
        {
            printf(" ");
        }

        // Print blocks for left pyramid
        for (int block = height - i; block < height + 1; block++)
        {
            printf("#");
        }
        printf("  ");

        // Print blocks for right pyramid
        for (int block = height - i; block < height + 1; block++)
        {
            printf("#");
        }

        // Prints new line
        printf("\n");
    }
}


