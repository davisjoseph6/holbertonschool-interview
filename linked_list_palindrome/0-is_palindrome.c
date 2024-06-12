#include "lists.h"
#include <stddef.h>

/**
 * reverse_list - reverses a linked list.
 * @head: pointer to the head of the list to reverse.
 *
 * Return: pointer to the new head of the reversed list.
 */
listint_t *reverse_list(listint_t * head)
{
	listint_t *prev = NULL;
	listint_t *current = head;
	listint_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: double pointer to the head of the list.
 *
 * Return: 1 if the list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	listint *slow, *fast, *first_half, *second_half, *second_half_reversed, *first, *second;
	if (head == NULL || *head == NULL)
		return(1);

	*slow = *head;
	*fast = *head;
	*first_half = *head;
	*second_half = NULL;
	*second_half_reversed = NULL;
	is_palindrome = 1;

	/* Find the middle of the list */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	/* Reverse the second half of the list */
	second_half = slow;
	second_half_reversed = reverse_list(second_half);

	/* Compare the first half and the reversed second half */
	listint_t *first = first_half;
	listint_t *second = second_half_reversed;
	int is_palindrome = 1;

	while (second != NULL)
	{
		if (first->n != second->n)
		{
			is_palindrome = 0;
			break;
		}
		first = first->next;
		second = second->next;
	}

	/* Restore the second half to its original order */
	reverse_list(second_half_reversed);

	return is_palindrome;
}
