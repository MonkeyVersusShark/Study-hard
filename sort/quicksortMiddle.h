#ifndef __QUICKSORT_MIDDLE_H__
#define __QUICKSORT_MIDDLE_H__

#include "global.h"
#include "insertionSort.h"

#define LIM 10

static inline void cmp_swap(int *n1, int *n2) {
    if (*n1 > *n2)
        swap(n1, n2);
}

static int partition(int *arr, int start, int finish) {
    int pivot = arr[finish];
    int swap_candidate = start - 1;

    for (int i = start; i <= finish - 1; i++) {
        if (arr[i] < pivot) {
            ++swap_candidate;
            swap(&arr[swap_candidate], &arr[i]);
        }
    }
    swap(&arr[swap_candidate + 1], &arr[finish]);
    return swap_candidate + 1;
}

static void sort_aux(int *arr, int start, int finish) {
    if (finish - start <= LIM) return;

    int mid = (start + finish) / 2;
    swap(&arr[mid], &arr[finish - 1]);

    cmp_swap(&arr[start], &arr[finish - 1]);
    cmp_swap(&arr[start], &arr[finish]);
    cmp_swap(&arr[finish - 1], &arr[finish]);

    // arr[start] < arr[finish - 1] < arr[finish]
    int partition_point = partition(arr, start + 1, finish - 1);
    sort_aux(arr, start, partition_point - 1);
    sort_aux(arr, partition_point + 1, finish);
}

void quicksort_middle(int *arr, int start, int finish) {
    if (start < finish) {
        sort_aux(arr, start, finish);
        insertionSort(arr, finish - start + 1);
    }
}

#endif
