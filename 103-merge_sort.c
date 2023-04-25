#include "sort.h"

void merge_partition(size_t lo, size_t hi, int *array, int *base);
void merge(size_t lo, size_t mid, size_t hi, int *dest, int *src);

/**
 * merge_sort - A function that sorts an array using merge algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *base = NULL;

	if (array == NULL || size < 2)
		return;
	base = malloc(sizeof(int) * size);
	if (base == NULL)
		return;
	for (; i < size; i++)
		base[i] = array[i];
	merge_partition(0, size, array, base);
	free(base);
}

/**
 * merge - A function that sorts the subarrays.
 * @lo: Lower index.
 * @mid: Middle index.
 * @hi: Higher index.
 * @dest: Destination for data.
 * @src: Input data.
 */
void merge(size_t lo, size_t mid, size_t hi, int *dest, int *src)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + lo, mid - lo);
	printf("[right]: ");
	print_array(src + mid, hi - mid);
	i = lo;
	j = mid;
	k = lo;
		for (; k < hi; k++)
		{
			if (i < mid && (j >= hi || src[i] <= src[j]))
			{
				dest[k] = src[i];
				i++;
			}
			else
			{
				dest[k] = src[j];
				j++;
			}
		}
	printf("[Done]: ");
	print_array(dest + lo, hi - lo);
}

/**
 * merge_partition -Function that recursively partitions the array into smaller
 * sub-arrays until the sub-arrays contain only one or zero elements.
 * @lo: Lowest index of the array.
 * @hi: Highest index of the array.
 * @array: Pointer to the array to sort.
 * @base: The copy of the array.
 */
void merge_partition(size_t lo, size_t hi, int *array, int *base)
{
	size_t mid = 0;

	if (hi - lo < 2)
		return;
	mid = (lo + hi) / 2;
	merge_partition(lo, mid, array, base);
	merge_partition(mid, hi, array, base);
	merge(lo, mid, hi, array, base);
	for (mid = lo; mid < hi; mid++)
		base[mid] = array[mid];
}
