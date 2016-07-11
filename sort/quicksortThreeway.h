#ifndef __QUICKSORT_THREE_WAY_H__
#define __QUICKSORT_THREE_WAY_H__

#include "global.h"
#include "insertionSort.h"

#define LIM 10

static void sort_aux(int *arr, int start, int finish) {
    if (finish - start <= LIM) return;

    int i = start - 1;
    int j = finish;
    int p = start;
    int q = finish;

    int pivot = arr[finish];

    while(true) {
        while (arr[++i] < pivot);
        while (pivot < arr[--j])
            if (j == start)
                break;

        if (j <= i)
            break;

        swap(&arr[i], &arr[j]);

        if (arr[i] == pivot) {
            swap(&arr[i], &arr[p]);
            ++p;
        }
        if (arr[j] == pivot) {
            swap(&arr[j], &arr[q]);
            --q;
        }
    }

    swap(&arr[i], &arr[finish]);

    j = i + 1;
    i = i - 1;
    for(int k = start; k < p; k++, i--)
		swap(&arr[k], &arr[i]);
	for(int k = finish; k > q; k--, j++)
		swap(&arr[k], &arr[j]);

    sort_aux(arr, start, i);
    sort_aux(arr, j, finish);
}

void quicksort_three_way(int *arr, int start, int finish) {
    if (start < finish) {
        sort_aux(arr, start, finish);
        insertionSort(arr, finish - start + 1);
    }
}

#endif
