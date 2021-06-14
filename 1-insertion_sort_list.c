#include "sort.h"

/**
 * insertion_sort_list - Insertion sort algorithm
 *
 * @list: linked list to be sorted
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *aux;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	while (current->next != NULL)
	{
		aux = current->next;
		if (current->n > aux->n)
		{
			temp = current;
			while (temp != NULL && temp->n > aux->n)
			{
				temp->next = aux->next;
				if (temp->next != NULL)
				{
					temp->next->prev = temp;
				}
				aux->prev = temp->prev;
				if (aux->prev != NULL)
				{
					aux->prev->next = aux;
				}
				else
				{
					*list = aux;
				}
				temp->prev = aux;
				aux->next = temp;
				print_list(*list);
				temp = aux->prev;
			}
			continue;
		}
		current = current->next;
	}
}
