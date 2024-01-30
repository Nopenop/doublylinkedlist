#include "DLList.h"
#include "DLList.cpp"
int main() {
DLList<char> l;
l.pop_front();
l.pop_back();
l.push_back('C');
l.pop_front();
l.push_front('A');
l.pop_back();
l.push_back('W');
l.push_front('V');
l.push_back('6');
l.push_front('F');
l.push_front('W');
l.print_backwards();


std::cout<<"\n\n\n";
// call even odd on quiz list
// print out forward and backward
l.evenOdd();
l.print();
l.print_backwards();

// clear list
l.clear();

// goes through and add integers
// from 1 to 9
for(int i = 1; i <10; i++){
    l.push_back(char(i+48));
}

// prints original list
l.print();
// prints swapped
l.evenOdd();
l.print();


std::cout<<"\n\n\n";

// test for the remaining methods
DLList<char> ex1(l);
ex1.pop_back();
ex1.pop_back();
ex1.pop_back();
ex1.print();

l = ex1;
l.print();
return 0;
}