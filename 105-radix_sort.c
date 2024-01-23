#include "sort.h"
#include <stdio.h>
/**
* max - A utility function to get maximum value in arr[]
* @array: array
* @size: size of the array
* Return: array
*/
int max(int *array, int size)
{
	int i, m = array[0];

	for (i = 1; i < size; i++)
		if (array[i] > m)
			m = array[i];
	return (m);
}

/**
* countingsort - A function to do counting sort of array[] according to
* the digit represented by exp.
* @array: array
* @size: size of the array
* @exp: exp is 10^i
* @output: array to save the temporary values
*/
void countingsort(int *array, size_t size, int exp, int *output)
{
	int i;
	int count[10] = {0};

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
}

/**
* radix_sort - The main function to that sorts arr[]
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	int exp, maximum = 0;
	int *output = 0;

	if (array == NULL || size < 2)
		return;

	maximum = max(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;
	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		countingsort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
