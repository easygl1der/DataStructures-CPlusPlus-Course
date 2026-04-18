#pragma once
#include <iostream>

template<typename T>
class SingleLink {
public:
    struct Node {
        T _value;
        Node* _next;
        Node(T value) : _value(value), _next(nullptr) {}
    };
    typedef Node* pointer;

    SingleLink() : _head(nullptr), _size(0) {}
    ~SingleLink() {
        while (_head) {
            Node* temp = _head;
            _head = _head->_next;
            delete temp;
        }
    }

    void insert(int pos, T value) {
        if (pos < 0 || pos > _size) return;
        Node* newNode = new Node(value);
        if (pos == 0) {
            newNode->_next = _head;
            _head = newNode;
        } else {
            Node* current = _head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->_next;
            }
            newNode->_next = current->_next;
            current->_next = newNode;
        }
        _size++;
    }

    void insert_head(T value) {
        insert(0, value);
    }

    void insert_last(T value) {
        insert(_size, value);
    }

    pointer getHead() const { return _head; }
    int size() const { return _size; }

private:
    Node* _head;
    int _size;
}; 