#include <stdio.h>
#include <cs50.h>
#include <math.h>
/**
 * This is a challenging version of cash problem.
 * The variable names are chaotic, so does the code,
 * probably will revise the code soon XD.
 **/  
int main()
{
     	long long card_number = get_long("Number: ");
    	long long ten_pow;
    	int second_number = 0; 
    	int first_number = 0;
    	int total_spard = 0;
    	int total_less_ten = 0;
    	int get_num = 0;
    	int tmp_sum = 0;
    	int length = 0;
    	long long length_count = card_number;

        // Get the length of the card number.
	for (length = 0; length_count != 0;)
	{
		length++;
		length_count = length_count / 10;
	}

	//printf("%d\n", length);

	// Get the number from last second, jump two each time.
	for (int i = 1; i <= length; i = i + 2)
	{
		// Use Nth power of ten, and % to get demand numbers.
		ten_pow = pow(10, i);

		get_num = (card_number / ten_pow) % 10;

		// Multiply acquired numbers by 2.
		get_num = get_num * 2;

		// Separate the numbers if > 10.
		if (get_num >= 10)
		{
			second_number = get_num % 10; 
			//printf("%d\n", second_number);

			first_number = (get_num / 10) % 10; 
			//printf("%d\n", first_number);

			tmp_sum = tmp_sum + second_number + first_number;
		}
		else
		{
			//printf("%d\n", get_num);
			total_less_ten = total_less_ten + get_num;
		}
		
	}

	total_spard = tmp_sum + total_less_ten;
	//printf("From last Second added: %d\n", total_spard);

	// Get all the rest numbers.
	int rest_number = 0;

	// Get the last digit.
	int last_digit = card_number % 10;

	// Store the total number of the rest.
	int total_rest = 0;

	//printf("%d\n", last_digit);

	for (int x = 2; x <= length; x = x + 2)
	{
		ten_pow = pow(10, x);

		rest_number = (card_number / ten_pow) % 10;

		total_rest = total_rest + rest_number;

		//printf("%d\n", rest_number);
	}

	last_digit = last_digit + total_rest;
	//printf("Rest number added: %d\n", last_digit);

	int total = last_digit + total_spard;
	//printf("Total: %d\n", total);

	long long check_type = 0;
	
	
	//printf("%lld\n", check_type);


	// Check if the credit card if vaild.
	if (total % 10 == 0)
	{
		if (length != 16 && length != 13 && length != 15)
		{
			printf("INVALID\n");
		}
		else if (length == 16)
		{
			ten_pow = pow(10, 15);
			check_type = card_number / ten_pow;
			if (check_type == 4)
			{
				printf("VISA\n");
			}
			else if (check_type != 4)
			{
				ten_pow = pow(10, 14);
				check_type = card_number / ten_pow;
				if (check_type == 51 || check_type == 52 || check_type == 53 || check_type == 54 || check_type == 55)
				{
					printf("MASTERCARD\n");
				}
				else
				{
					printf("INVALID\n");
				}
			}
		}
		else if (length == 15)
		{
			ten_pow = pow(10, 13);
			check_type = card_number / ten_pow;
			if (check_type == 34 || check_type == 37)
			{
				printf("AMEX\n");
			}
			else
			{
				printf("INVALID\n");
			}
		}
		else if (length == 13)
		{
			ten_pow = pow(10, 12);
			check_type = card_number / ten_pow;
			if (check_type == 4)
			{
				printf("VISA\n");
			}
			else
			{
				printf("INVALID\n");
			}
		}
	}
	else
	{
		printf("INVALID\n");
	}
}
