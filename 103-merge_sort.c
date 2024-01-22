#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *merge - Merges two subarrays in ascending order
 *@array: Original array
 *@temp: Temporary array to store merged elements
 *@left: Left index of the subarray
 *@mid: Middle index of the subarray
 *@right: Right index of the subarray
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);

	printf("[right]: ");
	print_array(array + mid, right - mid);

	i = left;
	j = mid;
	k = 0;

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];

	while (j < right)
		temp[k++] = array[j++];

	for (i = 0, k = left; k < right; ++i, ++k)
		array[k] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 *merge_sort_recursive - Recursive helper function for merge sort
 *@array: Original array
 *@temp: Temporary array to store merged elements
 *@left: Left index of the subarray
 *@right: Right index of the subarray
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, mid, right);
		merge(array, temp, left, mid, right);
	}
}

/**
 *merge_sort - Sorts an array of integers in ascending order using
 *             the Merge sort algorithm (top-down)
 *@array: Array of integers to be sorted
 *@size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}
