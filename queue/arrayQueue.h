#ifndef __ARRAY_QUEUE_H__
#define __ARRAY_QUEUE_H__

template<class T>
class arrayQueue {
private:
    T arr[10];
    int head;
    int tail;

public:
    arrayQueue() {
        head = tail = 0;
    }

    bool empty() const {
        return head == tail;
    }

    bool full() const {
        return head == (tail + 1) % (10 + 1);
    }

    void push(T x) {
        if (!full()) {
            arr[tail] = x;
            tail = (tail + 1) % (10 + 1);
        }
    }

    void pop() {
        if (!empty())
            head = (head + 1) % (10 + 1);
    }

    T front() const {
        if (empty())
            return T();
        return arr[head];
    }

    T back() const {
        if (empty())
            return T();
        return arr[(tail - 1 + (10 + 1)) % (10 + 1)];
    }
};

#endif
