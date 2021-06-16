#include "sort.h"

/**
 * print_left - print elements of left sublist in required format
 * @A: pointer to array containing the sublists
 * @iBegin: start index of sublist
 * @iEnd: end index of sublist
 *
 * Return: no return value (void)
 */
void print_left(int *A, int iBegin, int iEnd)
{
	int idx;

	for (idx = iBegin; idx < iEnd; idx++)
	{
		if (idx == iBegin)
		{
			if (iBegin == iEnd - 1)
				printf("[left]: %d\n", A[idx]);
			else
				printf("[left]: %d", A[idx]);
		}
		else if (idx == (iEnd - 1))
		{
			printf(", %d\n", A[idx]);
		}
		else if (idx > iBegin && idx < (iEnd - 1))
		{
			printf(", %d", A[idx]);
		}
	}
}

/**
 * print_right - print elements of left sublist in required format
 * @A: pointer to array containing the sublists
 * @iBegin: start index of sublist
 * @iEnd: end index of sublist
 *
 * Return: no return value (void)
 */
void print_right(int *A, int iBegin, int iEnd)
{
	int idx;

	for (idx = iBegin; idx < iEnd; idx++)
	{
		if (idx == iBegin)
		{
			if (iBegin == iEnd - 1)
				printf("[right]: %d\n", A[idx]);
			else
				printf("[right]: %d", A[idx]);
		}
		else if (idx == iEnd - 1)
		{
			printf(", %d\n", A[idx]);
		}
		else if (idx > iBegin && idx < (iEnd - 1))
		{
			printf(", %d", A[idx]);
		}
	}
}

/**
 * TopDownMerge - Merges two sorted sublists
 * @A: pointer to array to be sorted
 * @iBegin: index of beginning of sublist
 * @iMiddle: Boundary between teh two sublists to be sorted
 * @iEnd: index of end of second sorted sublist
 * @B: pointer to array to store result/sorted list
 *
 * Return: no return value (void)
 */
void TopDownMerge(int *A, int iBegin, int iMiddle, int iEnd, int *B)
{
/*
 * Left source half is A[ iBegin:iMiddle-1].
 * Right source half is A[iMiddle:iEnd-1   ].
 * Result is            B[ iBegin:iEnd-1   ].
*/
	int i = iBegin, j = iMiddle, k;

	printf("Merging...\n");
	print_left(A, iBegin, iMiddle);
	print_right(A, iMiddle, iEnd);
/*
 * While there are elements in the left or right runs...
*/
	for (k = iBegin; k < iEnd; k++)
	{
/*
 * If left run head exists and is <= existing right run head.
*/
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i = i + 1;
		}
		else
		{
			B[k] = A[j];
			j = j + 1;
		}
	}
}

/**
 * TopDownSplitMerge - split an array into two sublists to be sorted
 * @B: array to hold result/sorted list
 * @iBegin: start index of sublist to be split
 * @iEnd: end index of sublist to be split
 * @A: array to be split
 *
 * Return: no return value (void)
 */
void TopDownSplitMerge(int *B, int iBegin, int iEnd, int *A)
{
/*
 * Split A[] into 2 runs, sort both runs into B[],
 * merge both runs from B[] to A[]
 * iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
*/
	int iMiddle, idx;

	if (iEnd - iBegin <= 1)
		return;
/*
 *	split the run longer than 1 item into halves
*/
	iMiddle = (iEnd + iBegin) / 2;
/*
 * recursively sort both runs from array A[] into B[]
*/
	TopDownSplitMerge(A, iBegin,  iMiddle, B);
	TopDownSplitMerge(A, iMiddle,    iEnd, B);
/*
 * merge the resulting runs from array B[]
*/
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
	for (idx = iBegin; idx < iEnd; idx++)
	{
		if (idx == iBegin)
			printf("[Done]: %d,", A[idx]);
		else if (idx == iEnd - 1)
			printf(" %d\n", A[idx]);
		else
			printf(" %d,", A[idx]);
	}
}

/**
 * merge_sort - sort an array of integers in ascending order
 * @array: pointer to array to be sorted
 * @size: size of the array
 *
 * Return: No return value (void)
 */
void merge_sort(int *array, size_t size)
{
	int *A = array, *B = NULL, n = size, k;

	if (size < 2)
		return;

	B = malloc(sizeof(int) * size);
	if (B == NULL)
		return;
	for (k = 0; k < n; k++)
		B[k] = A[k];
	TopDownSplitMerge(B, 0, n, A);
	free(B);
}
