#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
	// Get text input from user.
	string str = get_string("text: ");

	// As var names show. initialize word_count to 1, in a proper English sentence, word(s) = space + 1. ps looking for other solutions XD;
	int word_count = 1; int letter_count = 0; int sentence_count = 0;

	// Get string length of input text. Also used as loop range.
	int text_length = strlen(str);

	for (int i = 0; i < text_length; i++)
	{
		// Count word(s)
		if (str[i] == ' ')
		{
			word_count++;
		}
		// Count letter(s)
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			letter_count++;
		}
		// Case sensitive, ACSII for lower and upper case letters are different
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			letter_count++;
		}
		// Count sentence(s). incomplete code, period '.' doesn't mean a sentence. 
		else if (str[i] == '.' || str[i] == '?' || str[i] == '!')
		{
			sentence_count++;
		}
	}
	// Average letter and sentence per 100 words.
	float L, S;

	// Convert int values to float to c detruncation.
	L = ((float)letter_count / (float)word_count) * 100;

	S = ((float)sentence_count / (float)word_count) * 100;

	// Formula.
	float index = (0.0588 * L) - (0.296 * S) - 15.8;

	// Round index value.
	int index_round = round(index);

	// Reading level.
	if (index_round <= 1)
	{
		printf("Before Grade 1\n");
	}
	else if (index_round > 16)
	{
		printf("Grade 16+\n");
	}
	else
	{
		printf("Grade %d\n", index_round);
	}

	// Check values
	/*
	printf("%d sentence(s)\n%d word(s)\n%d letter(s)\n", sentence_count, word_count, letter_count);
	printf("Average letter per 100 words is: %f\nAverage sentence per 100 words is: %f\n", L, S);
	printf("Before round Index value: %f\nAfter round Index value: %d", index, index_round); 
	*/
}