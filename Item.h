//
// Created by Luke Cheng on 3/16/20.
//

#ifndef INC_08_LAB_ITEM_H
#define INC_08_LAB_ITEM_H
#include <string>
#include "Date.h"

using namespace std;

class Item {
private:

    string description;
    double price;
    string UOM;
    int quantityOnHand;
    int leadTime;

public:
    string SKU;
    Item(string newSKU, string newDescription, double newPrice, string newUOM, int newLeadTime = 3, int newQuantityOnHand = 0); //quantityOnHand is optional
    string getPartInfo(Item* part);
    double getPrice(Item* part);
    bool inStock(Item* part);
    bool available(Date desiredDate);
    void displayItem();

    // operator overloading:
    bool operator<(Item const &obj);
    bool operator>(Item const &obj);
    bool operator==(Item const &obj);
};

#endif //INC_08_LAB_ITEM_H
