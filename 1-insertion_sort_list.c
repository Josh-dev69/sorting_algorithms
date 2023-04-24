#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 * @list: double pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		prev = current->prev;
		temp = current->next;
		while (prev != NULL && prev->n > current->n)
		{
			/* Swap the nodes */
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;
			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			/* Print the list after each swap */
			print_list(*list);
			prev = current->prev;
		}
		current = temp;
	}
}
