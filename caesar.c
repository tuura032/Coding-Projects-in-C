// Ceasar is a very basic encryption program. User inputs a number and a message, 
// and each letter of the message has it's ascii value changed by the number input. 
// For example, inputs of "1" and "abc" would output "bcd".

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// closed brackets after argv ([]) means it's an array
int main(int argc, string argv[])
{
    // Run the program if two arguments are typed at prompt
    if (argc == 2)
    {
        // Convert the key from string to int
        int key = atoi(argv[1]);

        // Get plaintext from user
        string s = get_string("plaintext: ");
        printf("ciphertext: ");

        //Encode the text, one letter at a time
        for (int i = 0; i < strlen(s); i++)
        {
            char single_letter = s[i];

            // Use separate equations to convert letters to cyphertext
            if (isalpha(single_letter))
            {
                //preserve lowercase
                if (islower(single_letter))
                {
                    //shift plaintext character by key (convert ascii string to int?)
                    int cyphertext = ((((int) single_letter - 97) + key) % 26) + 97;
                    printf("%c", cyphertext);
                }

                //preserve uppercase
                if (isupper(single_letter))
                {
                    int cyphertext = ((((int) single_letter - 65) + key) % 26) + 65;
                    printf("%c", cyphertext);
                }
            }

            // Non-letter characters are printed unchanged
            else
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }

    // Tell user to retry if #arguments != 2
    else
    {
        printf("Error, try another number!\n");
        return 1;
    }
}
