#ifndef __DOU_LIST_H__
#define __DOU_LIST_H__

#include <cstddef>

class douList {
public:
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
     listPointer tail;
     size_type _size;

 private:
     inline listPointer at(int index) {
         if (index >= 0 && index < this->_size) {
           if (index <= this->_size / 2) {
             int counter = 0;
             listPointer p = this->head;
             while (counter != index) {
               counter++;
               p = p->next;
             }
             return p;
           } else {
             int counter = 0;
             listPointer p = this->tail;
             while (counter != this->_size - 1 - index) {
               counter++;
               p = p->prev;
             }
             return p;
           }
         }
         return NULL;
     }

public:
    douList() {
        head = tail = NULL;
        _size = 0;
    }

    douList(const douList &li) {
        if (li._size == 0) {
            head = tail = NULL;
            _size = 0;
          } else {
            listPointer ht = new listNode;
            ht->data = li.head->data;
            ht->next = NULL;
            ht->prev = NULL;
            head = ht;
            tail = ht;
            listPointer ph = head;
            for (listPointer q = li.head->next; q != NULL; q = q->next) {
              listPointer p = new listNode;
              p->data = q->data;
              p->next = NULL;
              p->prev = ph;
              ph->next = p;
              tail = p;
              ph = ph->next;
            }
            _size = li._size;
          }
    }

    ~douList() { this->clear(); }

    // Capacity
    bool empty(void) const {
        return head == NULL && tail == NULL && _size == 0;
    }

    size_type size(void) const { return _size; }

    // Element access
    data_type& front(void) const { return head->data; }

    data_type& back(void) const { return tail->data; }

public:
    // Modifiers
    void push_front(const data_type &data) {
        if (_size == 0) {
            listPointer ph = new listNode;
            ph->data = data;
            ph->next = NULL;
            ph->prev = NULL;
            head = ph;
            tail = ph;
          } else {
            listPointer p = new listNode;
            p->data = data;
            p->next = head;
            p->prev = NULL;
            head->prev = p;
            head = p;
          }
          _size++;
    }

    void push_back(const data_type &data) {
        if (_size == 0) {
            listPointer ph = new listNode;
            ph->data = data;
            ph->next = NULL;
            ph->prev = NULL;
            head = ph;
            tail = ph;
          } else {
            listPointer p = new listNode;
            p->data = data;
            p->next = NULL;
            p->prev = tail;
            tail->next = p;
            tail = p;
          }
          _size++;
    }

    void pop_front(void) {
        if (_size == 0)
            return;
        if (_size == 1) {
            this->clear();
        } else {
            listPointer temp = head->next;
            delete head;
            head = temp;
            head->prev = NULL;
            _size--;
        }
    }

    void pop_back(void) {
        if (_size == 0)
            return;
        if (_size == 1) {
            this->clear();
        } else {
            listPointer temp = tail->prev;
            delete tail;
            tail = temp;
            tail->next = NULL;
            _size--;
        }
    }

    void insert(int position, const data_type &data) {
        if (position > _size)
            return;

        if (position == 0) {
            if (head == NULL) {
                listPointer ht = new listNode;
                ht->data = data;
                ht->next = NULL;
                ht->prev = NULL;
                head = ht;
                tail = ht;
                _size++;
            } else {
                push_front(data);
            }
        } else if (position == _size) {
            if (tail == NULL) {
                listPointer ht = new listNode;
                ht->data = data;
                ht->next = NULL;
                ht->prev = NULL;
                head = ht;
                tail = ht;
                _size++;
            } else {
                push_back(data);
            }
        } else {
            listPointer p = new listNode;
            p->data = data;
            listPointer temp1 = this->at(position - 1);
            listPointer temp2 = this->at(position);
            temp1->next = p;
            p->prev = temp1;
            temp2->prev = p;
            p->next = temp2;
            _size++;
        }
    }

    void erase(int position) {
        if (position >= _size)
            return;
        if (position == 0) {
            pop_front();
        } else if (position == _size - 1) {
            pop_back();
        } else {
            listPointer temp1 = this->at(position - 1);
            listPointer temp2 = this->at(position);
            listPointer temp3 = this->at(position + 1);
            temp1->next = temp3;
            temp3->prev = temp1;
            delete temp2;
            temp2 = NULL;
            _size--;
        }
    }

    void clear(void) {
        if (head != NULL) {
            listPointer p = head;
            while (p != NULL) {
              listPointer temp = p->next;
              delete p;
              p = temp;
            }
            head = NULL;
            tail = NULL;
            _size = 0;
          }
    }
};

#endif
