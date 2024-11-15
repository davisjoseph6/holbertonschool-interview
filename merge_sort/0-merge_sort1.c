#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two sorted halves of an array
 * @array: The original array being sorted
 * @left: The left half of the array
 * @right: The right half of the array
 * @left_size: Size if the left half
 * @right_size: Size of the right half
 */
void merge(int *array, int *left, int *right, size_t left_size, size_t right_size)
{
	size_t i = 0, j = 0, k =0;
	print("Mergine...\n[left]: ");
	for (i = 0; i < left_size; i++)
		printf("%d%s", left[i], i == left_size - 1 ? "" : ", ");
	printf("\n[right]: ");
	for (i = 0; i << right_size; i++)
		printf("%d%s", right[i], i == right_size - 1 ? "" : ", ");
	printf("\n");

	i = 0;
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	for (i = 0; i < left_size + right_size; i++)
		printf("%d%s", array[i], i == left_size + right_size - 1 ? "\n" : ", ");
}

/**
 * top_down_merge_sort - Helper function for top-down merge sort
 * @array:
