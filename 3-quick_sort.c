#include "sort.h"

/**
 * partition - Divides array into two partitions
 * @arr: array of ints
 * @low: lower bound or partition
 * @high: upper bound of partition
 * @n: size of array
 * Return: the pivot index
 */

int partition(int arr[], int low, int high, size_t n)
{
	int pivot = arr[high];
	int j, i = (low - 1);
	int temp;

	for (j = low; j <= (high - 1); j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (j != i)
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				print_array(arr, n);
			}
		}
	}
	if (high != (i + 1))
	{
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	print_array(arr, n);
	}
	return (i + 1);
}

/**
 * recursion - recursive algorithm allowing splitting of array into partitions
 * @array: array of ints
 * @low: lower bound or partition
 * @high: upper bound of partition
 * @size: size of array
 */

void recursion(int *array, int low, int high, size_t size)
{
	int pi;

	if (low >= high || low < 0)
		return;

	pi = partition(array, low, high, size);

	recursion(array, low, pi - 1, size);
	recursion(array, pi + 1, high, size);
}

/**
 * quick_sort - sorts an array of ints using Lomuto partition Quicksort
 * @array: array of ints
 * @size: size of array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	recursion(array, 0, (int)(size - 1), size);
}
