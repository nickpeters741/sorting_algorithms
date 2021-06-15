#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order using Bubble sort
 *
 * Return: no return value (void)
 */
void bubble_sort(int *array, size_t size)
{
	int temp = 0, swapped = 0;
	size_t count = 0;

	while (1)
	{
		swapped = 0;

		for (count = 0; count < size - 1; count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}
}
