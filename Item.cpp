//
// Created by Luke Cheng on 3/16/20.
//

#include "Item.h"
#include "Date.h"

Item::Item(string newSKU, string newDescription, double newPrice, string newUOM, int newQuantityOnHand) {
    SKU = newSKU;
    description = newDescription;
    price = newPrice;
    UOM = newUOM;
    quantityOnHand = newQuantityOnHand;
}

string Item::getPartInfo(Item* part)
{
    string partInfo = part->SKU + ": " + part->description;
    return partInfo;
}

double Item::getPrice(Item* part)
{
    return part->price;
}

bool Item::inStock(Item * part)
{
    if (part->quantityOnHand <= 0)
        return false;
    else
        return true;
}

// bool available(Date availKey) // implement after creating Date object
