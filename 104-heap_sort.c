#include "sort.h"

/**
 * swap - swaps position of two elements in a binary tree
 * @a: First element
 * @b: Second element
 *
 * Return: Void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * siftDown - employs the "siftdown" part of the algorithm
 * @array: array of ints
 * @i: index of int to be swapped
 * @len: length of the array as int
 * @size: size of the array
 * Return: void
 */

void siftDown(int *array, int i, int len, size_t size)
{
	int largest = i;
	int left = (2 * i + 1);
	int right = (2 * i + 2);

	if (left < len && array[left] > array[largest])
		largest = left;
	if (right < len && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		siftDown(array, largest, len, size);
	}
}

/**
 * heap_sort - sorts an array of ints using the Heapsort algorithm
 * @array: array of ints
 * @size: size of array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i, len = (int)size;

	for (i = size / 2 - 1; i >= 0; i--)
		siftDown(array, i, len, size);

	for (i = len - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		siftDown(array, 0, i, size);
	}
}
