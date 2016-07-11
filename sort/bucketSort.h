#ifndef __BUCKET_SORT_H__
#define __BUCKET_SORT_H__

#include <list>
#include <vector>
using namespace std;

void bucketSort(double *arr, int len) {
    // 0 < arr[i] < 1

    vector<list<double> > buckets(len);

    for (int i = 0; i < len; i++)
        buckets[len * arr[i]].push_back(arr[i]);
    for (int i = 0; i < len; i++)
        buckets[i].sort();

    int index = 0;
    for (int i = 0; i < len; i++) {
        while (!buckets[i].empty()) {
            arr[index++] = buckets[i].front();
            buckets[i].pop_front();
        }
    }
}

#endif
