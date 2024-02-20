#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - Sorts an array of integers using the quicksort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - Helper function for quick_sort, sorts an array recursively
 *
 * @array: The array to be sorted
 * @left: The left index of the sub-array
 * @right: The right index of the sub-array
 * @size: The size of the array
*/
void quicksort(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left >= right)
		return;
	pivot = partition(array, left, right, size);
	quicksort(array, left, pivot - 1, size);
	quicksort(array, pivot + 1, right, size);
}

/**
 *  partition - Partitions the array for quicksort
 *
 * @array: The array to be partitioned
 * @left: The left index of the sub-array
 * @right: The right index of the sub-array
 * @size: The size of the array
 *
 * Return: Index of the pivot element after partitioning
 */
int partition(int *array, int left, int right, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[right];
	j = left;
	for (i = left; i < right; i++)
	{
		if (array[i] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
			j++;
		}
	}
	temp = array[j];
	array[j] = array[right];
	array[right] = temp;
	if (j != right)
		print_array(array, size);
	return (j);
}
