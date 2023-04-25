#include "sort.h"

void sift_down(int *array, size_t size, size_t start, size_t orig_size);

/**
 * heap_sort - function that sorts an array using the heap sort algorithm.
 * @array: pointer to the array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i, last_parent;
	int tmp;

	if (array == NULL || size < 2)
		return;

	last_parent = (size / 2) - 1;
	for (i = last_parent; i + 1 > 0; i--)
		sift_down(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		sift_down(array, i, 0, size);
	}
}

/**
 * sift_down - function that sifts down the element at the given index.
 * @array: pointer to the array to sift down.
 * @size: The size of the heap.
 * @start: The index to start sifting down.
 * @orig_size: The original size of the array.
 */
void sift_down(int *array, size_t size, size_t start, size_t orig_size)
{
	size_t root = start, child, swap;
	int tmp;

	while (2 * root + 1 < size)
	{
		child = 2 * root + 1;
		swap = root;
		if (array[swap] < array[child])
			swap = child;
		if (child + 1 < size && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;
		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;
		print_array(array, orig_size);
		root = swap;
	}
}
