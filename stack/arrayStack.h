#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

template <class T>
class arrayStack {
private:
    T arr[10];
    int size;
    int top_pos;

public:
    arrayStack() {
        size = 0;
        top_pos = -1;
    }

    bool empty() const {
        return size == 0;
    }

    void push(T x) {
        if (size < 10) {
            arr[++top_pos] = x;
            ++size;
        }
    }

    void pop() {
        if (!this->empty()) {
            --top_pos;
            --size;
        }
    }

    T top() const {
        if (this->empty())
            return T();
        return arr[top_pos];
    }
};

#endif
