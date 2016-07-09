#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__

#include "global.h"

/**
 * Class	                        Sorting algorithm
 * Data structure	                Array
 * Worst case performance	        О(n2)
 * Best case performance	        О(n2)
 * Average case performance	        О(n2)
 * Worst case space complexity 	    О(n) total, O(1) auxiliary
 */

void selectionSort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int miniIndex = i;
        for (int j = i + 1; j < len; j++)
            if (arr[j] < arr[miniIndex])
                miniIndex = j;

        if (miniIndex != i)
            swap(&arr[miniIndex], &arr[i]);
    }
}

#endif
