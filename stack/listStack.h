#ifndef __LIST_STACK_H__
#define __LIST_STACK_H__

#include <cstddef>
using namespace std;

template <class T>
class listStack {
private:
    struct node {
        T data;
        node *next;
    };

private:
    node *top_node;
    int size;

public:
    listStack() {
        top_node = NULL;
        size = 0;
    }

    ~listStack() {
        while (!this->empty())
            this->pop();
    }

    bool empty() const {
        return size == 0;
    }

    void push(T x) {
        if (top_node == NULL) {
            top_node = new node;
            top_node->data = x;
            top_node->next = NULL;
        } else {
            node *temp = new node;
            temp->data = x;
            temp->next = top_node;
            top_node = temp;
        }
        ++size;
    }

    void pop() {
        if (!this->empty()) {
            node *temp = top_node;
            top_node = top_node->next;
            delete temp;
            --size;
        }
    }

    T top() const {
        if (this->empty())
            return T();
        return top_node->data;
    }
};

#endif
