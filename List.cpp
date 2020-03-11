#include "Node.cpp"

template <class T>
class LinkedList{
private:
    Node <T>head

public:
    T* addItem(T* item){
        Node* newNode = new Node;
        newNode->data = *item;

        if(head == nullptr)
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

        Node *temp = head;
        while (temp->next != nullptr && temp->next->data < newNode->data){
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;

    }
    T* getItem(){}
    bool isInList(){}
    bool isEmpty(){}
    int size(){}
    T* seeNext(){}
    T* seePrev(){}
    T* seeAt(int index){}
    void reset(){}

    //constructors
    LinkedList(){
    head = nullptr;

    }

};

#include "List.h"
