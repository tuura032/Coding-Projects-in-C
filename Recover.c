// Recovers pictures from a "memory card" that had previously been wiped.
// Input: raw data file, Output: Some number of .jpg until EOF reached

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "1Input Raw File\n");
        return 1;
    }

    // open input file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        fprintf(stderr, "2Could not open %s.\n", argv[1]);
        return 2;
    }


    // Create data type BYTE
    typedef uint8_t BYTE;

    // Char Array to store file name
    char filename[8];

    // Make array to store each block
    BYTE buffer[512] = {0};

    FILE* img = NULL;
    int j = 0;
    int feof(FILE* infile);

    // Repeat until end of memory card
    //for (j = 0; j < 5; j++)
    while (feof(infile) != EOF)
    {
        // Read the infile; read 512 bytes 1 time
        fread(buffer, 512, 1, infile);

        // Start of new jpeg?
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            //already found a jppeg?
            if (img != NULL)
            {
                // Close previous file
                fclose(img);

                // make a new file named ###.jpg, named in order of found files
                sprintf(filename, "%03i.jpg", (j+1));
                j++;

                // Open newly created file
                img = fopen(filename, "w");
                if (img == NULL)
                {
                    fprintf(stderr, "Could not open %s.\n", argv[1]);
                    return 4;
                }
                // Write from buffer to the new file
                fwrite(buffer, 512, 1, img);
            }

            // No jpeg yet found
            else
            {
                // make a new file named ###.jpg, named in order of found files
                sprintf(filename, "%03i.jpg", 0);

                //Open the file I just created
                img = fopen(filename, "w");
                if (infile == NULL)
                {
                    fprintf(stderr, "5Could not open %s.\n", argv[1]);
                    return 5;
                }

                // Write from buffer to new file
                fwrite(buffer, 512, 1, img);
            }

        }
        //not the start of a jpeg
        else
            {
                if (img != NULL)
                {
                    if (feof(infile))
                        break;

                    // Write to newfile
                    fwrite(buffer, 512, 1, img);
                }

                else
                    continue;
            }
    }

    fclose(img);
    return 0;
}
