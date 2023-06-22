#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *swp_nd, *next_swp;

	if (list == NULL || *list == NULL)
		return;
	swp_nd = (*list)->next;
	while (swp_nd != NULL)
	{
		next_swp = swp_nd->next;
		while (swp_nd->prev != NULL && swp_nd->prev->n > swp_nd->n)
		{
			swp_nd->prev->next = swp_nd->next;
			if (swp_nd->next != NULL)
				swp_nd->next->prev = swp_nd->prev;
			swp_nd->next = swp_nd->prev;
			swp_nd->prev = swp_nd->next->prev;
			swp_nd->next->prev = swp_nd;
			if (swp_nd->prev == NULL)
				*list = swp_nd;
			else
				swp_nd->prev->next = swp_nd;
			print_list(*list);
		}
		swp_nd = next_swp;
	}
}
