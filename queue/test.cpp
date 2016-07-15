#include "arrayQueue.h"
#include "listQueue.h"
#include <iostream>
using namespace std;

int main() {
    arrayQueue<int> arrQue;
    listQueue<int> liQue;

    for (int i = 0; i < 11; i++) {
        arrQue.push(i + 1);
        liQue.push(i + 1);
    }

    while (!arrQue.empty()) {
        cout << arrQue.front() << " " << arrQue.back() << " ";
        arrQue.pop();
    }
    cout << endl;

    while (!liQue.empty()) {
        cout << liQue.front() << " " << liQue.back() << " ";
        liQue.pop();
    }
    cout << endl;

    return 0;
}
