#ifndef __HASH_CHAINING_H__
#define __HASH_CHAINING_H__

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 1024    // The max size of table.

/**
 * Information of contacts
 * Use name as key
 */
struct Info {
    string name;
    string tag;
    string phone_number;

    Info *next;
    Info *prev;

    Info(string s1 = "", string s2 = "", string s3 = "",
    Info *p1 = NULL, Info *p2 = NULL)
    : name(s1), tag(s2), phone_number(s3), next(p1), prev(p2) { }

    Info(const Info &x) : name(x.name), tag(x.tag),
    phone_number(x.phone_number), next(x.next), prev(x.prev) { }

    ~Info() {
        // Cascade deletion
        if (next != NULL)
            delete next;
    }

    friend ostream &operator<<(ostream &os, const Info &x) {
        os << "name:\t" << x.name << endl;
        os << "tag:\t" << x.tag << endl;
        os << "phone number:\t" << x.phone_number << endl;
        return os;
    }
};

class HashTable {
private:
    typedef Info *InfoPtr;
    typedef InfoPtr *Table;

private:
    Table table;
    int HashSize;

private:
    inline int pow(int n, int p) {
        int retVal = 1;
        while (p--)
            retVal *= n;
        return retVal;
    }

    int hash(string key) {
        int k = 0;
        int len = key.size();
        for (int i = 0; i < len; i++)
            k += key[i] * pow(2, len - i - 1);
        return k % MAX;
    }

public:
    HashTable() : HashSize(0) {
        table = new InfoPtr[MAX];
        for (int i = 0; i < MAX; i++)
            table[i] = new Info;
    }

    ~HashTable() {
        for (int i = 0; i < MAX; i++)
            delete table[i];
        delete[] table;
    }

    InfoPtr search(string key) {
        int h = hash(key);
        InfoPtr cur = table[h];
        cur = cur->next;

        while (cur != NULL) {
            if (cur->name == key) {
                InfoPtr retInfo = new Info(*cur);
                return retInfo;
            }
            cur = cur->next;
        }
        return NULL;
    }

    void HashInsert(const Info &x) {
        int h = hash(x.name);
        InfoPtr cur = table[h];

        while (cur->next != NULL)
            cur = cur->next;
        InfoPtr new_x = new Info(x);
        cur->next = new_x;
        new_x->prev = cur;
        new_x->next = NULL;
        ++HashSize;
    }

    bool HashDelete(const Info &x) {
        int h = hash(x.name);
        InfoPtr cur = table[h];
        cur = cur->next;

        while (cur != NULL) {
            if (cur->name == x.name) {
                if (cur->next == NULL) {
                    cur->prev->next = cur->next;
                    delete cur;
                } else {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    delete cur;
                }
                --HashSize;
                return true;
            }
        };
        return false;
    }
};

#endif
