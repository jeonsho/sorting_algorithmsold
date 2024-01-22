#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *counting_sort - Sorts an array of integers in ascending order using the
 *                Counting sort algorithm
 *@array: Array of integers to be sorted
 *@size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int k = 0;
	int *count_array, *output_array;
	size_t i;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i]; }
	count_array = malloc((k + 1) * sizeof(int));
	if (!count_array)
		return;
	for (i = 0; i <= (size_t) k; i++)
		count_array[i] = 0;
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	for (i = 1; i <= (size_t) k; i++)
		count_array[i] += count_array[i - 1];
	for (i = 0; i <= (size_t) k; i++)
	{
		printf("%d", count_array[i]);
		if (i < (size_t) k)
			printf(", "); }
	printf("\n");
	output_array = malloc(size * sizeof(int));
	if (!output_array)
	{
		free(count_array);
		return; }
	for (i = 0; i < size; i++)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	free(count_array);
	free(output_array);
}
