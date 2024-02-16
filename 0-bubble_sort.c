#include "sort.h"

/**
 * bubble_sort - a function that sorts an array
 *			using bubble sort algorithm.
 *	@array: the array to be sorted.
 *	@size: the size of the array.
*/

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, idx;
	int min_int, swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			swapped = 0;
			if (array[j + 1] < array[j])
			{
				min_int = array[j + 1];
				array[j + 1] = array[j];
				array[j] = min_int;

				swapped = 1;
			}
			if (swapped == 1)
			{
				for (idx = 0; idx < size; idx++)
				{
					printf("%i", array[idx]);
					if (idx < size - 1)
						printf(", ");
				}
				printf("\n");
			}
		}
		if (swapped == 0)
			break;
	}
}
