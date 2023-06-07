#include <stdio.h>
#include <math.h>
#include <cs50.h>
/**
 * Use if condition to solve this problem was my first thought.
 * if (owned_cents >= 25) {owned_cents = owned_cents - quarters; counts++;}
 * However this solution requires four if conditions that looks even more silly than my Mario.
 * I couldn't think of any ways to simplify the code and I referred to other's work on Github,
 * then I found operator % used in his code. 
 * % operator computes the remainder. % really makes the life much more easier in this case :)
 * I am sure David mentioned the % operator in the lecture but it's just somehow out of my head.
**/

int main(void)
{
	int cents;

	do
    {
        float input = get_float("Change owned: ");

        cents = round(input * 100);
    } 
    while (cents < 0);

	int quarters = cents / 25;

	int dimes = (cents % 25) / 10; ;

	int nickels = ((cents % 25) % 10) / 5;
    
	int pennies = (((cents % 25) % 10) % 5) / 1;

	int counts = quarters + dimes + nickels + pennies;

	printf("%d", counts);
}
