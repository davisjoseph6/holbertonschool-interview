#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _isdigit - checks if a string consists of digits
 * @s: the string to check
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int _isdigit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to return
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * print_error - prints Error, frees memory (if applicable), and exits with status 98
 * @result: pointer to memory that needs to be freed
 */
void print_error(int *result)
{
	char *error = "Error\n";

	if (result)
		free(result);

	while (*error)
		_putchar(*error++);
	exit(98);
}

/**
 * multiply - multiplies two numbers represented as strings
 * @num1: first number as a string
 * @num2: second number as a string
 *
 * Return: pointer to result array
 */
int *multiply(char *num1, char *num2, int len1, int len2, int len)
{
	int *result = malloc(sizeof(int) * len);
	int carry, n1, n2, i, j;

	if (!result)
		return (NULL);

	for (i = 0; i < len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			carry += result[i + j + 1] + n1 * n2;
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry;
	}
	return (result);
}

/**
 * print_result - prints the result of multiplication
 * @result: pointer to the result array
 * @len: length of the result array
 */
void print_result(int *result, int len)
{
	int i = 0;

	while (i < len && result[i] == 0)
		i++;

	if (i == len)
		_putchar('0');

	while (i < len)
		_putchar(result[i++] + '0');

	_putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: 0 if successful, 98 if failure
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, len, *result;

	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
		print_error(NULL);

	num1 = argv[1];
	num2 = argv[2];
	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;

	result = multiply(num1, num2, len1, len2, len);
	if (!result)
		print_error(NULL);

	print_result(result, len);
	free(result);
	return (0);
}
