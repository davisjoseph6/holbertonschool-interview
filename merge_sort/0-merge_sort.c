#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two sorted halves of an array
 * @array: The original array being sorted
 * @left: The left half of the array
 * @right: The right half of the array
 * @left_size: Size of the left half
 * @right_size: Size of the right half
 */
void merge(int *array, int *left, int *right, size_t left_size, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;

    printf("Merging...\n[left]: ");
    for (i = 0; i < left_size; i++)
        printf("%d%s", left[i], i == left_size - 1 ? "" : ", ");
    printf("\n[right]: ");
    for (i = 0; i < right_size; i++)
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
 * @array: The array to be sorted
 * @temp: Temporary array used for merging
 * @size: The size of the array
 */
void top_down_merge_sort(int *array, int *temp, size_t size)
{
    if (size < 2)
        return;

    size_t mid = size / 2;
    int *left = temp;
    int *right = temp + mid;

    for (size_t i = 0; i < mid; i++)
        left[i] = array[i];
    for (size_t i = mid; i < size; i++)
        right[i - mid] = array[i];

    top_down_merge_sort(left, temp, mid);
    top_down_merge_sort(right, temp, size - mid);
    merge(array, left, right, mid, size - mid);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    int *temp = malloc(sizeof(int) * size);
    if (!temp)
        return;

    top_down_merge_sort(array, temp, size);
    free(temp);
}

