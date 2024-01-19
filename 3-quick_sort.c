#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: number of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

