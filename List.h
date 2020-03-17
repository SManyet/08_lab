#ifndef LIST_H
#define LIST_H
#include "Node.h"

template <class T>
class List
{

private:
    Node<T> head;

public:

    //not implemented yet
    bool isInList();
    bool isEmpty();
    bool getItem(T* key);

    int size();
    T* seeNext();
    T* seePrev();
    T* seeAt(int index);
    void reset();

    //constructors
    List::List();

    //operations implemented:
    bool List<T>::isEmpty();
    bool getItem(T* key);
    void addItem(T* item);
};

List::List(){
    head = nullptr;
}

bool List<T>::isEmpty(){
    if(head == nullptr)
        return true;
    else
        return false;
}

bool getItem(T* key)
{
    if( isEmpty() )
        return false;
    Node<T> *temp = head;
                  //double pointer?

} //basically pop()

void addItem(T* item){
    Node<T>* newNode = new Node<T>; //TODO: why do we use <T> here?
    newNode->data = *item;

    if( isEmpty() )
    {
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
    }
    else if(newNode->data < head->data)
    {
        newNode->next = head;
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node<T> *temp = head;
    while (temp->next != nullptr && temp->next->data < newNode->data)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

#endif;