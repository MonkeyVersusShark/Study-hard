#ifndef __RADIX_SORT_H__
#define __RADIX_SORT_H__

void radix_counting_sort(int *arr, int *corres, int len) {
    int *tmp = new int[len];
    for (int i = 0; i < len; i++)
        tmp[i] = 0;

    int *cnt = new int[10];
    for (int i = 0; i <= 9; i++)
        cnt[i] = 0;

    for (int i = 0; i < len; i++)
        ++cnt[corres[i]];
    for (int i = 1; i <= 9; i++)
        cnt[i] += cnt[i - 1];

    for (int i = len - 1; i >= 0; i--) {
        tmp[cnt[corres[i]] - 1] = arr[i];
        --cnt[corres[i]];
    }

    for (int i = 0; i < len; i++)
        arr[i] = tmp[i];

    delete[] tmp;
    delete[] cnt;
}

void radixSort(int *arr, int len, int d) {
    int *tmp = new int[len];
    for (int i = 0; i < len; i++)
        tmp[i] = arr[i];

    for (int i = 0; i < d; i++) {
        int *digit = new int[len];

        for (int j = 0; j < len; j++)
            digit[j] = tmp[j] % 10;

        radix_counting_sort(arr, digit, len);

        for (int j = 0; j < len; j++)
            tmp[j] = arr[j] / (10 * (i + 1));

        delete[] digit;
    }

    delete[] tmp;
}

#endif
