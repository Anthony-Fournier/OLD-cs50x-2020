#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{

    // Check for proper usage of only one command line argument
    if (argc != 2)
    {
        printf("Bad Syntax\nUsage: ./recover [image file]\n");
        return 1;
    }

    // Open image file for recovery declare FILE and assign to image
    FILE *image = fopen(argv[1], "r");

    // Exit if the file cannot be opened
    if (image == NULL)
    {
        printf("Failed to open %s.\n", argv[1]);
        return 1;
    }


    // buffer of 512 bytes 0 - 255
    unsigned char temp[512];

    // Found image counter
    int count = 0;

    // declare and set file_name size
    char file_name[8];

    // declare and assign empty to FILE recovered_image
    FILE *recovered_image = NULL;

    // jpeg check
    bool isjpg = false;

    // loop through image file in 512 byte blocks until none remain
    while (fread(&temp, 512, 1, image) == true)
    {
        // look for jpeg
        if (temp[0] == 0xff && temp[1] == 0xd8 && temp[2] == 0xff && (temp[3] & 0xf0) == 0xe0)
        {
            // if found
            if (isjpg == true)
            {
                // new jpeg starts here, close current jpeg
                fclose(recovered_image);
            }
            else
            {
                isjpg = true;
            }

            // modify file_name with count, to three decmil places
            sprintf(file_name, "%03d.jpg", count);

            // open new modified file_name for writing output
            recovered_image = fopen(file_name, "w");

            // count the JPEG
            count ++;
        }

        if (isjpg == true)
        {
            // write 512 bytes to file
            fwrite(&temp, 512, 1, recovered_image);
        }
    }
    // close open files
    fclose(recovered_image);
    fclose(image);

    // program complete
    return 0;
}
