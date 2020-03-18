#include <iostream>
#include "Item.h"
#include "Node.cpp"
#include "List.cpp"

using namespace std;

int main()
{ //we can copy the rest of this code for the most part.
    cout << "What would you like to do?" << endl;
    cout << endl;
    cout << "1)" << endl;
    cout << "2)" << endl;
    cout << "3)" << endl;
    cout << "4)" << endl;
    cout << "5)" << endl;
    cout << "6)" << endl;
    cout << "7)" << endl;



    List<Item> list();
    for (int i = 0; i < 5; i++) {
        Item* item = new Item("item"+to_string(i), "desc", i, to_string(i), i);
        list.addItem(item);


    }
}
