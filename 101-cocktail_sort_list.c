#include "sort.h"

void swap_nodes(listint_t **list, listint_t *curr, listint_t *nxt);
/**
 * swap_nodes - function that swap two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @curr: current node to swap
 * @nxt: next node to swap
 */
void swap_nodes(listint_t **list, listint_t *curr, listint_t *nxt)
{
	curr->next = nxt->next;
	if (curr->n)
		curr->next->prev = curr;
	nxt->next = curr;
	if (nxt->prev)
		nxt->prev->next = nxt;
	else
		*list = nxt;
	curr->prev = nxt;

	print_list(*list);
}

/**
 * cocktail_sort_list - sort a doubly linked list using Cocktail Shaker Sort
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *front_runner, *back_runner;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;
	front_runner = (*list);
	back_runner = NULL;
	while (swapped == 1)
	{
		swapped = 0;
		while (front_runner->next && front_runner != back_runner)
		{
			if (front_runner->n > front_runner->next->n)
			{
				swapped = 1;
				swap_nodes(list, front_runner, front_runner->next);
			}
			else
				front_runner = front_runner->next;
		}
		back_runner = front_runner;
		if (swapped == 0)
			break;
		swapped = 0;
		while (front_runner->prev && front_runner != *list)
		{
			if (front_runner->n < front_runner->prev->n)
			{
				swapped = 1;
				swap_nodes(list, front_runner->prev, front_runner);
			}
			else
				front_runner = front_runner->prev;
		}
		*list = front_runner;
	}
}
