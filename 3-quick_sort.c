#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending
 *              order using the Quick sort algorithm.
 *
 * @array: The array.
 * @size: Array size.
 *
 */

void quick_sort(int *array, size_t size)
{
	execution(array, 0, (int)(size - 1), size);
}

/**
 * execution - Sorts an array of integers in ascending
 *             order using the Quick sort algorithm.
 *
 * @array: The array.
 * @initial: Initial index.
 * @final: Final index.
 * @size: Array size.
 *
 */

void execution(int *array, int initial, int final, size_t size)
{
	if (initial < final)
	{
		int pi = lomuto_partition(array, initial, final, size);

		execution(array, initial, pi - 1, size);
		execution(array, pi + 1, final, size);
	}
}

/**
 * lomuto_partition - Iterates over the input array, swapping elements
 *                    that are strictly less than a preselected pivot element.
 *
 * @array: The array.
 * @initial: Initial index.
 * @final: Final index.
 * @size: Array size.
 *
 * Return: Next index.
 */

int lomuto_partition(int *array, int initial, int final, size_t size)
{
	int i, j, pivot;

	pivot = array[final];
	i = (initial - 1);

	for (j = initial; j <= (final - 1); j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j);

			if (i != j)
				print_array(array, size);
		}
	}

	swap(array, (i + 1), final);

	if ((i + 1) < j)
		print_array(array, size);

	return (i + 1);
}

/**
 * swap - Swap two values in an array.
 *
 * @array: The array.
 * @i: First index.
 * @j: Second index.
 *
 */

void swap(int *array, int i, int j)
{
	int x = 0;

	x = array[i];
	array[i] = array[j];
	array[j] = x;
}
