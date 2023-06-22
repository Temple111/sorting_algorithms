#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t ai, bj, space = 1;
	int insert;

	if (array == NULL || size < 2)
		return;

	while (space < size / 3)
		space = space * 3 + 1;

	while (space > 0)
	{
		for (ai = space; ai < size; ai++)
		{
			insert = array[ai];
			for (bj = ai; bj >= space && array[bj - space] > insert; bj = bj - space)
				array[bj] = array[bj - space];
			array[bj] = insert;
		}
		space = (space - 1) / 3;
		print_array(array, size);
	}
}
