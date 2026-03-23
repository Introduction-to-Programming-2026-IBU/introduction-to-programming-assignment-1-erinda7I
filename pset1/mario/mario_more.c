#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    for (int i = 0; i < height; i++)
    {
        // Left spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        // Left hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        // Two spaces in middle
        printf("  ");
        // Right hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
