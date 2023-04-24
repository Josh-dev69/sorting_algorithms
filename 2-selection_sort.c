#include "sort.h"

/**
 * selection_sort - Function that performs selection sorting
 * array: pointer to the array to be sorted.
 * size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, pos = 0;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pos])
				pos = j;
		}
		if (pos != i)
		{
			/* Swap the elements */
			temp = array[i];
			array[i] = array[pos];
			array[pos] = temp;
			/* Print the array */
			print_array(array, size);
		}
	}
}
