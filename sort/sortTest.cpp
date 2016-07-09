/**
 * Test for correctness and time consuming.
 */

#include "insertionSort.h"
#include "mergeSort.h"
#include "bubbleSort.h"
#include "heapsort.h"
#include "quicksort.h"
#include "selectionSort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MILLION = 1000000;

class test {
private:
    int *arr;
    int len;

    typedef void (*fun1)(int *, int);
    typedef void (*fun2)(int *, int, int);

public:
    test() {
        arr = NULL;
        len = 0;
    }

    explicit test(int n) {
        arr = new int[n];
        len = n;
        for (int i = 0; i < len; i++)
            arr[i] = rand();
    }

    ~test() {
        delete[] arr;
    }

    void calculateTime(fun1 f) const {
        int *tmp = new int[len];
        for (int i = 0; i < len; i++)
            tmp[i] = arr[i];

        clock_t start = clock();
        f(tmp, len);
        clock_t finish = clock();
        cout << static_cast<double>(finish - start) / CLOCKS_PER_SEC
             << endl;

        delete[] tmp;
    }

    void calculateTime(fun2 f) const {
        int *tmp = new int[len];
        for (int i = 0; i < len; i++)
            tmp[i] = arr[i];

        clock_t start = clock();
        f(tmp, 0, len - 1);
        clock_t finish = clock();
        cout << static_cast<double>(finish - start) / CLOCKS_PER_SEC
             << endl;

        delete[] tmp;
    }

    static void sortTest(fun1 f) {
        int *tmp = new int[10];
        for (int i = 0; i < 10; i++)
            tmp[i] = rand() % 10;

        f(tmp, 10);

        for (int i = 0; i < 10; i++)
            cout << tmp[i] << ' ';
        cout << endl;

        delete[] tmp;
    }

    static void sortTest(fun2 f) {
        int *tmp = new int[10];
        for (int i = 0; i < 10; i++)
            tmp[i] = rand() % 10;

        f(tmp, 0, 10 - 1);

        for (int i = 0; i < 10; i++)
            cout << tmp[i] << ' ';
        cout << endl;

        delete[] tmp;
    }
};

int main() {
    test instance(MILLION);

    cout << "Test1: Correctness\n";
    test::sortTest(insertionSort);
    test::sortTest(mergeSort);
    test::sortTest(bubbleSort);
    test::sortTest(heapsort);
    test::sortTest(quicksort);
    test::sortTest(selectionSort);

    cout << endl;

    cout << "Test2: Time consuming by 1 million data\n";
    cout << "Insertion sort: ";
    instance.calculateTime(insertionSort);
    cout << "Merge sort: ";
    instance.calculateTime(mergeSort);
    cout << "Bubble sort: ";
    instance.calculateTime(bubbleSort);
    cout << "Heapsort: ";
    instance.calculateTime(heapsort);
    cout << "Quicksort: ";
    instance.calculateTime(quicksort);
    cout << "Selection sort: ";
    instance.calculateTime(selectionSort);

    /**
     * Result:
     * Test1: Correctness
     * 0 1 1 3 3 3 4 5 6 9
     * 0 1 1 2 2 3 3 5 5 8
     * 1 3 4 5 5 6 7 7 8 8
     * 0 2 3 3 4 5 6 8 9 9
     * 0 0 1 2 2 4 5 5 6 9
     * 3 3 4 4 5 7 7 8 9 9
     *
     * Test2: Time consuming by 1 million data
     * Insertion sort: 736.582
     * Merge sort: 0.303206
     * Bubble sort: 3858.25
     * Heapsort: 0.512206
     * Quicksort: 0.195093
     * Selection sort: 1327.9
     */

    return 0;
}
