//
// Created by Luke Cheng on 3/16/20.
//

#include "Item.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>

Item::Item(string newSKU, string newDescription, double newPrice, string newUOM, int newLeadTime, int newQuantityOnHand) {
    SKU = newSKU;
    description = newDescription;
    price = newPrice;
    UOM = newUOM;
    leadTime = newLeadTime;
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

bool Item::available(Date desiredDate)
{
    int year, month, day;
    bool status;

    std::cout << "Please input the current date";
    std::cout << "What is the current year?";
    std::cin >> year;
    std::cout << "What is the current month?";
    std::cin >> month;
    std::cout << "What is the current day?";
    std::cin >> day;

    //calculate leadDate
    //reuse variables of currentDate
    if ( (month == 1) || (month = 3) || (month = 5) || (month = 7) || (month = 8) || (month = 10) || (month = 12) ) {
        if ( (day + leadTime) > 31) {
            day = (leadTime + day) % 31;
            month = (month + 1) % 12;
        } else {
            day = leadTime + day;
        }
    } else if ( (month == 4) || (month = 6) || (month = 9) || (month = 11) ) {
        if ( (day + leadTime) > 30) {
            day = (leadTime + day) % 30;
            month = (month + 1) % 12;
        } else {
            day = leadTime + day;
        }
    } else { // month is 2
        if ( (day + leadTime) > 28) {
            day = (leadTime + day) % 28;
            month = (month + 1) % 12;
        } else {
            day = leadTime + day;
        }
    }

    //create leadDate
    Date leadDate = Date(year, month, day);

    if( quantityOnHand > 0 ){
        status = true;
        return status;
    } else if(desiredDate > leadDate ) {
        status = false;
        return status;
    } else {
        status = true;
        return status;
    }
}

bool Item::operator < (Item const &obj)
{
    bool status;
    int cSKU = 0;
    int oSKU = 0;
    stringstream currentSKU(SKU);
    stringstream objectSKU(obj.SKU);

    currentSKU >> cSKU;
    objectSKU >> oSKU;

    if(cSKU < oSKU) {
        status = true;
        return status;
    } else {
        status = false;
        return status;
    }
}

bool Item::operator > (Item const &obj)
{
    bool status;
    int cSKU = 0;
    int oSKU = 0;
    stringstream currentSKU(SKU);
    stringstream objectSKU(obj.SKU);

    currentSKU >> cSKU;
    objectSKU >> oSKU;

    if(cSKU > oSKU) {
        status = true;
        return status;
    } else {
        status = false;
        return status;
    }
}

bool Item::operator == (Item const &obj)
{
    bool status;
    int cSKU = 0;
    int oSKU = 0;
    stringstream currentSKU(SKU);
    stringstream objectSKU(obj.SKU);

    currentSKU >> cSKU;
    objectSKU >> oSKU;

    if(cSKU == oSKU) {
        status = true;
        return status;
    } else {
        status = false;
        return status;
    }
}

void Item::displayItem() {
    cout << "/////////////////////////////////////////////////////////";
    cout << "SKU:" << SKU << ", " << "Price:" << price  << "Quantity:" << quantityOnHand << endl;
    cout << "/////////////////////////////////////////////////////////";
}