#include "sort.h"

/**
 * merge - rearranges subarray before re-merging them back together
 * @array: array of ints
 * @temp: temporary array
 * @left: left side of array
 * @mid: middle of array
 * @right: right side of array
 * Return: void
 */

void merge(int *array, int *temp, int left, int mid, int right)
{
	int i, aPos, bPos;

	aPos = left;
	bPos = mid;

	for (i = left; i < right; i++)
	{
		if (aPos < mid && (bPos >= right || array[aPos] <= array[bPos]))
		{
			temp[i] = array[aPos];
			aPos++;
		}
		else
		{
			temp[i] = array[bPos];
			bPos++;
		}
	}
}

/**
 * print_subarray - prints a subarray given start and end
 *
 * @arr: array containing subarray to print
 * @start: first index to print
 * @end: index to print to
 */
void print_subarray(int *arr, int start, int end)
{
	int i;

	for (i = start; i < end - 1; i++)
		printf("%d, ", arr[i]);
	printf("%d\n", arr[i]);
}

/**
 * sort - splits array into halves,
 *  then calls itself recursively before passing onto merge function
 * @arr: array of ints
 * @temp: temporary array
 * @left: left side of array
 * @right: right side of array
 * Return: void
 */

void sort(int *arr, int *temp, int left, int right)
{
	int mid;

	if (right - left <= 1)
		return;

	mid = (left + right) / 2;

	/* recursively split */
	sort(temp, arr, left, mid);
	sort(temp, arr, mid, right);

	/* merge back together */
	merge(arr, temp, left, mid, right);

	printf("Merging...\n[left]: ");
	print_subarray(arr, left, mid);
	printf("[right]: ");
	print_subarray(arr, mid, right);
	printf("[Done]: ");
	print_subarray(temp, left, right);
}

/**
 * merge_sort - sorts an array of ints using the Merge-sort algorithm
 * @array: array of ints
 * @size: size of array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *temp, i;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	for (i = 0; i < (int)size; i++)
		temp[i] = array[i];
	sort(temp, array, 0, size);
	free(temp);
}
