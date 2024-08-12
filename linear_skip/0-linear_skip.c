#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where value is located,
 *         or NULL if value is not present or list is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = NULL;
	skiplist_t *curr = list;

	if (!list)
		return (NULL);

	/* Traverse express lane first */
	while (curr->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				curr->express->index, curr->express->n);
		if (curr->express->n >= value)
			break;
		curr = curr->express;
	}

	/* Identify the range between prev and curr */
	prev = curr;
	if (curr->express && curr->express->n >= value)
		curr = curr->express;
	else
	{
		while (curr->next)
			curr = curr->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, curr->index);

	/* Traverse regular lane within the identified range */
	while (prev != NULL && prev->index <= curr->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
