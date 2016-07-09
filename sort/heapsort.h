#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

/**
 * Class	                     Sorting algorithm
 * Data structure	             Array
 * Worst case performance	     O(n log n)
 * Best case performance	     Ω(n), O(n log n)
 * Average case performance	     O(n log n)
 * Worst case space complexity	 O(1) auxiliary
 */

void swap(int *n1, int *n2) {
    *n1 ^= *n2;
    *n2 ^= *n1;
    *n1 ^= *n2;
 }

static int left(int i) {
    return i << 1;
    // return i * 2;
}

static int right(int i) {
    return (i << 1) + 1;
    // return i * 2 + 1;
}

static void max_heapify(int *arr, int heap_size, int i) {
    int l = left(i);
    int r = right(i);
    int largest = 0;

    if (l < heap_size && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if (r < heap_size && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, heap_size, largest);
    }
}

static void build_max_heap(int *arr, int len) {
    int heap_size = len;
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, heap_size, i);
}

void heapsort(int *arr, int len) {
    int heap_size = len;
    build_max_heap(arr, heap_size);
    for (int i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        --heap_size;
        max_heapify(arr, heap_size, 0);
    }
}

#endif
