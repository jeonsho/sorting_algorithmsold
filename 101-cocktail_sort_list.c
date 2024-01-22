#include "sort.h"

/**
 *swap_nodes - Swaps two nodes in a doubly linked list
 *@list: The list to which the nodes belong
 *@node1: The first node
 *@node2: The second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node2->prev == NULL)
		*list = node2;
}

/**
 *cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                     order using the Cocktail shaker sort algorithm.
 *@list: The doubly linked list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped = true;
	listint_t *current;

	if (!list || !(*list))
		return;

	while (swapped)
	{
		swapped = false;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = true;
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;
		swapped = false;
		current = current->prev;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = true;
			}
			else
				current = current->prev;
		}
	}
}
