#ifndef LIST_H
#define LIST_H
#include "Node.cpp"

template <class T>
class List {
private:
    Node<T>* head;

public:
   
    //constructors
    List() {
        head = nullptr;
    }

    //not implemented yet
    bool isInList();
    int size();
    T* seeNext();
    T* seePrev();
    T* seeAt(int index);
    void reset();
    
    // implimented
    bool isEmpty() {
        if(head == nullptr) return true;
        else return false;
    }

    T* getItem(T* key) {
        if (isEmpty()) return false;
        Node<T> *temp = head;
        while (temp != nullptr && temp->data < key->data) {
            temp = temp->next;
        }
        if (temp == nullptr) return nullptr;
        else {
            T* retVal = temp->data;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return retVal;
        }
    }

    void addItem(T* item) {
        Node<T>* newNode = new Node<T>;
        newNode->data = item;
        if (isEmpty()) {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            head = newNode;
        } else if (head->data < newNode->data) {
            newNode->prev = nullptr;
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr && temp->next->data < newNode->data) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
};

#endif
