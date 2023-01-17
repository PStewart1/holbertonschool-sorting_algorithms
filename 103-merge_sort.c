#include "sort.h"

/**
 * merge - rearranges subarray before re-merging them back together
 * @arr: array of ints
 * @l: left side of array
 * @m: middle of array
 * @r: right side of array
 * Return: void
 */

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int p;

    /* create temp arrays */
    int* L = malloc(n1 * sizeof(int));
    int* R = malloc(n2 * sizeof(int));

    printf("Merging...\n");

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    printf("[left]:");
    for(p = 0; p < n1; p++)
      printf(" %d", L[p]);
    printf("\n");

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    printf("[right]:");
    for(p = 0; p < n2; p++)
      printf(" %d", R[p]);
    printf("\n");

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);

    printf("[Done]:");
    for(p = l; p <= r; p++)
      printf(" %d", arr[p]);
    printf("\n");
}


/**
 * sort - splits array into halves, then calls itself recursively before passing onto merge function
 * @arr: array of ints
 * @l: left side of array
 * @r: right side of array
 * Return: void
 */

void sort(int arr[], int l, int r)
{
    if (l < r) {

    int m = l + (r - l) / 2;

    sort(arr, l, m);
    sort(arr, m + 1, r);

    merge(arr, l, m, r);
    }
}

/**
 * merge_sort - sorts an array of ints using the Merge-sort algorithm
 * @array: array of ints
 * @size: size of array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
    if (array == NULL)
		return;
	if (size < 2)
	{
		return;
	}
    sort(array, 0, size - 1);
}
