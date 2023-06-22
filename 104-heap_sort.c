#include "sort.h"

void int_arr_swap(int *x, int *y);
void bintree_to_binheap(int *arr, size_t sz, size_t base_id, size_t root_nd);
void heap_sort(int *array, size_t size);

/**
 * int_arr_swap - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void int_arr_swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bintree_to_binheap - Turn a binary tree into a complete binary heap.
 * @arr: An array of integers representing a binary tree.
 * @sz: The size of the array/tree.
 * @base_id: The index of the base row of the tree.
 * @root_nd: The root node of the binary tree.
 */
void bintree_to_binheap(int *arr, size_t sz, size_t base_id, size_t root_nd)
{
	size_t left, right, large;

	left = 2 * root_nd + 1;
	right = 2 * root_nd + 2;
	large = root_nd;

	if (left < base_id && arr[left] > arr[large])
		large = left;
	if (right < base_id && arr[right] > arr[large])
		large = right;

	if (large != root_nd)
	{
		int_arr_swap(arr + root_nd, arr + large);
		print_array(arr, sz);
		bintree_to_binheap(arr, sz, base_id, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int ai;

	if (array == NULL || size < 2)
		return;

	for (ai = (size / 2) - 1; ai >= 0; ai--)
		bintree_to_binheap(array, size, size, ai);

	for (ai = size - 1; ai > 0; ai--)
	{
		int_arr_swap(array, array + ai);
		print_array(array, size);
		bintree_to_binheap(array, size, ai, 0);
	}
}
