#include "sort.h"

/***/

void insertion_sort_list(listint_t **list)
{
	listint_t temp;
	int size = size_of_list(list);

	if (*list == NULL || size < 2)
		return;
}


int size_of_list(listint_t *node)
{
	int count = 0;

	while (node)
	{
		count += 1;
		node = node->next;
	}
	return (count);
}
