#include <iostream>

#include "Node.cpp"
#include "List.cpp"
#include "Item.h"
#include <string>

using namespace std;

int main()
{
    bool running = true;
    List<Item> list = List<Item>();
    cout << "The list has been created for you." << endl;
    cout << endl;

    while (running){
        int x;
        cout << "Which functions would you like to try?" << endl;
        cout << "1. Add an item" << endl;
        cout << "2. Get an item (deletes item from the list)" << endl;
        cout << "3. IsInList?" << endl;
        cout << "4. IsEmpty?" << endl;
        cout << "5. Size?" << endl;
        cout << "6. See next?" << endl;
        cout << "7. See prev?" << endl;
        cout << "8. See at" << endl;
        cout << "9. Reset see at function" << endl;
        cout << "10. Display list" << endl;
        cout << endl;

        cin.clear();
        cin >> x;
        if ( cin.fail() || ( x<0 || x>10 ) )
        {
            cin.clear();
            cin.ignore();
            cout << "This is an invalid input.  Try again." << endl;
            continue;
        }

        switch (x)
        {
            case 1: {
                string userSKU;
                string userDescription;
                double userPrice;
                string userUOM;
                int userLeadTime;
                int userQuantityOnHand;

                cout << "What is the SKU?" << endl;
                cin >> userSKU;
                cout << endl;

                cin.ignore();
                cout << "What is the description?" << endl;
                getline(cin, userDescription);
                cout << endl;

                cout << "What is the price?" << endl;
                cin >> userPrice;
                cout << endl;

                cout << "What is the unit of measure?" << endl;
                cin >> userUOM;
                cout << endl;

                cout << "What is the Lead Time in days?" << endl;
                cin >> userLeadTime;
                cout << endl;

                cout << "What is the quantity on hand?" << endl;
                cin >> userQuantityOnHand;
                cout << endl;

                Item *newItem = new Item(userSKU, userDescription, userPrice, userUOM, userLeadTime, userQuantityOnHand);
                list.addItem(newItem);
                cout << "Your item: " << endl;
                newItem->displayItem();
                cout << endl;
                break;
            }

            case 2: {
                string userKey;
                cout << endl;
                cout << "What is the SKU?" << endl;
                cin >> userKey;

                Item* keyItem = new Item(userKey, "desc", 10, "unit" );
                cout << "The item was: ";
                list.getItem(keyItem)->displayItem();
                cout << endl;
                break;
            }

            case 3: {
                string userKey;
                cout << "What is the SKU?" << endl;
                cin >> userKey;

                Item* keyItem = new Item(userKey, "desc", 10, "unit" );
                cout << "Is it in the list? (1 = yes/ 0 = no)" << endl;
                cout << list.isInList(keyItem) << endl;
                break;
            }

            case 4: {
                cout << "Is the list empty? (1 = yes/ 0 = no)" << endl;
                cout << list.isEmpty() << endl;
                break;
            }

            case 5: {
                cout << "Size: " << list.size() << endl;
                break;
            }

            case 6: {
                try {
                    list.seeNext()->displayItem();
                    break;
                } catch (List<Item>::OutOfBounds) {
                    cout << "This is invalid.  Try again." << endl;
                    continue;
                }
            }

            case 7: {
                try {
                    list.seePrev()->displayItem();
                    break;
                } catch (List<Item>::OutOfBounds) {
                    cout << "This is invalid.  Try again." << endl;
                    continue;
                }
            }

            case 8: {
                int userIndex;
                cout << "What is the index of the item? (starting from 0)" << endl;
                cin >> userIndex;

                try {
                    list.seeAt(userIndex)->displayItem();
                    cout << endl;
                    break;
                } catch (List<Item>::OutOfBounds) {
                    cout << "This is invalid.  Try again." << endl;
                    continue;
                }
            }

            case 9: {
                list.reset();
                cout << "The see at cursor has been reset" << endl;
                break;
            }

            case 10:{
                list.display();
            }

        }

        cout << "Would you like to continue? (1 = yes/ 0 = no)" << endl;
        cin >> running;

    }
}
