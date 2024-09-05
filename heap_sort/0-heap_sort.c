#include "sort.h"

/**
 * heapify - Ensures the max-heap property for a subtree
 * @array: The array to be sorted
 * @size: Total size of the array
 * @i: The index of the current node
 * @n: The size of the heap
 */
void heapify(int *array, size_t size, int i, size_t n)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < (int)n && array[left] > array[largest])
		largest = left;

	if (right < (int)n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		int temp = array[i];

		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, size);  /* Print after each swap */

		heapify(array, size, largest, n);
	}

}

/**
 * heap_sort - Sorts an array of integers using heap sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	/* Build the max heap */
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	/* Extract elements from the heap one by one */
	for (int i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);  /* Print after each swap */

		heapify(array, size, 0, i);
	}
}
