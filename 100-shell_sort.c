#include "sort.h"

/**
 * shell_sort - sorts an array in ascending order using the Shell sort
 * algorithm with the Knuth sequence of intervals
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j, temp;
	/* calculate the initial gap value */
	while (gap < (int)size / 3)
		gap = gap * 3 + 1;
	/* iterate over each gap value in the sequence */
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		/* perform an insertion sort with the current gap value */
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		/* print the array after each decrease in gap value */
		print_array(array, size);
	}
}
