#include "sort.h"

/*
Left source half is A[ iBegin:iMiddle-1].
Right source half is A[iMiddle:iEnd-1   ].
Result is            B[ iBegin:iEnd-1   ].
*/
void TopDownMerge(int *A, int iBegin, int iMiddle, int iEnd, int *B)
{
	int i = iBegin, j = iMiddle, k, idx;

	printf("Merging...\n");
	for (idx = iBegin; idx < iMiddle; idx++)
	{
		if (idx == iBegin)
		{
			if (iBegin == iMiddle - 1)
				printf("[left]: %d\n", A[idx]);
			else
				printf("[left]: %d", A[idx]);
		}
		else if (idx == (iMiddle - 1))
		{
			printf(", %d\n", A[idx]);
		}
		else if (idx > iBegin && idx < (iMiddle - 1))
		{
			printf(", %d", A[idx]);
		}
	}
	for (idx = iMiddle; idx < iEnd; idx++)
	{
		if (idx == iMiddle)
		{
			if (iMiddle == iEnd - 1)
				printf("[right]: %d\n", A[idx]);
			else
				printf("[right]: %d", A[idx]);
		}
		else if (idx == iEnd - 1)
		{
			printf(", %d\n", A[idx]);
		}
		else if (idx > iMiddle && idx < (iEnd - 1))
		{
			printf(", %d", A[idx]);
		}
	}
/*
While there are elements in the left or right runs...
*/
	for (k = iBegin; k < iEnd; k++)
	{
/*
If left run head exists and is <= existing right run head.
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
/*
	for (idx = iBegin; idx < iEnd; idx++)
	{
		if (idx == iBegin)
			printf("[Done]: %d,", A[idx]);
		else if (idx == iEnd - 1)
			printf(" %d\n", A[idx]);
		else
			printf(" %d,", A[idx]);
	}
*/
}

/*
Split A[] into 2 runs, sort both runs into B[], merge both runs from B[] to A[]
iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
*/
void TopDownSplitMerge(int *B, int iBegin, int iEnd, int *A)
{
	int iMiddle, idx;

	if(iEnd - iBegin <= 1)
		return;
/*
	split the run longer than 1 item into halves
*/
	iMiddle = (iEnd + iBegin) / 2;
/*
recursively sort both runs from array A[] into B[]
*/
	TopDownSplitMerge(A, iBegin,  iMiddle, B);
	TopDownSplitMerge(A, iMiddle,    iEnd, B);
/*
merge the resulting runs from array B[]
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

void CopyArray(int *A, int iBegin, int iEnd, int *B)
{
	int k;

	for(k = iBegin; k < iEnd; k++)
		B[k] = A[k];
}

void merge_sort(int *array, size_t size)
{
	int *A = array, *B = NULL, n = size;

	B = malloc(sizeof(int) * size);
	if (B == NULL)
		return;
	CopyArray(A, 0, n, B);
	TopDownSplitMerge(B, 0, n, A);
	free(B);
}
