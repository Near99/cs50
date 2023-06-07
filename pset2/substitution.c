#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
/**
 * This is an ASCII practice again.
 * I got stuck in how to match the plaintext with the key for a while.
 * Two pairs of 26 range numbers, one starts from 0 to 26, and
 * the other is 65 to 90 or 97 - 122. one minus another is constant
 * 65 or 97. But cannot simply match the two as string value returns
 * ASCII code as well. So I ended up to -65 and print it directly
 * in the for loop. The difference between upper and lower case
 * is 32, to minus 32 to keep the lowercase lower is my solution
 **/

int main(int argc, string argv[])
{
    string key =  argv[1];

    if (argc != 2)
    {
        printf("Usage: ./substiution key\n");

        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");

        return 1;
    }
    
    //Check if the key is alphanumeric.
    for (int i = 0; i < 26; ++i)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain 26 alphabet letters\n");

            return 1;
        }
    }

    //Convert key to uppcase
    for (int x = 0; x < 26; ++x)
    {
        key[x] = toupper(key[x]);
    }
    
    
    //Check if there is any duplicated letters in the key. 
    for (int y = 0; y < 26; ++y)
    {
        for (int j = 0; j < y; ++j)
        {
            if (key[y] == key[j])
            {
              printf("Key shouldn't contain duplicate characters\n"); 
              
              return 1;
            }
        }
    }
    
    string text = get_string("plaintext: ");
    
    printf("ciphertext: ");
    
    //Encrypt the message
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            printf("%c", key[(text[i] - 65)]);
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            printf("%c", key[(text[i] - 97)] + 32);
        }
        else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");
    
    return 0;
}
