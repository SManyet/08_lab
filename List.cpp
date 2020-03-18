#ifndef LIST_H
#define LIST_H
#include "Node.cpp"

template <class T>
class List {
private:
    Node<T>* head;
    int length;
    int cursor;

public:
   
    //constructors
    List() {
        head = nullptr;
        length = 0;
        cursor = 0;
    }

    class OutOfBounds{};

    //not implemented yet
    void reset() {
        cursor = 0;
    };

    T* seePrev() {
        return seeAt(cursor - 1);
    }

    T* seeNext() {
        return seeAt(cursor + 1);
    }
    
    T* seeAt(int index) {
        if (length == 0) throw OutOfBounds();
        if (index > length) throw OutOfBounds();
        if (index < -1) throw OutOfBounds();
        if (index == -1) return nullptr;
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

    bool isInList(T* item) {
        if (isEmpty()) return false;
        else {

        } 
    }

    bool isEmpty() {
        if(head == nullptr) return true;
        else return false;
    }

    T* getItem(T* key) {
        if (isEmpty()) return false;
        Node<T> *temp = head;
        while (temp != nullptr && *(temp->data) < *(key->data)) {
            temp = temp->next;
        }
        if (temp == nullptr) return nullptr;
        else {
            T* retVal = temp->data;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            length--;
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
        } else if (*(head->data) < *(newNode->data)) {
            newNode->prev = nullptr;
            newNode->next = head;
            head = newNode;
            length++;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr && *(temp->next->data) < *(newNode->data)) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
            length++;
        }
    }

    ~List() {
        Node<T>* temp = head->next;
        while (temp != nullptr) {
            delete temp->prev;
            temp = temp->next;
        }
        delete temp->prev;
    }
};

#endif
