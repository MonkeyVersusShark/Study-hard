#ifndef __MAX_MINI_H__
#define __MAX_MINI_H__

#include <utility>
using namespace std;

pair<int, int> find_max_mini(int *arr, int len) {
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    return pair<int, int>(min, max);
}

#endif
