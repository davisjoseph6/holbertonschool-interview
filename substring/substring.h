#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <stdio.h>

/**
 * find_substring - finds all possible substrings containing a list of words
 * @s: string to scan
 * @words: array of words (all of the same length)
 * @nb_words: number of elements in @words
 * @n: address at which to store the number of elements in the returned array
 *
 * Description:
 * A valid substring is the concatenation of each word in @words exactly
 * once, without any intervening characters, in any order.
 *
 * Return: an allocated array of indices in @s where such a substring starts,
 * or NULL if no valid substring is found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */

