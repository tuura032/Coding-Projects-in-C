// more complicated encyrption than Caesar, Vigenere asks for a string input (the cipher).
//The input message has it's ascii value modified by the ascii value of each letter of the string cipher,
// and repeats until the entire message is encoded.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// closed brackets after argv ([]) means it's an array
int main(int argc, string argv[])
{
    // Run the program only if two arguments are typed at prompt
    if (argc == 2)
    {

        // Initial nput goes into new vairable, cipher, for easier reference.
        string cipher = argv[1];

        //Make sure only letters are in the initial input
        for (int k = 0; k < strlen(cipher); k++)
        {
            char ciphertest = cipher[k];
            if (isalpha(ciphertest))
            {
            }
            else
            {
                printf("program failure\n");
                return 1;
            }
        }

        // Get plaintext from user
        string s = get_string("plaintext: ");
        printf("ciphertext: ");

        //define some variables I will be using
        int new_key;
        int j = 0;


        //One letter at a time, begin outputting the initial string as char
        for (int i = 0; i <= strlen(s); i++)
        {
            //Make sure cipher continues to reset at first letter if it's gone all the way through
            if (i == strlen(cipher))
            {
                i = 0;
            }
            char cipherchar = cipher[i];
            char single_letter = s[j];


            //pass through non-alphabetical characters
            if (isalpha(single_letter))
            {
                //convert uppercase to new_key
                if (islower(single_letter))
                {
                    // lowercase char needs to become the new key
                    if (isupper(cipherchar))
                    {
                        new_key = ((int) cipherchar - 65);
                    }
                    else
                    {
                        new_key = ((int) cipherchar - 97);
                    }

                    //shift plaintext character by key (convert ascii string to int?)
                    int ciphertext = ((((int) single_letter - 97) + new_key) % 26) + 97;
                    printf("%c", ciphertext);
                }

                //convert uppercase to new_key
                if (isupper(single_letter))
                {
                    if (isupper(cipherchar))
                    {
                        new_key = ((int) cipherchar - 65);
                    }
                    else
                    {
                        new_key = ((int) cipherchar - 97);
                    }
                    int ciphertext = ((((int) single_letter - 65) + new_key) % 26) + 65;
                    printf("%c", ciphertext);
                }
            }
            // if the character is not a letter, print it unchanged and reset the value of cipherchar
            else
            {
                i = i - 1;
                printf("%c", single_letter);
            }

            //Advance to next letter in plaintext conversion
            j += 1;

            //End the program when the entire message is encrypted
            if (j == strlen(s))
            {
                printf("\n");
                return 0;
            }

        }
    }

    // Tell user to retry if #arguments != 2
    else
    {
        printf("Error, try another number!\n");
        return 1;
    }
}

