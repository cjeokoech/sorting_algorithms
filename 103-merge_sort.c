#include "sort.h"
#include <stdio.h>
/**
 *mycalloc - this is a calloc function
 *@mb: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
void *mycalloc(unsigned int mb, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (mb == 0 || size == 0)
		return (NULL);
	p = malloc(mb * size);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < (mb * size); i++)
		p[i] = 0;
	return (p);
}
/**
 *mymerge - make a merge
 *@a: one from start to mid
 *@tmp: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: first element position
 *@mid: array middle
 *@end: last element position
 **/
void mymerge(int *a, int *tmp, int start, int mid, int end)
{
	int size_left = mid - start + 1, size_right = end - mid;
	int *left, *right;
	int l, r, i = 0;

	left = &tmp[0];
	right = &tmp[size_right];
	for (l = 0; l < size_left; l++)
		left[l] = a[start + l];
	for (r = 0; r < size_right; r++)
		right[r] = a[mid + 1 + r];
	l = 0, r = 0, i = start;
	while (l < size_left && r < size_right)
	{
		if (left[l] <= right[r])
			a[i] = left[l], l++;
		else
			a[i] = right[r], r++;
		i++;
	}
	while (l < size_left)
		a[i] = left[l], l++, i++;
	while (r < size_right)
		a[i] = right[r], r++, i++;
	printf("Merging...\n");
	printf("[l]: ");
	print_array(left, l);
	printf("[r]: ");
	print_array(right, r);
	printf("[Done]: ");
	print_array(&a[start], l + r);
}
/**
 *_mergesort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@array: array of integers
 *@tmp: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: fisrt element position
 *@end: last element position
 *Return: void
 */
void _mergesort(int *array, int *tmp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		_mergesort(array, tmp, start, mid);
		_mergesort(array, tmp, mid + 1, end);
		mymerge(array, tmp, start, mid, end);
	}
}
/**
 *merge_sort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@size: size of the list
 *@array: array of integers
 *Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;
	tmp = mycalloc(size, sizeof(int));
	_mergesort(array, tmp, 0, size - 1);
	free(tmp);
}
