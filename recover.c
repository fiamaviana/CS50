#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //open memory card file
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    //look for beginning of a JPEG; repeat it until end of card

    int file_index = 0;
    bool first_jpeg = false;
    FILE *img;
    unsigned char buffer[512];
    while(fread(buffer, 512, 1, file))
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //open a new JPEG file
            if(!first_jpeg)
                first_jpeg = true;
            else
                fclose(img);
            
            char filename[8];
            sprintf(filename, "%03i.jpg", file_index++);
            img = fopen(filename, "w");
            if(img == NULL)
                return 1;
            fwrite(buffer, 512, 1, img);

        }
        else if (first_jpeg)
        {
            //writes 512 bytes until the end of the file
            fwrite(buffer, 512, 1, img);
        }
    }
    fclose(img);
    fclose(file);
}