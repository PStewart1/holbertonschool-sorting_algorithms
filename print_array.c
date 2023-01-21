#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
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
