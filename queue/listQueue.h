#ifndef __LIST_QUEUE_H__
#define __LIST_QUEUE_H__

#include <cstddef>

template<class T>
class listQueue {
private:
    struct node {
        T data;
        node *next;
    };

private:
    node *head;
    node *tail;

public:
    listQueue() {
        head = tail = NULL;
    }

    bool empty() const {
        return (head == NULL) && (tail == NULL);
    }

    void push(T x) {
        if (empty()) {
            node *temp = new node;
            temp->data = x;
            temp->next = NULL;
            head = tail = temp;
        } else if (head == tail) {
            node *temp = new node;
            temp->data = x;
            temp->next = NULL;
            head->next = temp;
            tail = temp;
        } else {
            node *temp = new node;
            temp->data = x;
            temp->next = NULL;
            tail->next = temp;
            tail = tail->next;
        }
    }

    void pop() {
        if (!empty()) {
            if (head == tail) {
                delete head;
                head = tail = NULL;
            } else {
                node *temp = head;
                head = head->next;
                delete temp;
            }
        }
    }

    T front() const {
        if (empty())
            return T();
        return head->data;
    }

    T back() const {
        if (empty())
            return T();
        return tail->data;
    }
};

#endif
