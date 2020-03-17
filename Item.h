//
// Created by Luke Cheng on 3/16/20.
//

#ifndef INC_08_LAB_ITEM_H
#define INC_08_LAB_ITEM_H
#include <string>
using namespace std;

class Item {
private:
    string SKU;
    string description;
    double price;
    string UOM;
    int quantityOnHand;
    int leadTime;

public:
    Item(string newSKU, string newDescription, double newPrice, string newUOM, int newQuantityOnHand = 0); //quantityOnHand is optional
    string getPartInfo(Item* part);
    double getPrice(Item* part);
    bool inStock(Item* part);
    bool available(Date availKey); //implement data object
    //TODO: overload >, <, and == operators
};


#endif //INC_08_LAB_ITEM_H
