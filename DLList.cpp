#include "DLList.h"
#include <iostream>
template<typename T>
DLList<T>::DLList() {
    head = new DLLNode<T>; //sentinel header node
    tail = new DLLNode<T>; //sentinel tail node
    head->next = tail;
    tail->prev = head;
    listSize = 0;
}
template<typename T>
DLList<T>::~DLList() {
    clear();
}
template<typename T>
DLList<T>::DLList(const DLList<T>& other) {
    head = new DLLNode<T>; //sentinel header node
    tail = new DLLNode<T>; //sentinel tail node
    head->next = tail;
    tail->prev = head;
    DLLNode<T>* cur = other.head->next;
    while(cur != other.tail){
        push_back(cur->data);
        cur = cur->next;
    }
}
template<typename T>
DLList<T>& DLList<T>::operator=(const DLList<T>& other){
    clear();
    DLLNode<T>* cur = other.head->next;
    while(cur != other.tail){
        push_back(cur->data);
        cur = cur->next;
    }
    return *this;
}
template<typename T>
unsigned DLList<T>::size() const {
    return listSize;
}
template<typename T>
bool DLList<T>::empty() const {
    return (listSize == 0);
}

template<typename T>
void DLList<T>::print() const {
    //iterate through the linked list
    DLLNode<T>* cur = head->next;
    while(cur != tail) {
        std::cout << cur->data << " -> ";
        cur = cur->next;
    }
    std::cout << "/\n";
}
template<typename T>
void DLList<T>::push_back(const T& value) {
    tail->prev = new DLLNode<T>(value, tail->prev, tail);
    tail->prev->prev->next = tail->prev;
    listSize++; //update size
}
template<typename T>
void DLList<T>::pop_front() {
    if (!empty()) {
        DLLNode<T>* to_delete = head->next;
        head->next = head->next->next;
        head->next->prev = head;
        listSize--;
        delete to_delete;
    }
}

template<typename T>
void DLList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

/*Definitions for quiz*/

template<typename T>
void DLList<T>::print_backwards() const{
    //iterate through the linked list
    DLLNode<T>* cur = tail->prev;
    while(cur != head) {
        std::cout << cur->data << " <- ";
        cur = cur->prev;
    }
    std::cout << "/\n";
}

template<typename T>
void DLList<T>::pop_back() {
    if(!empty())
    {
        DLLNode<T>* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        listSize--;
        delete temp;
    }
}


template<typename T>
void DLList<T>::evenOdd(){
    unsigned arraySize = listSize/2 + 1;
    T *evens = new T[arraySize];
    T *odds = new T[arraySize];
    unsigned evensUsed = 0;
    unsigned oddsUsed = 0;
    DLLNode<T>* cur = head->next;
    short int i = 1;
    // goes through list and puts
    // even index in evens array
    // and odd index in odds array
    while(i <= listSize) {
        unsigned check = i % 2;
        //checks whether index is even or odd
        switch(check){
            case(0):
            //even
            *(evens + evensUsed) = cur->data;
            evensUsed++;
            break;
            default:
            //odd
            *(odds + oddsUsed) = cur->data;
            oddsUsed++;
        }
        i++;
        cur = cur->next;
    }
    // resets dummy head to head
    cur = head->next;
    // resets index counter
    i = 0;
    // goes through evens array
    // and sets list values to evens
    while(i<evensUsed) {
        cur->data = *(evens+i);
        // std::cout << *(evens+i) << std::endl;
        cur = cur->next;
        i++;
    }
    // resets counter and goes through
    // odds array and sets last values of 
    // list to odds array
    i = 0;
    while(i<oddsUsed) {
        cur->data = *(odds+i);
        // std::cout << *(odds+i) << std::endl;
        cur = cur->next;
        i++;
    }
    // deletes the values pointed at
    delete[] evens;
    delete[] odds;
}

template<typename T>
void DLList<T>::push_front(const T& value) {
    head->next = new DLLNode<T>(value, head, head->next);
    head->next->next->prev = head->next;
    listSize++;
}

template<typename T>
void DLList<T>::insert(int index, T value, int k) {
    if(index >= listSize) return;
    DLLNode<T>* cur = head->next;
    int i = 0;
    while(i < index-1){
        cur = cur->next;
        i++;
    }
    i = 0;
    while(i < k){
        cur->next = new DLLNode<T>(value, cur, cur->next);
        listSize++;
        i++;
    }
}

template<typename T>
void DLList<T>::erase (int index){
    if(index >= listSize) return;
    DLLNode<T>* cur = head->next;
    int i = 0;
    while(i < index){
        cur = cur->next;
        i++;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    listSize--;
}

template<typename T>
void DLList<T>::remove (T value){
    DLLNode<T>* cur = head->next;
    int i = 0;
    while(i < listSize){
        if (cur->data == value){
            cur = cur->next;
            erase(i);
            continue;
        }
        cur = cur->next;
        i++;
    }
    
}