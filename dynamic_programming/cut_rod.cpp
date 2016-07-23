#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int p[10] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };

// Use recursion directly
// low effecifiency
int cut_rod(int *p, int n) {
    if (n == 0)
        return 0;
    int q = -1;
    for (int i = 0; i < n; i++)
        q = max(q, p[i] + cut_rod(p, n - 1 - i));
    return q;
}

// Top-down with memoization
// O(n^2)
int memoized_cut_rod_aux(int *p, int n, int *r) {
    if (r[n] >= 0)
        return r[n];
    int q;
    if (n == 0) {
        q = 0;
    } else {
        q = -1;
        for (int i = 0; i < n; i++)
            q = max(q, p[i] + memoized_cut_rod_aux(p, n - 1 - i, r));
    }
    r[n] = q;
    return q;
}

int memoized_cut_rod(int *p, int n) {
    int *r = new int[n + 1];
    for (int i = 0; i <= n; i++)
        r[i] = -1;
    int result = memoized_cut_rod_aux(p, n, r);
    delete[] r;
    return result;
}

// bottom-up method
// O(n^2)
int bottom_up_cut_rod(int *p, int n) {
    int *r = new int[n + 1];
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        int q = -1;
        for (int i = 0; i < j; i++)
            q = max(q, p[i] + r[j - 1 - i]);
        r[j] = q;
    }
    int result = r[n];
    delete[] r;
    return result;
}

// Extended bottom up
// Get the solution
int *extended_bottom_up_cut_rod(int *p, int n) {
    int *r = new int[n + 1];
    int *s = new int[n + 1];
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        int q = -1;
        for (int i = 0; i < j; i++) {
            if (q < p[i] + r[j - 1 - i]) {
                q = p[i] + r[j - 1 - i];
                s[j] = i + 1;
            }
        r[j] = q;
        }
    }
    return s;
}

void print_cut_rod_solution(int *p, int n) {
    int *result = extended_bottom_up_cut_rod(p, n);
    while (n > 0) {
        cout << result[n] << " ";
        n = n - result[n];
    }
    cout << endl;
    delete[] result;
}

int main() {
    for (int i = 1; i <= 10; i++) {
        cout << "TEST 1\t" << cut_rod(p, i) << endl;
        cout << "TEST 2\t" << memoized_cut_rod(p, i) << endl;
        cout << "TEST 3\t" << bottom_up_cut_rod(p, i) << endl;
    }
    for (int i = 1; i <= 10; i++)
        print_cut_rod_solution(p, i);
    return 0;
}
