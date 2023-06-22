#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sort_merge_arr - sorts and merges the sub arrays in source
 * @start_id: starting index (inclusive) for left sub array
 * @middle_id: end index (exclusive) for left sub array and
 * starting index (inclusive) for the right sub array
 * @end_id: end index (exclusive) for the right sub array
 * @dest_d: destination for data
 * @source_d: source of data
 *
 * Return: void
 */
void sort_merge_arr(size_t start_id, size_t middle_id, size_t end_id,
		int *dest_d, int *source_d)
{
	size_t ai, bj, ck;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source_d + start_id, middle_id - start_id);
	printf("[right]: ");
	print_array(source_d + middle_id, end_id - middle_id);
	ai = start_id;
	bj = middle_id;
	for (ck = start_id; ck < end_id; ck++)
	{
		if (ai < middle_id && (bj >= end_id || source_d[ai] <= source_d[bj]))
		{
			dest_d[ck] = source_d[ai];
			ai++;
		}
		else
		{
			dest_d[ck] = source_d[bj];
			bj++;
		}
	}
	printf("[Done]: ");
	print_array(dest_d + start_id, end_id - start_id);
}

/**
 * split_merge_arr - recursively splits the array and merges the sorted arrays
 * @start_id: starting index (inclusive)
 * @end_id: end index (exclusive)
 * @arr: the array to sort
 * @cpy: a copy of the array
 *
 * Return: void
 */
void split_merge_arr(size_t start_id, size_t end_id, int *arr, int *cpy)
{
	size_t middle;

	if (end_id - start_id < 2)
		return;
	middle = (start_id + end_id) / 2;
	split_merge_arr(start_id, middle, arr, cpy);
	split_merge_arr(middle, end_id, arr, cpy);
	sort_merge_arr(start_id, middle, end_id, arr, cpy);
	for (middle = start_id; middle < end_id; middle++)
		cpy[middle] = arr[middle];
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t ai;
	int *cpy;

	if (array == NULL || size < 2)
		return;
	cpy = malloc(sizeof(int) * size);
	if (cpy == NULL)
		return;
	for (ai = 0; ai < size; ai++)
		cpy[ai] = array[ai];
	split_merge_arr(0, size, array, cpy);
	free(cpy);
}
