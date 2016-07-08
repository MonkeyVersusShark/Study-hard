#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

/**
 * Class                        Sorting algorithm
 * Data structure	            Array
 * Worst case performance	    О(n^2) comparisons, swaps
 * Best case performance	    O(n) comparisons, O(1) swaps
 * Average case performance	    О(n^2) comparisons, swaps
 * Worst case space complexity	О(n) total, O(1) auxiliary
 */

void insertionSort(int *arr, int len) {
    for (int j = 1; j < len; j++) {
        int key = arr[j];
        int i = j - 1;

        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            --i;
        }

        arr[i + 1] = key;
    }
}

#endif
