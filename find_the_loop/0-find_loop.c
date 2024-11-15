#include "lists.h"

/**
 * find_listint_loop - Find the start of a loop in a linked list
 * @head: Pointer to the head of the list
 *
 * Return: Address of the node where the loop starts, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;		/* Move slow pointer one step */
		fast = fast->next->next;	/* Move fast pointer two steps */

		if (slow == fast)		/* Loop detected */
		{
			slow = head;		/* Move slow pointer to the start */
			while (slow != fast)
			{
				slow = slow->next;	/* Move both ponters one step */
				fast = fast->next;
			}
			return (slow);			/* Start of the loop */
		}
	}

	return (NULL);					/* No loop found */
}
