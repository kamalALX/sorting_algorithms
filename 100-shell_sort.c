#include "sort.h"

/***/

size_t max_gap(size_t size)
{
	size_t max = 1;

	while (max < size)
	{
		max = max * 3 + 1;
	}
	return ((max - 1) / 3);
}

/***/

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL || !size)
		return;

	for (gap = max_gap(size); gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i;  temp < array[j - gap] && gap - 1 < j; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
