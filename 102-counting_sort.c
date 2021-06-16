#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * @array: pointer to integer array
 * @size: size of the array
 *
 * Return: no return value (void)
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *count, *output, k, j; /* t = 0;*/

	if (size < 2)
		return;

/*
 * Find the largest element in the array
 */
	k = 0;
	for (i = 0; i < size; i++)
	{
		if (k < array[i])
			k = array[i];
	}

	count = malloc(sizeof(int) * (k + 1));
	output = malloc(sizeof(int) * size);
	if (count == NULL || output == NULL)
		return;
	for (j = 0; j <= k; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j <= k; j++)
		count[j] += count[j - 1];

	print_array(count, k + 1);

	for (j = size - 1; j >= 0; j--)
	{
		output[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
