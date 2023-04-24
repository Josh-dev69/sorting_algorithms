#include "sort.h"

void quick_sort_helper(int *array, int lo, int hi, size_t size);
int partition(int *array, int lo, int hi, size_t size);

/**
 * quick_sort - Function that sorts an array in ascending order
 * using the Quick sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - quick sort helper
 * @array: pointer to the array
 * @lo: lower
 * @hi: higher
 * @size: size of the array
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, hi, size);
	}
}

/**
 * partition - partition
 * @array: pointer to the array
 * @lo: lower
 * @hi: higher
 * @size: size of the array
 * Return: integer value(the index of the pivot)
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int i = lo - 1, j = lo;
	int pivot = array[hi], temp = 0;
	/* iterate over the range of the partition */
	for (; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			/* increment the lower index and swap elements at i and j */
			i++;
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				/* Print Array */
				print_array(array, size);
			}
		}
	}
	/* swap the pivot element into its correct position */
	if (array[i + 1] != array[hi])
	{
		temp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = temp;
		/* Print the Array */
		print_array(array, size);
	}
	return (i + 1);
}
