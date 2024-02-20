#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swaper_nodes - Swaps two nodes in a doubly linked list
 * @list: Double per to the head of the list
 * @ndp: First node to swap
 * @nds: Second node to swap
 */
void swaper_nodes(listint_t **list, listint_t *ndp, listint_t *nds)
{
	if (ndp == NULL || nds == NULL)
		return;

	if (ndp->prev != NULL)
		ndp->prev->next = nds;
	else
		*list = nds;

	if (nds->next != NULL)
		nds->next->prev = ndp;

	ndp->next = nds->next;
	nds->prev = ndp->prev;
	ndp->prev = nds;
	nds->next = ndp;
}

/**
 * forward_pass - Performs a forward pass of the Cocktail Shaker Sort algorithm
 * @list: Double per to the head of the list
 */
void forward_pass(listint_t **list)
{
	int swap = 0;
	listint_t *p = *list;

	while (p->next != NULL)
	{
		if (p->n > p->next->n)
		{
			swaper_nodes(list, p, p->next);
			swap = 1;
			print_list(*list);
		}
		else
			p = p->next;
	}
	if (!swap)
		return;
}

/**
 * backward_pass - Performs a backward pass of the Cocktail Shaker.
 * @list: Double per to the head of the list
 */
void backward_pass(listint_t **list)
{
	int swap = 0;
	listint_t *p = *list;

	while (p->prev != NULL)
	{
		if (p->n < p->prev->n)
		{
			swap_nodes(list, p->prev, p);
			swap = 1;
			print_list(*list);
		}
		else
		{
			p = p->prev;
		}
	}
	if (!swap)
		return;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * @list: Double per to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swap;

	if (list == NULL || *list == NULL)
		return;
	do {
		swap = 0;
		forward_pass(list);
		backward_pass(list);
	} while (swap);
}

