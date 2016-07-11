#ifndef __WEEK_01_1000_H__
#define __WEEK_01_1000_H__

#include <iostream>
using namespace std;

class MyArray {
private:
    int contents[100];
    int size;

public:
    MyArray() {
        for (int i = 0; i < 100; i++)
            contents[i] = 0;
        size = 0;
    }

    void insert(int position, int content) {
        if (position > size) {
            ++size;
            contents[size - 1] = content;
        } else {
            ++size;
            for (int i = size - 1; i > position; i--)
                contents[i] = contents[i - 1];
            contents[position] = content;
        }
    }

    void deleteByPosition(int position) {
        if (position < size) {
            --size;
            for (int i = position; i < size; i++)
                contents[i] = contents[i + 1];
        }
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << contents[i] << '\t';
        cout << endl;
    }
};

#endif
