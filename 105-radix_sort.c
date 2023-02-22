#include "sort.h"

/**
 * get_max - Function to get the largest element from an array
 * @array: array
 * @size: size of array
 * Return: max element
 */
int get_max(int *array, int size)
{
	int max = array[0];
	int i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * mallocate - malloc and fill an array
 * @size: size of array
 * Return: pointer to array
 */
int *mallocate(int size)
{
	int i;
	int *arr;

	arr = malloc(sizeof(int) * (size));
	if (!arr)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = 0;
	return (arr);
}

/**
 * sorting_out - sorting to buckets in matrix, by significant places
 * @array: array to sort
 * @size: size of array
 * @place: current place we're sorting by
 * @o: number of 0's in array
 * Return: void
 */
void sorting_out(int *array, int size, int place)
{
	int *matrix, *list, i;

	matrix = mallocate(10);
	if (!matrix)
		return;

	for (i = 0; i < size; i++)
		matrix[(array[i] / place) % 10]++;

	for (i = 1; i < 10; i++)
		matrix[i] = matrix[i] + matrix[i - 1];

	list = malloc(sizeof(int) * (size));
	if (!list)
		return;

	for (i = size - 1; i >= 0; i--)
	{
		list[matrix[(array[i] / place) % 10] - 1] = array[i];
		matrix[(array[i] / place) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = list[i];

	free(list);
	free(matrix);
}

/**
 * radix_sort - sorts an array of ints using the LSD Radix sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int place, max;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (place = 1; max / place > 0; place *= 10)
	{
		sorting_out(array, size, place);
		print_array(array, size);
	}
}
