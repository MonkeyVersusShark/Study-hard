#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include "global.h"
#include <cstdlib>
using namespace std;

/**
 * Class	                     Sorting algorithm
 * Worst case performance	     O(n2)
 * Best case performance	     O(n log n) (simple partition) or O(n) (three-way partition and equal keys)
 * Average case performance	     O(n log n)
 * Worst case space complexity	 O(n) auxiliary (naive) O(log n) auxiliary (Sedgewick 1978)
 */

static int partition(int *arr, int start, int finish) {
    int pivot = arr[finish];
    int swap_candidate = start - 1;

    for (int i = start; i <= finish - 1; i++) {
        if (arr[i] <= pivot) {
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

static int random(int start, int finish) {
    int retNum = rand() % (finish + 1);
    while (retNum < start)
        retNum = rand() % (finish + 1);
    return retNum;
}

static int three_way_partition(int *arr, int start, int finish) {
    int i = random(start, finish);
    int j = random(start, finish);
    int k = random(start, finish);

    int pivot_pos = 0;
    if (arr[j] <= arr[i] && arr[i] >= arr[k])
        pivot_pos = i;
    else if (arr[i] <= arr[j] && arr[j] >= arr[k])
        pivot_pos = j;
    else
        pivot_pos = k;

    swap(&arr[pivot_pos], &arr[finish]);
    return partition(arr, start, finish);
}

void three_way_partition_quicksort(int *arr, int start, int finish) {
    if (start < finish) {
        int partition_point = three_way_partition(arr, start, finish);
        quicksort(arr, start, partition_point - 1);
        quicksort(arr, partition_point + 1, finish);
    }
}

#endif
