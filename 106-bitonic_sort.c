#include "sort.h"
#include <stdio.h>
/**
 * bitonicswap - change two values in ascending or descending order
 * @array: array
 * @item1: item one
 * @item2: item two
 * @order: 1: ascending order, 0 descending order
 */
void bitonicswap(int array[], int item1, int item2, int order)
{
	int temp;

	if (order == (array[item1] > array[item2]))
	{
		temp = array[item1];
		array[item1] = array[item2];
		array[item2] = temp;
	}
}
/**
 * mergebitonic - sort bitonic sequences recursively in both orders
 * @array: array
 * @low: first element
 * @n: elements number
 * @order: 1: ascending order, 0 descending order
 */
void mergebitonic(int array[], int low, int n, int order)
{
	int mid, i;

	if (n > 1)
	{
		mid = n / 2;
		for (i = low; i < low + mid; i++)
			bitonicswap(array, i, i + mid, order);
		mergebitonic(array, low, mid, order);
		mergebitonic(array, low + mid, mid, order);
	}
}
/**
 * bitonicsort - bitonic sort algorithm implementation
 * @array: array
 * @low: first element
 * @n: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void bitonicsort(int array[], int low, int n, int order, int size)
{
	int mid;

	if (n > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", n, size);
			print_array(&array[low], n);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", n, size);
			print_array(&array[low], n);
		}
		mid = n / 2;
		bitonicsort(array, low, mid, 1, size);
		bitonicsort(array, low + mid, mid, 0, size);
		mergebitonic(array, low, n, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", n, size);
			print_array(&array[low], n);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", n, size);
			print_array(&array[low], n);
		}
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
