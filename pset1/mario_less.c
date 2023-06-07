#include <stdio.h>
/** 
 * It's probably the most stupid solution for Mario XD;
 * The key for this is simply using the loop range.
 * 
 * If the height is 8,
 * x loop will be in the range (0, 1, 2, 3, 4, 5, 6, 7).
 * Initialize y = height - 1 to delete extra space,
 * and y > x, the inverted pyramid will be printed as below.
 * 
 * 7 6 5 4 3 2 1 #
 * 7 6 5 4 3 2 # #
 * 7 6 5 4 3 # # #
 * 7 6 5 4 # # # #
 * 7 6 5 # # # # #
 * 7 6 # # # # # #
 * 7 # # # # # # #
 * # # # # # # # #
 * 
 * Simply add a z loop after y loop, but not inverted this time,
 * therefore, z <= x.
 * The numeric shape looks like this:
 * 
 * # # # # # # # 0
 * # # # # # # 0 1
 * # # # # # 0 1 2
 * # # # # 0 1 2 3
 * # # # 0 1 2 3 4
 * # # 0 1 2 3 4 5
 * # 0 1 2 3 4 5 6
 * 0 1 2 3 4 5 6 7  ps: this is why y = height - 1
 **/

int get_int_number(void);

int main (void)
{
    int i = get_int_number();
    int x, y, z;

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