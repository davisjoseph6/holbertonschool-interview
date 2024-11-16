#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Finds the maximum value in an array of integers
 * @array: Array of integers
 * @size: Size of the array
 * 
 * Return: The maximum integer in the array
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return (max);
}

/**
 * counting_sort - Sorts the array based on a specific digit
 * @array: Array of integers
 * @size: Size of the array
 * @exp: The exponent corresponding to the digit being sorted
 */
void counting_sort(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t i;

    if (!output)
        return;

    /* Count occurrences of each digit */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Update count[i] to contain the position of this digit in output */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = size; i > 0; i--)
    {
        output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
        count[(array[i - 1] / exp) % 10]--;
    }

    /* Copy sorted elements back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (!array || size < 2)
        return;

    max = get_max(array, size);

    /* Perform counting sort for each digit */
    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
        print_array(array, size); /* Print the array after sorting each digit */
    }
}

