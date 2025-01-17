//
// Created by geoff on 2025-01-17.
//

#include "Item.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
using namespace std;

//First simple attempt at class design  before implementing new knowledge

// base item class
class Item {
    //class attributes private
    private:
        int id;
        string name;
        int quantity;
        double price;

    public:
    // Base Constructor
        Item(int id, string name, int quantity, double price)
            : id(id), name(name), quantity(quantity), price(price) {}

    // Getters
    int getId() { return id; }
    string getName() { return name; }
    int getQuantity() { return quantity; }
    double getPrice() { return price; }

    // Setters
    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setQuantity(int quantity) { this->quantity = quantity; }
    void setPrice(double price) { this->price = price; }

    // Display
    void display() {
            cout << "Item id: " << id << endl;
            cout << "Item name: " << name << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Price: $" << price << endl;
        }
};