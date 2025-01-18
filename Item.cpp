//
// Created by geoff on 2025-01-17.
//

#include "Item.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
using namespace std;

/*Third attempt at Item class design implementing new knowledge,
 *moved class declarations into the header file to improve readability.
 *added const and string& where appropriate to make program reference rather than copy the string
 *const additions optimize the code for the compiler indicating that some values are immutable
 */

Item::Item(int id, const string& name, int quantity, double price)
            : id(id), name(name), quantity(quantity), price(price) {}

    // Getters
    int Item::getId() const { return id; }
    const string& Item::getName() const{ return name; }
    int Item::getQuantity() const { return quantity; }
    double Item::getPrice() const { return price; }

    // Setters
    void Item::setId(int id) { this->id = id; }
    void Item::setName(const string& name) { this->name = name; }
    void Item::setQuantity(int quantity) { this->quantity = quantity; }
    void Item::setPrice(double price) { this->price = price; }

    // Display
    void Item::display() const {
            cout << "Item id: " << id << endl;
            cout << "Item name: " << name << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Price: $" << price << endl;
        }
;