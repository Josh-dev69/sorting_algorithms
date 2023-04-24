#include "sort.h"

/**
 * bubble_sort - Function that performs bubble sorting
 * @array: the array
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	if (array == NULL || size == 0)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap the elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				/* Print array */
				print_array(array, size);
			}
		}
	}
}
