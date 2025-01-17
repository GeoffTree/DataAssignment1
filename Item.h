//
// Created by geoff on 2025-01-17.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

// base item class
class Item {
//class attributes private
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    // Constructor
    Item(int id, string name, int quantity, double price);

    // Getters
    int getId();
    string getName();
    int getQuantity();
    double getPrice();

    // Setters
    void setId(int id);
    void setName(string name);
    void setQuantity(int quantity);
    void setPrice(double price);

    // Display
    void display();
};



#endif //ITEM_H
