#include "holberton.h"

/**
 * main - multiplies two positive numbers, passed in as args
 * @argc: int count of number of arguments provided to program
 * @argv: double pointer to array with program name and arguments
 *
 * Return: 0 if successful, exit status of 98 on failure
 */

int main(int argc, char *argv[])
{
	unsigned int digit_count1 = 0, digit_count2 = 0, max_digit = 0, min_digit = 0;
	unsigned int row = 0, column = 0, start = 0, i = 0, j = 0;
	int product = 0, remainder = 0;
	char *num1 = NULL, *num2 = NULL, **calculation = NULL, *final = NULL;

	if (argc != 3)
		error();
	digit_count1 = digit_check(argv[1]);
	digit_count2 = digit_check(argv[2]);
	if (digit_count1 == 0 || digit_count2 == 0)
		error();
	set_max_min(digit_count1, digit_count2, &max_digit, &min_digit,
		    &num1, &num2, argv[1], argv[2]);
	calculation = create_double(min_digit, min_digit + max_digit);
	start = (min_digit + max_digit - 1);
	for (i = min_digit, row = 0; i > 0; i--, row++)
	{
		for (j = max_digit, column = start; j > 0; j--, column--)
		{
			product = (num1[j - 1] - '0') * (num2[i - 1] - '0');
			product += remainder;
			calculation[row][column] = (product % 10) + '0';
			remainder = product / 10;
		}
		calculation[row][column] = remainder + '0';
		remainder = 0;
		start--;
	}
	final = create_final(min_digit + max_digit, calculation);
	for (i = 0; final[i]; i++)
		_putchar(final[i]);
	_putchar('\n');
	for (row = 0; calculation[row]; row++)
		free(calculation[row]);
	free(calculation);
	free(final);
	return (0);
}

/**
 * error - prints error message and exits program
 */

void error(void)
{
	int i = 0;
	char error[6] = "Error";

	for (i = 0; error[i]; i++)
		_putchar(error[i]);
	_putchar('\n');
	exit(98);
}


/**
 * digit_check - checks if number contains only digits and
 * counts number of digits
 *
 * @number: array of characters to check if digits
 *
 * Return: 0 on failure or number of digits in number
 */

int digit_check(char *number)
{
	int i = 0;

	for (i = 0; number[i]; i++)
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
	}
	return (i);
}

/**
 * set_max_min - sets max and min numbers and digit counts
 * @digit_count1: count of digits in first number argument
 * @digit_count2: count of digits in second number argument
 * @max_digit: pointer to maximum number of digits
 * @min_digit: pointer to minimum number of digits
 * @num1: double pointer to number with maximum digits
 * @num2: double pointer to number with minimum digits
 * @arg1: pointer to first number argument
 * @arg2: pointer to second number argument
 */

void set_max_min(unsigned int digit_count1, unsigned int digit_count2,
		 unsigned int *max_digit, unsigned int *min_digit,
		 char **num1, char **num2, char *arg1, char *arg2)
{
	if (digit_count1 > digit_count2)
	{
		*max_digit = digit_count1;
		*num1 = arg1;
		*min_digit = digit_count2;
		*num2 = arg2;
	}
	else
	{
		*max_digit = digit_count2;
		*num1 = arg2;
		*min_digit = digit_count1;
		*num2 = arg1;
	}
}

/**
 * create_double - mallocs and initializes a double pointer (2D array)
 *
 * @row_size: number of rows the double pointer should have
 * @column_size: number of columns each row should contain
 *
 * Return: the 2D array initialized with 0s
 */

char **create_double(unsigned int row_size, unsigned int column_size)
{
	char **calculation = NULL;
	unsigned int row = 0, column = 0;

	calculation = malloc(sizeof(char *) * (row_size + 1));
	if (calculation == NULL)
		error();
	for (row = 0; row < row_size; row++)
	{
		calculation[row] = malloc(sizeof(char) * (column_size + 1));
		if (calculation[row] == NULL)
		{
			for (; (row + 1) > 0; row--)
				free(calculation[row]);
			free(calculation);
			error();
		}
		for (column = 0; column < column_size; column++)
			calculation[row][column] = '0';
		calculation[row][column] = '\0';
	}
	calculation[row] = NULL;
	return (calculation);
}

/**
 * create_final - mallocs for final calculation of product and
 * sets values from calculations 2D array
 *
 * @size: maximum size needed for final array
 * @calculation: 2D array of all intermediary calculations
 *
 * Return: the final array with the final product value
 */

char *create_final(unsigned int size, char **calculation)
{
	char *final = NULL;
	unsigned int row = 0, column = 0, sum = 0, remainder = 0;

	final = malloc(sizeof(char) * (size + 1));
	if (final == NULL)
	{
		for (row = 0; calculation[row]; row++)
			free(calculation[row]);
		free(calculation);
		error();
	}
	final[size] = '\0';
	for (column = (size - 1); (column + 1) > 0; column--)
	{
		sum = 0;
		for (row = 0; calculation[row]; row++)
		{
			sum += (calculation[row][column] - '0');
		}
		sum += remainder;
		final[column] = (sum % 10) + '0';
		remainder = sum / 10;
	}
	if (final[0] == '0')
		final = final_realloc(final, calculation);
	return (final);
}

/**
 * final_realloc - reallocates if there are any leading 0s
 * @final: pointer to calculated final product
 * @calculation: pointer to 2D array storing intermediary calculations
 *
 * Return: final product without leading 0s
 */

char *final_realloc(char *final, char **calculation)
{
	unsigned int i = 0, j = 0, leading = 0, new_size = 1;
	char *final_realloc = NULL;

	for (i = 0; final[i]; i++)
	{
		if (leading)
			new_size++;
		else if (final[i] != '0')
			leading = 1;
	}
	final_realloc = malloc(sizeof(char) * (new_size + 1));
	if (final_realloc == NULL)
	{
		for (i = 0; calculation[i]; i++)
			free(calculation[i]);
		free(calculation);
		free(final);
		error();
	}
	final_realloc[new_size] = '\0';
	leading = 0;
	for (i = 0; final[i]; i++)
	{
		if (leading)
		{
			final_realloc[j] = final[i];
			j++;
		}
		else if (final[i] != '0')
		{
			leading = 1;
			final_realloc[j] = final[i];
			j++;
		}
		else if (new_size == 1)
			final_realloc[j] = '0';
	}
	free(final);
	return (final_realloc);
}
