#include "sort.h"
#include <stdio.h>

/**
 * swap_node - swaps a node with the next node in the list
 * @hd: double pointer to the beginning of the list
 * @nd: node to swap
 *
 * Return: void
 */
void swap_node(listint_t **hd, listint_t *nd)
{
	nd->next->prev = nd->prev;
	if (nd->prev)
		nd->prev->next = nd->next;
	else
		*hd = nd->next;
	nd->prev = nd->next;
	nd->next = nd->next->next;
	nd->prev->next = nd;
	if (nd->next)
		nd->next->prev = nd;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *cp;

	if (list == NULL || *list == NULL)
		return;
	cp = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (cp->next != NULL)
		{
			if (cp->next->n < cp->n)
			{
				swap_node(list, cp);
				swapped = 1;
				print_list(*list);
			}
			else
				cp = cp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (cp->prev != NULL)
		{
			if (cp->prev->n > cp->n)
			{
				swap_node(list, cp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				cp = cp->prev;
		}
	}
}
