#ifndef _SORTING_
#define _SORTING_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t *node_prev, listint_t *node, listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort(int *array, int left, int right, size_t size);
int partition(int *array, int left, int right, size_t size);
void cocktail_sort_list(listint_t **list);
void swaper_nodes(listint_t **list, listint_t *ndp, listint_t *nds);
void forward_pass(listint_t **list);
void backward_pass(listint_t **list);
#endif /* _SORTING_*/

