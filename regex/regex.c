#include "regex.h"

/**
 * regex_match - Checks whether a given pattern matches a given string.
 * @str: The string to scan.
 * @pattern: The regular expression pattern.
 *
 * Description:
 *  - The special character '.' matches any single character.
 *  - The special character '*' matches zero or more occurrences
 *    of the preceding character.
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t.
 */
int regex_match(const char *str, const char *pattern)
{
	if (*pattern == '\0')
		return (*str == '\0');

	/* If the next character of pattern is '*', handle repetition */
	if (*(pattern + 1) == '*')
	{
		/*
		 * Case 1: Try to match zero occurrences of the preceding char
		 */
		if (regex_match(str, pattern + 2))
			return (1);

		/*
		 * Case 2: If the current char of str matches pattern[0] or '.',
		 * advance in str and try again with the same pattern
		 */
		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			return (regex_match(str + 1, pattern));

		return (0);
	}
	else if (*str != '\0' && (*str == *pattern || *pattern == '.'))
	{
		/*
		 * If current chars match, move both pointers forward
		 */
		return (regex_match(str + 1, pattern + 1));
	}

	return (0);
}

