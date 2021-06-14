#include "sort.h"

/**
 * insertion_sort_list - Insertion sort algorithm
 *
 * @list: linked list to be sorted
 * Return: sorted array
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *aux;
	listint_t *tmp;

	if (!list || *list == NULL)
		return;
	current = *list;
	if (current->next == NULL)
		return;
	while (current->next != NULL)
	{
		aux = current->next;
		if (current->n > aux->n)
		{
			tmp = current;
			while (tmp != NULL && tmp->n > aux->n)
			{
				tmp->next = aux->next;
				if (tmp->next != NULL)
				{
					tmp->next->prev = tmp;
				}
				aux->prev = tmp->prev;
				if (aux->prev != NULL)
				{
					aux->prev->next = aux;
				}
				else
				{
					*list = aux;
				}
				tmp->prev = aux;
				aux->next = tmp;
				print_list(*list);
				tmp = aux->prev;
			}
			continue;
		}
		current = current->next;
	}
}
