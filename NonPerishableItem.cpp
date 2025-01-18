//
// Created by geoff on 2025-01-17.
//

#include "NonPerishableItem.h"
#include "Item.h"
#include <iostream>
using namespace std;

/*First attempt at NonPerishableItem
 *Not significantly different from Perishable just subtle things with new variable being int not string
 *
 */
NonPerishableItem::NonPerishableItem(int id, const string &name, int quantity, double price, int warrantyPeriod)
    : Item(id, name, quantity, price), warrantyPeriod(warrantyPeriod) {}

    //Getter implementation for new warranty period field
    int NonPerishableItem::getWarrantyPeriod() const {return warrantyPeriod;}

    //Setter implementation
    void NonPerishableItem::setWarrantyPeriod(int period) {warrantyPeriod = period;}

    //Display override implementation
    void NonPerishableItem::display() const{
        Item::display();
        cout << "WarrantyPeriod: " << warrantyPeriod << endl;
    }
