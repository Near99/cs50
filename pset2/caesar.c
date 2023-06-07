#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
/**
 * Feels like a damn f* stupid when attempting this task
 * It's quite similar to readability in terms of manipulating 
 * strings with ASCII code. But I totaly forgot how I did 
 * readability days ago, so was in trouble for a while XD.
 * I wrote some piece of code first that passed the check,
 * It was, however, in chaos. This one still sucks but slightly better
 * as I referred to other coders work. I tried to use 
 * -= += %= operatin format this time to clean up the code a bit.
 * Gonna watch lecture 2 again cause I think I don't have enough
 * understanding about the array. And will try to write a atoi function
 * myself. Thanks to Federico-abss on github for your work :)
 **/

int main(int argc, string argv[])
{
    int k; //Rotating value
    
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        
        return 1;
    }
    else if (atoi(argv[1]) <= 0)
    {
        printf("Usage: ./caesar key \n");
        
        return 1;
    }
    else 
    {
        k = atoi(argv[1]);
        
        //Use the remainder as key value if > 26.
        if (k > 26)
        {
            k %= 26;
        }
        
        string plaintext = get_string("plaintext: ");
        
        for (int i = 0; i < strlen(plaintext); ++i)
        {
            //Uppercase letters
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                //Handle the out-of-range letters if plus key
                if (plaintext[i] + k > 'Z')
                {
                    plaintext[i] -= 26;
                }
                plaintext[i] += k;
            }
            //Lowercase letters
            else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                if (plaintext[i] + k > 'z')
                {
                    plaintext[i] -= 26;
                }
                plaintext[i] += k;
            }
        }

        printf("ciphertext: %s\n", plaintext);
        
        return 0;
    }
}
