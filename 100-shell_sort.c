#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Knuth seq
 * @array: pointer to array of integers
 * @size: size of the array
 *
 * Return: no return value (void)
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, temp, i;
	int j;

	if (size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j > 0 && array[j] < array[j - gap]; j -= gap)
			{
				temp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = temp;
			}
		}
		gap = gap / 3;
		print_array(array, size);
	}
}
