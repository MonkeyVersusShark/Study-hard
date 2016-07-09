#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include "global.h"

/**
 * Class	                     Sorting algorithm
 * Worst case performance	     O(n2)
 * Best case performance	     O(n log n) (simple partition) or O(n) (three-way partition and equal keys)
 * Average case performance	     O(n log n)
 * Worst case space complexity	 O(n) auxiliary (naive) O(log n) auxiliary (Sedgewick 1978)
 */

static int partition(int *arr, int start, int finish) {
    int key = arr[finish];
    int swap_candidate = start - 1;

    for (int i = start; i <= finish - 1; i++) {
        if (arr[i] <= key) {
            ++swap_candidate;
            swap(&arr[swap_candidate], &arr[i]);
        }
    }
    swap(&arr[swap_candidate + 1], &arr[finish]);
    return swap_candidate + 1;
}

void quicksort(int *arr, int start, int finish) {
    if (start < finish) {
        int partition_point = partition(arr, start, finish);
        quicksort(arr, start, partition_point - 1);
        quicksort(arr, partition_point + 1, finish);
    }
}

#endif
