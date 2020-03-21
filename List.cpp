#ifndef LIST_H
#define LIST_H
#include "Node.cpp"
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class List {
private:
    int length;
    int cursor;

public:
    Node<T>* head;

    //constructors
    List() {
        head = nullptr;
        length = 0;
        cursor = 0;
    }

    void addItem(T* item) {
        Node<T>* newNode = new Node<T>;
        newNode->data = item;
        if (isEmpty()) {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            head = newNode;
            length++;
        } else if ( *(newNode->data) < *(head->data) ) {
            newNode->prev = nullptr;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            length++;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr && *(temp->next->data) < *(newNode->data) ) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            if (temp->next != nullptr) // if newNode is not the last node
                newNode->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
            length++;
        }
    }

    T* getItem(T* key) {
        if (isEmpty()) {
            cout << "The list is empty" << endl;
            return nullptr;
        }

        Node<T> *temp = head;

        while (temp != nullptr) {
            if ((*(temp->data) == *key) && (temp->next != nullptr) && (temp->prev != nullptr) ) { //key is not the last or first but matches
                T *retVal = temp->data;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                length--;
                return retVal;
            } else if (temp->next == nullptr) { //key is the last
                T *retVal = temp->data;
                delete temp;
                head = nullptr;
                length--;
                return retVal;
            } else if (temp->prev == nullptr) { //key is the first
                T *retVal = temp->data;
                head = temp->next;
                delete temp;
                length--;
                return retVal;
            }
            temp = temp->next;
        }
    }

    bool isInList(T* key){
        if (isEmpty()) return false;
        Node<T> *temp = head;
        while ( temp != nullptr ){
            if (*(temp->data) == *key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    class OutOfBounds{};

    void reset() {
        cursor = 0;
    };

    T* seePrev() {
        if (head == nullptr || head->next == nullptr || cursor == 0) throw OutOfBounds();
        Node<T>* temp = head;
        int i;
        for(i = 0; i < cursor; i++) {
            temp = temp->next;
        }
        return temp->prev->data;
    }

    T* seeNext() {
        return seeAt(cursor + 1);
    }
    
    T* seeAt(int index) {
        if (isEmpty()) throw OutOfBounds();
        if (index > length -1 ) throw OutOfBounds();
        if (index < 0) throw OutOfBounds();
        Node<T>* temp = head;
        int i;
        for(i = 0; i < index; i++) {
            temp = temp->next;
        }
        cursor = i;
        return temp->data;
    }

    int size() {
        return length;
    }

    bool isEmpty() {
        bool status;
        if (head == nullptr) {
            status = true;
            return status;
        } else {
            status = false;
            return status;
        }
    }

    void display() {
        Node<T>* temp = head;
        std::cout << "[head]---" << std::endl;
        while (temp != nullptr) {
            std::cout << "--------v" << std::endl;
            std::cout << "[";
            temp->data->displayItem();
            std::cout << "]---" << std::endl;
            temp = temp->next;
        }
        std::cout << "--v" << std::endl;
        std::cout << "[tail]" << std::endl;

    }

    ~List() {
        Node<T>* nodePtr = head;
        Node<T>* nextNode;
        while (nodePtr != nullptr) {
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }
    }

    bool operator > (List const &obj){
        bool status;

        if (length > obj.length) {
            status = true;
            return status;
        } else {
            status = false;
            return status;
        }
    }

    bool operator < (List const &obj){
        bool status;

        if (length < obj.length) {
            status = true;
            return status;
        } else {
            status = false;
            return status;
        }
    }

    bool operator == (List const &obj){
        bool status;

        if (length == obj.length) {
            status = true;
            return status;
        } else {
            status = false;
            return status;
        }
    }

};

#endif
