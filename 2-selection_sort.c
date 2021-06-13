#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending
 *                  order using the Selection sort algorithm.
 *
 * @array: The array.
 * @size: Array size.
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t temp, min, i, j, change;

	temp = min = change = i = j = 0;

	for (i = 1; i < size; i++)
	{
		change = 0;
		min = i - 1;

		for (j = i; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				change = 1;
			}
		}

		if (change == 1)
		{
			temp = array[i - 1];
			array[i - 1] = array[min];
			array[min] = temp;

			print_array(array, size);
		}
	}
}
