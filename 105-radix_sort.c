#include "sort.h"

/**
 * getMax - Function to get the largest element from an array
 * @array: array
 * @size: size of array
 * Return: max element
 */
int get_max(int array[], int size)
{
	int max = array[0];
	int i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * countingSort - sorting to buckets in matrix, by significant places
 * @array: array to sort
 * @size: size of array
 * @place: current place we're sorting by
 * @o: number of 0's in array
 * Return: void
 */
void sorting_out(int array[], int size, int place, int o)
{
	int(*matrix)[10] = malloc(size * sizeof(*matrix));
	int i, j, k, n;

	for (i = 0; i < size; i++)
	{
		n = (array[i] / place) % 10;
		for (j = 0; j < 10; j++)
		{
			if (matrix[n][j] == 0)
			{
				matrix[n][j] = array[i];
				break;
			}
		}
	}
	for (i = 0; i < size; i++)
	{
		if (o > 0)
		{
			array[i] = 0;
			o--;
			continue;
		}
		for (j = 0; j < 10; j++)
		{
			for (k = 0; k < size; k++)
			{
				if (matrix[j][k] != 0)
				{
					array[i] = matrix[j][k];
					i++;
					if (i == size)
						return;
				}
				else
					break;
			}
		}
	}
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
	int place, max, i, o = 0;

	max = get_max(array, size);
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] == 0)
			o++;
	}
	for (place = 1; max / place > 0; place *= 10)
	{
		sorting_out(array, size, place, o);
		print_array(array, size);
	}
}
