#ifndef DLLNODE_H
#define DLLNODE_H
#include <iostream>
template<typename T>
class DLLNode {
public:
    //T() - default template value
    DLLNode(const T& d = T(), DLLNode<T>* p = nullptr, DLLNode<T>* n = nullptr) {
        data = d;
        prev = p;
        next = n;
    }
    T data;
    DLLNode<T>* next;
    DLLNode<T>* prev;
};
#endif