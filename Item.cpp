//
// Created by geoff on 2025-01-17.
//

#include "Item.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
using namespace std;

/*Second attempt at Item class design implementing new knowledge, moved class declarations into the
 *header file to improve readability.
 *
 */

Item::Item(int id, string name, int quantity, double price)
            : id(id), name(name), quantity(quantity), price(price) {}

    // Getters
    int Item::getId() { return id; }
    string Item::getName() { return name; }
    int Item::getQuantity() { return quantity; }
    double Item::getPrice() { return price; }

    // Setters
    void Item::setId(int id) { this->id = id; }
    void Item::setName(string name) { this->name = name; }
    void Item::setQuantity(int quantity) { this->quantity = quantity; }
    void Item::setPrice(double price) { this->price = price; }

    // Display
    void Item::display() {
            cout << "Item id: " << id << endl;
            cout << "Item name: " << name << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Price: $" << price << endl;
        }
;