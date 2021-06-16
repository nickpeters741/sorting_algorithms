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

	while (gap < size)
		gap = gap * 3 + 1;
	gap /= 3;

	while (1)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i - gap; j >= 0; j = j - gap)
			{
				if (array[j+gap] >= array[j])
				{
					break;
				}
				else
				{
					temp = array[j];
					array[j] = array[j + gap];
					array[j + gap] = temp;
				}
			}
		}
		gap = gap / 3;
		print_array(array, size);
		if (gap < 1)
			break;
	}

}
