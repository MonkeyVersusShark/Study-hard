#ifndef __BS_TREE_H__
#define __BS_TREE_H__

#include <iostream>
#include <stack>
using namespace std;

struct Info {
    string name;        // use name as key
    string tag;
    string phone_number;

    Info(string s1 = "", string s2 = "", string s3 = "")
    : name(s1), tag(s2), phone_number(s3) { }

    Info(const Info &x)
    : name(x.name), tag(x.tag), phone_number(x.phone_number) { }

    friend ostream &operator<<(ostream &os, const Info &x) {
        os << "name:\t" << x.name << endl;
        os << "tag:\t" << x.tag << endl;
        os << "phone number:\t" << x.phone_number << endl;
        return os;
    }
};

class BStree {
private:
    struct node {
        Info data;
        node *left;
        node *right;
        node *prev;

        node(Info d = Info(), node *l = NULL, node *r = NULL, node *p = NULL)
        : data(d), left(l), right(r), prev(p) { }
    };

private:
    node *root;

private:
    void transplant(node *p1, node *p2) {
        if (p1->prev == NULL)
            root = p2;
        else if (p1 == p1->prev->left)
            p1->prev->left = p2;
        else
            p1->prev->right = p2;
        if (p2 != NULL)
            p2->prev = p1->prev;
    }

public:
    BStree() : root(NULL) { }

    ~BStree() {
        if (root != NULL) {
            node *curr = NULL;
            node *pre = NULL;
            stack<node *> s;
            s.push(root);
            while (!s.empty()) {
                curr = s.top();
                if ((curr->left == NULL && curr->right == NULL) ||
                (pre != NULL && (pre == curr->left || pre == curr->right))) {
                    delete curr;
                    s.pop();
                    pre = curr;
                } else {
                    if (curr->right != NULL)
                        s.push(curr->right);
                    if (curr->left != NULL)
                        s.push(curr->left);
                }
            }
        }
    }

    // With recursion
    static void inorder_tree_walk(node *r) {
        if (r != NULL) {
            inorder_tree_walk(r->left);
            cout << r->data;
            inorder_tree_walk(r->right);
        }
    }

    // Without recursion
    static void inorder_tree_walk_no_recursion(node *r) {
        if (r != NULL) {
            node *curr = r;
            stack<node *> s;
            while (curr != NULL || !s.empty()) {
                while (curr != NULL) {
                    s.push(curr);
                    curr = curr->left;
                }
                if (!s.empty()) {
                    curr = s.top();
                    s.pop();
                    cout << curr->data;
                    curr = curr->right;
                }
            }
        }
    }

    // With recursion
    static void preorder_tree_walk(node *r) {
        if (r != NULL) {
            cout << r->data;
            preorder_tree_walk(r->left);
            preorder_tree_walk(r->right);
        }
    }

    // Without recursion
    static void preorder_tree_walk_no_recursion(node *r) {
        if (r != NULL) {
            node *curr = r;
            stack<node *> s;
            while (curr != NULL || !s.empty()) {
                while (curr != NULL) {
                    cout << curr->data;
                    s.push(curr);
                    curr = curr->left;
                }
                if (!s.empty()) {
                    curr = s.top();
                    s.pop();
                    curr = curr->right;
                }
            }
        }
    }

    // With recursion
    static void postorder_tree_walk(node *r) {
        if (r != NULL) {
            postorder_tree_walk(r->left);
            postorder_tree_walk(r->right);
            cout << r->data;
        }
    }

    // Without recursion
    static void postorder_tree_walk_no_recursion(node *r) {
        if (r != NULL) {
            node *curr = NULL;
            node *pre = NULL;
            stack<node *> s;
            s.push(r);
            while (!s.empty()) {
                curr = s.top();
                if ((curr->left == NULL && curr->right == NULL) ||
                (pre != NULL && (pre == curr->left || pre == curr->right))) {
                    cout << curr->data;
                    s.pop();
                    pre = curr;
                } else {
                    if (curr->right != NULL)
                        s.push(curr->right);
                    if (curr->left != NULL)
                        s.push(curr->left);
                }
            }
        }
    }

    node *BStree_search(const Info &x) const {
        node *curr = root;
        while (curr->data.name != x.name) {
            if (x.name < curr->data.name)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return curr;
    }

    static node *BStree_minimum(node *x) {
        node *curr = x;
        while (curr->left != NULL)
            curr = curr->left;
        return curr;
    }

    static node *BStree_maximum(node *x) {
        node *curr = x;
        while (curr->right != NULL)
            curr = curr->right;
        return curr;
    }

    static node *successor(node *x) {
        node *curr = x;
        if (curr->right != NULL)
            return BStree_minimum(curr->right);
        node *prev = curr->prev;
        while (prev != NULL && curr == prev->right) {
            curr = prev;
            prev = prev->prev;
        }
        return prev;
    }

    static node *predecessor(node *x) {
        node *curr = x;
        if (curr->left != NULL)
            return BStree_maximum(curr->left);
        node *prev = curr->prev;
        while (prev != NULL && curr == prev->left) {
            curr = prev;
            prev = prev->prev;
        }
        return prev;
    }

    void BStree_insert(const Info &x) {
        node *curr = root;
        node *prev = NULL;
        node *new_node = new node(x);
        while (curr != NULL) {
            prev = curr;
            if (x.name < curr->data.name)
                curr = curr->left;
            else
                curr = curr->right;
        }
        new_node->prev = prev;
        if (prev == NULL)
            root = new_node;
        else if (new_node->data.name < prev->data.name)
            prev->left = new_node;
        else
            prev->right = new_node;
    }

    void BStree_delete(const Info &x) {
        node *curr = BStree_search(x);
        if (curr->left == NULL) {
            transplant(curr, curr->right);
        } else if (curr->right == NULL) {
            transplant(curr, curr->left);
        } else {
            node *p = BStree_minimum(curr->right);
            if (p->prev != curr) {
                transplant(p, p->right);
                p->right = curr->right;
                p->right->prev = curr;
            }
            transplant(curr, p);
            p->left = curr->left;
            p->left->prev = p;
        }
        delete curr;
    }

    node *getRoot() const { return root; }
};

#endif
