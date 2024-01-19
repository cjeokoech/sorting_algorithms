#include "sort.h"
/**
 * bubble_sort - use bubble sort to sor integers in ascending order
 * @array: the array to be printed
 * @size: number of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
		{
			break;
		}
	}
}
