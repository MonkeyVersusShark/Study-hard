#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define MAX_STORAGE 1000

class arrayList{
private:
    typedef int data_type;
    typedef int pointer;
    typedef unsigned int size_type;
    static const pointer nullpointer = -1;

private:
    struct node {
        data_type data;
        pointer next;

        node(const node &another) {
            this->data = another.data;
            this->next = another.next;
        }

        node& operator=(const node &another) {
            if (this == &another)
                return *this;
            this->data = another.data;
            this->next = another.next;
            return *this;
        }

        node(data_type data = 0, pointer next = nullpointer)
        : data(data), next(next) { }
    };

private:
    node storage[MAX_STORAGE];
    size_type _size;
    pointer head;
    pointer empty_head;

public:
    arrayList() {
        this->head = nullpointer;
        this->_size = 0;
        this->empty_head = 0;
        for (int i = 0; i < MAX_STORAGE - 1; i++)
          storage[i].next = i + 1;
        storage[MAX_STORAGE - 1].next = nullpointer;
    }

    arrayList(const arrayList &another) {
        for (int i = 0; i < MAX_STORAGE; i++)
            storage[i] = another.storage[i];
        this->head = another.head;
        this->empty_head = another.empty_head;
        this->_size = another._size;
    }

    ~arrayList() { }

    // Capacity
    bool empty(void) const { return this->_size == 0; }

    size_type size(void) const { return this->_size; }

    void insert(int position, const int &data) {
        if (position >= 0 && position <= this->_size) {
            if (this->_size + 1 <= MAX_STORAGE) {
                pointer freeNode = empty_head;
                empty_head = storage[empty_head].next;
                storage[freeNode].data = data;
                if (position == 0) {
                    storage[freeNode].next = head;
                    head = freeNode;
                } else {
                    pointer p = head;
                    for (int i = 0; i < position - 1; i++)
                        p = storage[p].next;
                    storage[freeNode].next = storage[p].next;
                    storage[p].next = freeNode;
                }
                this->_size++;
            }
        }
    }

    void erase(int position) {
        if (position >= 0 && position < this->_size) {
            if (position == 0) {
                pointer temp = head;
                head = storage[head].next;
                storage[temp].next = empty_head;
                empty_head = temp;
            } else {
                pointer p = head;
                for (int i = 0; i < position - 1; i++)
                    p = storage[p].next;
                pointer temp = storage[p].next;
                storage[p].next = storage[storage[p].next].next;
                storage[temp].next = empty_head;
                empty_head = temp;
            }
            this->_size--;
        }
    }

    void clear(void) {
        this->head = nullpointer;
        this->_size = 0;
        this->empty_head = 0;
        for (int i = 0; i < MAX_STORAGE - 1; i++)
            storage[i].next = i + 1;
        storage[MAX_STORAGE - 1].next = nullpointer;
    }
};

#endif
