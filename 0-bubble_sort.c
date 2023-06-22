#include "sort.h"

/**
 * bubble_sort - a function to sort an array
 * @array: integer array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t ai, bj;
	int cp;

	for (ai = 0; ai < size; ai++)
		for (bj = 0; bj < size - 1; bj++)
			if (array[bj] > array[bj + 1])
			{
				cp = array[bj];
				array[bj] = array[bj + 1];
				array[bj + 1] = cp;
				print_array(array, size);
			}
}
