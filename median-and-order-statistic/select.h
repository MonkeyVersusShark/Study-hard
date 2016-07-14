#ifndef __SELECT_H__
#define __SELECT_H__

#include <cstdlib>
using namespace std;

static void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
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

static void cmp_swap(int *n1, int *n2) {
    if (*n1 > *n2)
        swap(n1, n2);
}

static int randomized_partition(int *arr, int start, int finish) {
    int mid = (start + finish) / 2;

    cmp_swap(&arr[start], &arr[mid]);
    cmp_swap(&arr[mid], &arr[finish]);
    cmp_swap(&arr[start], &arr[finish]);
    swap(&arr[mid], &arr[finish]);

    return partition(arr, start, finish);
}

int randomized_select(int *arr, int start, int finish, int i) {
    if (start == finish)
        return arr[start];

    int partition_point = randomized_partition(arr, start, finish);
    int k = partition_point - start + 1;

    if (i == k)
        return arr[partition_point];
    else if (i < k)
        return randomized_select(arr, start, partition_point - 1, i);
    else
        return randomized_select(arr, partition_point + 1, finish, i - k);
}

#endif
