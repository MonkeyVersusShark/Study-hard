#include "arrayStack.h"
#include "listStack.h"
#include <iostream>
using namespace std;

int main() {
    arrayStack<int> arrSt;
    listStack<int> liSt;

    for (int i = 0; i < 11; i++) {
        arrSt.push(i + 1);
        liSt.push(i + 1);
    }

    while (!arrSt.empty()) {
        cout << arrSt.top() << " ";
        arrSt.pop();
    }
    cout << endl;

    while (!liSt.empty()) {
        cout << liSt.top() << " ";
        liSt.pop();
    }
    cout << endl;

    return 0;
}
