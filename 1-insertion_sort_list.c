#include "sort.h"

/**
 * _swap - Function to swap nodes
 *
 * @tmp: pointer to the head of the list
 *
 */

void _swap(listint_t **tmp)
{
	listint_t *previous, *after;

	previous = (*tmp)->prev;
	after = (*tmp)->next;

	if(after->next != NULL)
		after->next->prev = (*tmp);
	(*tmp)->next = after->next;
	after->prev = previous;
	after->next = (*tmp);
	(*tmp)->prev = after;

	if(previous == NULL)
		*tmp = (*tmp)->prev;
	else
		previous->next = after;
}

/**
 * insertion_sort_list - Insertion sort algorithm
 *
 * @list: linked list to be sorted
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *after;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		after = current->next;
		if (after != NULL && current->n > after->n)
		{
			_swap(&current);

			if (current->prev != NULL)
				current = *list;
			else
				*list = current;

			print_list(*list);
			continue;
		}

		current = current->next;
	}
}
