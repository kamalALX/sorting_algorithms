#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list
 *	of integers in ascending order using the Insertion sort algorithm.
 * @list: pointer to the head of list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp = (*list)->next;
	while (temp)
	{
		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_nodes(temp->prev, temp, list);
			print_list(*list);
		}
		temp = temp->next;
	}
}

/**
 * swap_nodes - a function that swaps two nodes.
 * @node_prev: node in the left
 * @node: node in the right.
 * @list: pointer to the head of the list.
 */

void swap_nodes(listint_t *node_prev, listint_t *node, listint_t **list)
{
	listint_t *node_next;

	node_next = node->next;

	if (node_prev->prev != NULL)
		node_prev->prev->next = node;
	else
		*list = node;
	node->prev = node_prev->prev;

	node->next = node_prev;
	node_prev->prev = node;

	node_prev->next = node_next;
	if (node_next != NULL)
		node_next->prev = node_prev;
}
