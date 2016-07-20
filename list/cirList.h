#ifndef __CIR_LIST_H__
#define __CIR_LIST_H__

#include <cstddef>
#include <iostream>
using namespace std;

class cirList {
private:
    typedef int data_type;
    struct node {
     public:
      data_type data;
      node* next;
      node* prev;
      node(data_type data = 0, node* next = NULL, node* prev = NULL)
          : data(data), next(next), prev(prev){};
    };
    typedef node listNode;
    typedef node* listPointer;
    typedef unsigned int size_type;

private:
    listPointer head;
    int _size;

private:
    inline listPointer at(int index) {
        if (index >= 0 && index < _size) {
            if (index <= _size / 2) {
                int count = 0;
                listPointer p = head->next;
                while (count != index) {
                    ++count;
                    p = p->next;
                }
                return p;
            } else {
                int count = 0;
                listPointer p = head->prev;
                while (count != _size - 1 - index) {
                    ++count;
                    p = p->prev;
                }
                return p;
            }
        }
        return NULL;
    }

public:
    cirList() : _size(0) {
        head = new listNode;
        head->next = head;
        head->prev = head;
    }

    ~cirList() {
        this->clear();
        delete head;
    }

    void push_front(const data_type &data) {
        listPointer new_node = new listNode(data);
        new_node->next = head->next;
        head->next->prev = new_node;
        head->next = new_node;
        new_node->prev = head;
        ++_size;
    }

    void push_back(const data_type &data) {
        listPointer new_node = new listNode(data);
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
        new_node->next = head;
        ++_size;
    }

    void pop_front() {
        listPointer temp = head->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        --_size;
    }

    void pop_back() {
        listPointer temp = head->prev;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        --_size;
    }

    void insert(int position, const data_type &data) {
        listPointer new_node = new listNode(data);
        listPointer temp1 = this->at(position - 1);
        listPointer temp2 = temp1->next;
        temp1->next = new_node;
        new_node->prev = temp1;
        new_node->next = temp2;
        temp2->prev = new_node;
        ++_size;
    }

    void erase(int position) {
        listPointer temp = this->at(position);
        listPointer temp1 = temp->prev;
        listPointer temp2 = temp->next;
        temp1->next = temp2;
        temp2->prev = temp1;
        --_size;
    }

    void clear() {
        listPointer p = head->next;
        while (p != head) {
            listPointer q = p;
            p = p->next;
            delete q;
        }
        _size = 0;
    }

    void sort() {
        if (head->next != head && head->next->next != head) {
            node *slow = head->next;
            node *fast = slow->next;
            while (fast != head) {
                if (fast->data >= slow->data) {
                    fast = fast->next;
                    slow = slow->next;
                } else {
                    node *pre = head->next;
                    if (head->next->data > fast->data) {
                        slow->next = fast->next;
                        fast->next->prev = slow;
                        fast->next = head->next;
                        head->next->prev = fast;
                        head->next = fast;
                        fast->prev = head;
                    } else {
                        while (pre->next->data <= fast->data)
                            pre = pre->next;
                        slow->next = fast->next;
                        fast->next->prev = slow;
                        fast->next = pre->next;
                        pre->next->prev = fast;
                        pre->next = fast;
                        fast->prev = pre;
                    }
                    fast = slow->next;
                }
            }
        }
    }

    /*
    friend ostream &operator<<(ostream &os, const cirList &x) {
        listPointer p = x.head->next;
        while (p != x.head) {
            os << p->data << " ";
            p = p->next;
        }
        return os;
    }
     */
};

#endif
