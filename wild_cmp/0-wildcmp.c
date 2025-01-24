#include "holberton.h"

/**
 * wildcmp - Compares two strings considering '*' in s2 as a wildcard
 * @s1: The first string
 * @s2: The second string, which may contain '*'
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	/* If both strings end at the same time, they match */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* If s2 has a '*', it can match zero or more characters of s1 */
	if (*s2 == '*')
	{
		/*
		 * If '*' is the last character in s2, then it can match
		 * the rest of s1, so return 1.
		 */
		if (*(s2 + 1) == '\0')
			return (1);

		/*
		 * Otherwise, try two possibilities:
		 * 1) Move s2 forward by 1 (skip '*'), keep s1 where it is
		 * 2) Move s1 forward by 1, keep s2 where it is
		 */
		if (*s1 == '\0')
			/* s1 is empty, so skip '*' in s2 */
			return (wildcmp(s1, s2 + 1));

		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	}

	/*
	 * If both current characters match, move both forward
	 * Otherwise, if one has ended or they differ, return 0
	 */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* Characters differ and s2 is not '*', no match */
	return (0);
}

