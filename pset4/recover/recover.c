#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    BYTE buffer[512];
    int file_count = 0;
    FILE *output = NULL;
    char filename[8];
    
    while (fread(buffer, 512, 1, input) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output != NULL)
            {
                fclose(output);
            }
            
            sprintf(filename, "%03i.jpg", file_count);
            output = fopen(filename, "w");
            file_count++;
        }
        
        if (output != NULL)
        {
            fwrite(buffer, 512, 1, output);
        }
    }
    
    if (output != NULL)
    {
        fclose(output);
    }
    
    fclose(input);
}
