//
// Created by geoff on 2025-01-17.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>
using namespace std;

/*Included <memory> as while learning about dynamic memory allocation discovered unique_ptr
 *unique_ptr is a smart pointer that covers the lifetime of a dynamically allocated object
 *automatically deletes object when no longer needed freeing memory
 *
 */

//Declarations
class Inventory {

    //Class Attributes
    vector<unique_ptr<Item>> items; //from <memory> smart ptr prevents memory leaks
    int capacity;
    int itemCount;

    public:
    //Constructor
    Inventory(int capacity);
        //Initializes object with max capacity with itemCount defaulting to zero
        //items is a vector container that holds references by smart ptr to item objects building the inventory

    //Add item
    void addItem(unique_ptr<Item> item); //add items by smart ptr

    //Remove item by id
    void removeItem(int id);

    //Display all items
    void displayItems() const; //const at end indicates method doesn't modify this object

    //Save inventory to file
    void saveToFile(const string& filename) const; //saving doesn't modify this object so const follows
        //const in method means file name cannot be modified

    //Load inventory to file
    void loadFromFile(const string& filename); //no const after as modifies this object
        //const to ensure name does not change

    //Destructor
    ~Inventory() = default;
};



#endif //INVENTORY_H
