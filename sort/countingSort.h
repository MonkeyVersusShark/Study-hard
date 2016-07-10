#ifndef __COUNTING_SORT_H__
#define __COUNTING_SORT_H__

void countingSort(int *arr, int len, int k) {
    int *tmp = new int[len];
    for (int i = 0; i < len; i++)
        tmp[i] = 0;

    int *cnt = new int[k + 1];
    for (int i = 0; i <= k; i++)
        cnt[i] = 0;

    for (int i = 0; i < len; i++)
        ++cnt[arr[i]];
    for (int i = 1; i <= k; i++)
        cnt[i] += cnt[i - 1];

    for (int i = len - 1; i >= 0; i--) {
        tmp[cnt[arr[i]] - 1] = arr[i];
        --cnt[arr[i]];
    }

    for (int i = 0; i < len; i++)
        arr[i] = tmp[i];

    delete[] tmp;
    delete[] cnt;
}

void countingSort(int *arrA, int *arrB, int len, int k) {
    int *cnt = new int[k + 1];
    for (int i = 0; i <= k; i++)
        cnt[i] = 0;

    for (int i = 0; i < len; i++)
        ++cnt[arrA[i]];
    for (int i = 1; i <= k; i++)
        cnt[i] += cnt[i - 1];

    for (int i = len - 1; i >= 0; i--) {
        arrB[cnt[arrA[i]] - 1] = arrA[i];
        --cnt[arrA[i]];
    }

    delete[] cnt;
}

#endif
