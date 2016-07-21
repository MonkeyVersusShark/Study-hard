#ifndef __RB_TREE_H__
#define __RB_TREE_H__

#include <cstddef>
#include <stack>
#include <iostream>
using namespace std;

class RBtree {
private:
    enum RB { RED, BLACK };

private:
    struct node {
        int key;
        RB color;
        node *left;
        node *right;
        node *parent;

        node(int k = 0, RB c = BLACK,
        node *l = NULL, node *r = NULL, node *p = NULL)
        : key(k), color(c), left(l), right(r), parent(p) { }
    };

private:
    node *root;
    node *nil;

public:
    RBtree() {
        nil = new node();
        root = nil;
    }

    ~RBtree() {
        if (root != nil) {
            node *curr = nil;
            node *pre = nil;
            stack<node *> s;
            s.push(root);
            while (!s.empty()) {
                curr = s.top();
                if ((curr->left == nil && curr->right == nil) ||
                (pre != nil && (pre == curr->left || pre == curr->right))) {
                    delete curr;
                    s.pop();
                    pre = curr;
                } else {
                    if (curr->right != nil)
                        s.push(curr->right);
                    if (curr->left != nil)
                        s.push(curr->left);
                }
            }
        }
    }

private:
    void left_rotate(node *x) {
        if (x != nil && x->right != nil) {
            node *y = x->right;
            x->right = y->left;
            if (y->left != nil)
                y->left->parent = x;
            y->parent = x->parent;
            if (x->parent == nil)
                root = y;
            else if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
        }
    }

    void right_rotate(node *x) {
        if (x != nil && x->left != nil) {
            node *y = x->left;
            x->left = y->right;
            if (y->right != nil)
                y->right->parent = x;
            y->parent = x->parent;
            if (x->parent == nil)
                root = y;
            else if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->right = x;
            x->parent = y;
        }
    }

private:
    void RB_insert_fixUp(node *z) {
        while (z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                node *y = z->parent->parent->right;
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        left_rotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    right_rotate(z->parent->parent);
                }
            } else {
                node *y = z->parent->parent->left;
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        right_rotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    left_rotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

public:
    void RB_insert(int k) {
        node *z = new node(k);
        node *y = nil;
        node *x = root;
        while (x != nil) {
            y = x;
            if (z->key < x->key)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == nil)
            root = z;
        else if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
        z->left = nil;
        z->right = nil;
        z->color = RED;
        RB_insert_fixUp(z);
    }

private:
    void RB_transplant(node *u, node *v) {
        if (u->parent == nil)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        v->parent = u->parent;
    }

    node *RB_minimum(node *x) {
        node *curr = x;
        while (curr != nil)
            curr = curr->left;
        return curr;
    }

    void RB_delete_fixUp(node *x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                node *w = x->parent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    left_rotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        right_rotate(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    left_rotate(x->parent);
                    x = root;
                }
            } else {
                node *w = x->parent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    right_rotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        left_rotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    right_rotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

public:
    void RB_delete(node *z) {
        node *y = z;
        node *x = nil;
        RB y_original_color = y->color;
        if (z->left == nil) {
            x = z->right;
            RB_transplant(z, z->right);
        } else if (z->right == nil) {
            x = z->left;
            RB_transplant(z, z->left);
        } else {
            y = RB_minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                RB_transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            RB_transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == BLACK)
            RB_delete_fixUp(x);
    }
};

#endif
