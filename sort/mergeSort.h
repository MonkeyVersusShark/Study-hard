#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

/**
 * Class	                    Sorting algorithm
 * Data structure	            Array
 * Worst case performance	    O(n log n)
 * Best case performance	    O(n log n) typical, O(n) natural variant
 * Average case performance	    O(n log n)
 * Worst case space complexity	О(n) total, O(n) auxiliary
 */

void merge(int *arr, int start, int mid, int finish) {
    int left = mid - start + 1;
    int right = finish - mid;

    int *left_arr = new int[left];
    int *right_arr = new int[right];

    for (int i = 0; i < left; i++)
        left_arr[i] = arr[start + i];
    for (int i = 0; i < right; i++)
        right_arr[i] = arr[mid + i + 1];

    int left_index = 0;
    int right_index = 0;
    int index = 0;

    for (index = start; index <= finish; index++) {
        if (left_index == left || right_index == right)
            break;

        if (left_arr[left_index] < right_arr[right_index]) {
            arr[index] = left_arr[left_index];
            ++left_index;
        } else {
            arr[index] = right_arr[right_index];
            ++right_index;
        }
    }

    for (int i = left_index; i < left; i++) {
        arr[index] = left_arr[i];
        ++index;
    }
    for (int i = right_index; i < right; i++) {
        arr[index] = right_arr[i];
        ++index;
    }

    delete[] left_arr;
    delete[] right_arr;
}

void mergeSort(int *arr, int start, int finish) {
    if (start < finish) {
        int mid = (finish + start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, finish);
        merge(arr, start, mid, finish);
    }
}

#endif
