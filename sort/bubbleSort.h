#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__

/**
 * Class	                    Sorting algorithm
 * Data structure	            Array
 * Worst case performance	    O(n^2)
 * Best case performance	    O(n)
 * Average case performance	    O(n^2)
 * Worst case space complexity  O(1), auxiliary
 */

void swap(int *n1, int *n2) {
    *n1 ^= *n2;
    *n2 ^= *n1;
    *n1 ^= *n2;
}

void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++)
        for (int j = len - 1; j > i; j--)
            if (arr[j] < arr[j - 1])
                swap(&arr[j], &arr[j - 1]);
}

#endif
