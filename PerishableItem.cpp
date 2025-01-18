//
// Created by geoff on 2025-01-17.
//

#include "PerishableItem.h"
#include "Item.h"
#include <iostream>
using namespace std;


/*First attempt perishableItem, following design of the more developed Item class
 *demonstrates inheritance and polymorphism
 *maintaining const and string& for efficiency and security reasons
 *overrode display and added a default destructor to clean up resources
 */

//Constructor implementation
PerishableItem::PerishableItem(int id, const string &name, int quantity, double price, const string &expirationDate)
    : Item(id, name, quantity, price), expirationDate(expirationDate) {}

    //Getter implementation for new expiration date field
    const string& PerishableItem::getExpirationDate() const{
        return expirationDate;
    }

    //Setter implementation
    void PerishableItem::setExpirationDate(const string &expirationDate) {
        this->expirationDate = expirationDate;
    }

    //Display override implementation
    void PerishableItem::display() const{
        Item::display();
        cout << "Expiration Date: " << expirationDate << endl;
    }

