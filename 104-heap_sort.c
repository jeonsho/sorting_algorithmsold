#include "sort.h"
#include <stdio.h>

/**
 *heapify - Adjusts the heap rooted at index 'i'
 *@array: Array of integers
 *@size: Size of the array
 *@i: Index to start heapifying from
 */
void heapify(int *array, size_t size, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		int temp = array[i];

		array[i] = array[largest];
		array[largest] = temp;

		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 *heap_sort - Sorts an array of integers in ascending order using Heap sort
 *@array: Array of integers to be sorted
 *@size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (!array || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		heapify(array, i, 0);
	}
}
