#include <stdio.h>
/**
 * This should be the most stupid solution for mario more again XD. I am such a rookie.
 * I simply add two loops j & h after mario_less.
 * j is to print the two-space long gaps, and h is the second z loop but no y loop for mirror flip.
 * 
**/

int get_int_number(void);

int main (void)
{
    int i = get_int_number();
    int x, y, z;
    int j, h;

    for (x = 0; x < i; x++)
    {
        for (y = i - 1; y > x; y--)
        {
            printf(" ");
        }
        for (z = 0; z <= x; z++)
        {
            printf("#");
        }
        for (j = 0; j < 2; j++)
        {
            printf(" ");
        }
        for (h = 0; h <= x; h++)
        {
            printf("#");
        }
            printf("\n");
    } 
}

int get_int_number(void)
{
    int num_rows;

    do
    {
        printf("Height: ");
        scanf("%d", &num_rows);
    } while (num_rows < 1 || num_rows > 8);
    return num_rows;
}