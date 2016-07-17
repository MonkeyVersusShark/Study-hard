#ifndef __HASH_CHAINING_H__
#define __HASH_CHAINING_H__

#include <vector>
#include <list>
#include <cmath>
using namespace std;

class hashTable {
private:
    struct element {
        int data;
        int key;

        element(int d = 0, int k = 0) : data(d), key(k) { }
    };

private:
    vector<list<element> > ele;
    static const int MAX = 701;
    int hashSize;

private:
    int hash(int key) {
        double constant = (sqrt(5) - 1) / 2;
        double num1 = static_cast<double>(key) * constant;
        double num2 = static_cast<double>(static_cast<int>(num1));
        return static_cast<int>(num1 - num2) % 701;
    }

public:
    hashTable() : ele(701), hashSize(0) { }

    void insert(int data, int key) {
        int hashKey = hash(key);
        ele[hashKey].push_back(element(data, key));
        ++hashSize;
    }

    bool erase(int key) {
        int hashKey = hash(key);
        for (auto iter = ele[hashKey].begin();
        iter != ele[hashKey].end(); ++iter)
            if (iter->key == key) {
                ele[hashKey].erase(iter);
                return true;
            }
        return false;
    }

    bool search(int key) {
        int hashKey = hash(key);
        for (auto iter = ele[hashKey].begin();
        iter != ele[hashKey].end(); ++iter)
            if (iter->key == key)
                return true;
        return false;
    }
};

#endif
