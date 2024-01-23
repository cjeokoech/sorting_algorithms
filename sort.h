#ifndef SORT_HEADER_
#define SORT_HEADER_
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
listint_t *swap_node(listint_t *node, listint_t **list);
listint_t *swap_node(listint_t *node, listint_t **list);
void swap(int *array, int item1, int item2);
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size);
void qs(int *array, ssize_t first, ssize_t last, int size);
void *_calloc(unsigned int nmemb, unsigned int size);
void _mergesort(int *array, int *tmp, int start, int end);
void mymerge(int *a, int *tmp, int start, int mid, int end);
void *mycalloc(unsigned int mb, unsigned int size);
void maxHeapify(int *array, size_t size, int i, size_t n);
void heapswap(int *a, int *b);
void countingsort(int *array, size_t size, int exp, int *output);
int max(int *array, int size);
void bitonicsort(int array[], int low, int n, int order, int size);
void mergebitonic(int array[], int low, int n, int order);
void bitonicswap(int array[], int item1, int item2, int order);
/*void swap(int *array, ssize_t item1, ssize_t item2);
void sort_deck(deck_node_t **deck);*/

#endif
