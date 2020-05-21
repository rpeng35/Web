#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>


#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8

typedef uint8_t BYTE;
bool new_jpg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File not found!\n");
        return 1;
    }
    
    BYTE buffer[BLOCK_SIZE];
    int file_index = 0;
    bool first_jpg = false;
    FILE *outfile;
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        if (new_jpg(buffer))
        {
            if (!first_jpg)
            {
                first_jpg = true;
            }
            else
            {
                fclose(outfile);
            }
            char filename[FILE_NAME_SIZE];
            sprintf(filename, "%03i.jpg", file_index++);
            
            outfile = fopen(filename, "w");
            if (outfile == NULL)
            {
                return 1;
            }
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
        else if (first_jpg)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }
    fclose(outfile);
    fclose(file);
}

bool new_jpg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}

