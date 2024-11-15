#include "sort.h"

/**
 * sort - Sorts subarrays and merges them into the original array
 * @arr: Pointer to the original array
 * @l: Pointer to the left subarray
 * @r: Pointer to the right subarray
 * @start: Start index of the left subarray
 * @mid: End index of the left subarray
 * @end: End index of the right subarray
 *
 * Return: None
 */
void sort(int *arr, int *l, int *r, int start, int mid, int end)
{
	int left_iter = 0, right_iter = 0, array_iter = start;
	int left_size = mid - start + 1;
	int right_size = end - mid;

	while (left_iter < left_size && right_iter < right_size)
	{
		if (l[left_iter] <= r[right_iter])
			arr[array_iter++] = l[left_iter++];
		else
			arr[array_iter++] = r[right_iter++];
	}

	while (left_iter < left_size)
		arr[array_iter++] = l[left_iter++];

	while (right_iter < right_size)
		arr[array_iter++] = r[right_iter++];
}

/**
 * merge - Merges two subarrays into the original array
 * @array: Pointer to the original array
 * @start: Start index of the left subarray
 * @mid: End index of the left subarray
 * @end: End index of the right subarray
 *
 * Return: None
 */
void merge(int *array, int start, int mid, int end)
{
	int left_size = mid - start + 1;
	int right_size = end - mid;
	int left[left_size];
	int right[right_size];
	int left_iter, right_iter;

	for (left_iter = 0; left_iter < left_size; left_iter++)
		left[left_iter] = array[start + left_iter];

	for (right_iter = 0; right_iter < right_size; right_iter++)
		right[right_iter] = array[mid + 1 + right_iter];

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	sort(array, left, right, start, mid, end);

	printf("[Done]: ");
	print_array(&array[start], left_size + right_size);
}

/**
 * split_arrays - Recursively splits the array into subarrays
 * @array: Pointer to the original array
 * @start: Start index of the subarray
 * @end: End index of the subarray
 *
 * Return: None
 */
void split_arrays(int *array, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end - 1) / 2;

		split_arrays(array, start, mid);
		split_arrays(array, mid + 1, end);

		merge(array, start, mid, end);
	}
}

/**
 * merge_sort - Sorts an array using the merge sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 *
 * Return: None
 */
void merge_sort(int *array, size_t size)
{
	if (array && size >= 2)
		split_arrays(array, 0, size - 1);
}
