#include "substring.h"
#include <string.h>

/**
 * check_valid - checks if a substring is a valid concatenation of all words
 * @s: pointer to the start of the substring in the main string
 * @words: array of words
 * @nb_words: number of words
 * @word_len: length of each word
 *
 * Return: 1 if valid, 0 otherwise
 */
static int check_valid(const char *s, const char **words,
		       int nb_words, int word_len)
{
	int *used;
	int i, j;
	const char *current;

	used = malloc(nb_words * sizeof(int));
	if (!used)
		return (0);
	for (i = 0; i < nb_words; i++)
		used[i] = 0;

	for (i = 0; i < nb_words; i++)
	{
		current = s + i * word_len;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] && strncmp(current, words[j], word_len) == 0)
			{
				used[j] = 1;
				break;
			}
		}
		if (j == nb_words)
		{
			free(used);
			return (0);
		}
	}
	free(used);
	return (1);
}

/**
 * init_lengths - initializes string and word lengths, checks basic edge cases
 * @s: the main string
 * @words: array of words
 * @nb_words: number of words
 * @n: pointer to int that will store resulting count
 * @s_len: pointer to int for storing length of s
 * @word_len: pointer to int for storing length of each word
 * @total_len: pointer to int for total length (nb_words * word_len)
 *
 * Return: 1 if checks pass, 0 otherwise
 */
static int init_lengths(char const *s, char const **words, int nb_words,
			int *n, int *s_len, int *word_len, int *total_len)
{
	if (!s || !words || nb_words == 0)
	{
		*n = 0;
		return (0);
	}
	*s_len = strlen(s);
	*word_len = strlen(words[0]);
	*total_len = (*word_len) * nb_words;

	if (*s_len < *total_len)
	{
		*n = 0;
		return (0);
	}
	return (1);
}

/**
 * collect_indices - collects valid starting indices in s
 * @s: the main string
 * @words: array of words
 * @nb_words: number of words
 * @s_len: length of s
 * @word_len: length of each word
 * @total_len: total length to check at each start
 * @n: pointer to int for storing the count of valid indices
 *
 * Return: pointer to dynamically allocated array of valid indices, or NULL
 */
static int *collect_indices(const char *s, const char **words, int nb_words,
			    int s_len, int word_len, int total_len, int *n)
{
	int *indices, count = 0, i;

	indices = malloc(sizeof(int) * s_len);
	if (!indices)
	{
		*n = 0;
		return (NULL);
	}
	for (i = 0; i <= s_len - total_len; i++)
	{
		if (check_valid(s + i, words, nb_words, word_len))
		{
			indices[count] = i;
			count++;
		}
	}
	if (count == 0)
	{
		free(indices);
		*n = 0;
		return (NULL);
	}
	indices = realloc(indices, count * sizeof(int));
	*n = count;
	return (indices);
}

/**
 * find_substring - finds substrings of s formed by each word in words
 * @s: the string to scan
 * @words: the array of words
 * @nb_words: the number of words
 * @n: pointer to store the number of found substrings
 *
 * Return: dynamically allocated array of indices where substrings start,
 *         or NULL if no valid substring is found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len, word_len, total_len;

	if (!init_lengths(s, words, nb_words, n, &s_len,
			  &word_len, &total_len))
		return (NULL);

	return (collect_indices(s, words, nb_words,
				s_len, word_len, total_len, n));
}

