#include <stdio.h>
#include "sort.h"

/**
 * swap - Function that swaps two values
 *
 * @x: Fisrt value
 * @y: Second value
 * Return: 0
 */
void swap(int *x, int *y)
{
	int cp;

	cp = *y;
	*y = *x;
	*x = cp;
}
