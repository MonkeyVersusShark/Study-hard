#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__

#include "global.h"

/**
 * Class	                    Sorting algorithm
 * Data structure	            Array
 * Worst case performance	    O(n^2)
 * Best case performance	    O(n)
 * Average case performance	    O(n^2)
 * Worst case space complexity  O(1), auxiliary
 */

void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++)
        for (int j = len - 1; j > i; j--)
            if (arr[j] < arr[j - 1])
                swap(&arr[j], &arr[j - 1]);
}

#endif
