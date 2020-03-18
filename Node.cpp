#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
    T* data; //stores object
    Node* next;
    Node* prev;
};

#endif
