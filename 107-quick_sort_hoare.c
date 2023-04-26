#include "sort.h"

int hoare_partition(int *array, int lo, int hi, size_t size);
void quicksort(int *array, int lo, int hi, size_t size);

/**
 * hoare_partition - Partitions an array using the Hoare scheme
 * @array: The array to be partitioned
 * @lo: The lower index of the partition
 * @hi: The upper index of the partition
 * @size: The size of the whole array
 * Return: The final index of the pivot
 */
int hoare_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], tmp;
	int i = lo - 1, j = hi + 1;
	
	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i < j)
			return j;
		/* Swap elements */
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort - Recursively sorts an array using the quicksort algorithm
 * @array: The array to be sorted
 * @lo: The lower index of the partition being sorted
 * @hi: The upper index of the partition being sorted
 * @size: The size of the whole array
 */
void quicksort(int *array, int lo, int hi, size_t size)
{
	int p;
	
	if (hi - lo > 0)
	{
		p = hoare_partition(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p, hi, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using quicksort with Hoare partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	quicksort(array, 0, (int)size - 1, size);
}

