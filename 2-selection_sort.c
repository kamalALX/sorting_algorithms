#include "sort.h"

/**
 * selection_sort -  a function that sorts an array
 *	of integers in ascending order using the Selection sort algorithm
 *
 * @array: array to sort.
 * @size: size of the array.
*/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, swap;
	int current_min;
	int current_item;

	for (i = 0; i < size; i++)
	{
		swap = 0;
		current_min = array[i];
		for (j = i + 1; j < size; j++)
		{
			current_item = array[j];
			if (current_item < current_min)
			{
				current_min = current_item;
				swap = j;
			}
		}
		if (swap != 0)
		{
			array[swap] = array[i];
			array[i] = current_min;
			print_array(array, size);
		}
	}
}
