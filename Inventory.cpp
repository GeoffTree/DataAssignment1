//
// Created by geoff on 2025-01-17.
//

#include "Inventory.h"
#include <iostream>

#include "NonPerishableItem.h"
#include "PerishableItem.h"
using namespace std;

/*Took longer to build Inventory class as had to understand nuances of dynamic memory allocation
 *and reading and writing to/from files.
 *
 * With the inventory being to backbone of the program functionality wanted to ensure
 * methods were clear and ready to be tested after building the menu.
 *
 *Inventory destructor implemented in header file
 */


//Constructor
Inventory::Inventory(int capacity): capacity(capacity), itemCount(0) {}

//Add item - throws error if at capacity
void Inventory::addItem(unique_ptr<Item> item) {
    if (!uniqueId(item->getId())) {
        throw invalid_argument("Item must have unique Id");
    }

    if (itemCount >= capacity) {
        throw overflow_error("Inventory is currently full. Items cannot be added!");
            //with <stdexcept> indicates arithmetic overflow
    }
    items.push_back(move(item));
        //push_back appends a new element to end of vector
        //move is used to transfer ownership of the ptr to the vector
    ++itemCount;
}

//Remove item by id - auto iterator pointing at first vector element
//loop checks getId() to find matching id for deletion
void Inventory::removeItem(int id) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getId() == id) {
            items.erase(it); //releases resources
            --itemCount;
            return;
        }
    }
    throw invalid_argument("Item not found!");
}

//Display all items
void Inventory::displayItems() const {
    if (items.empty()) {
        cout << "There are no items." << endl;
        return;
    }
    for (const auto& item : items) {
        item->display();
        cout << "\n";
    }
    cout << "End of list." << endl;
}

// Save - throws exception if save fails
void Inventory::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        throw ios_base::failure("Could not open file " + filename);
        //ios_base::failure from <fstream> indicates I/O failure
    }
        //saves inventory capacity and item count in next line
    outFile << capacity << " " << itemCount << endl;

        //loops through each item in vector and writes item to file
    for (const auto& item : items) {
        outFile << typeid(*item).name() << " " << item->getId() << " "
                << item->getName() << " " << item->getQuantity() << " "
                << item->getPrice();

            //checks if item perishable or nonperishable and writes appropriate attribute
        if (auto* perishable = dynamic_cast<const PerishableItem* >(item.get())) {
            outFile << " " << perishable->getExpirationDate();
        } else if (auto* nonperishable = dynamic_cast<const NonPerishableItem* > (item.get())) {
            outFile << " " << nonperishable->getWarrantyPeriod();
        }
        outFile << endl;
    }
}

//Load - creates items from file
void Inventory::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        throw ios_base::failure("Could not open file " + filename);
    }

    items.clear(); //ensues inventory empty before load
    itemCount = 0;

    inFile >> capacity >> itemCount;
    for (int i = 0; i < itemCount; ++i) {
        string type;
        int id, quanity;
        double price;
        string name;

        inFile >> type >> id >>name >> quanity >> price;

            //reads type to decide which attribute and type of item (perishable or non) to create
            //make_unique creates a new smart pointer
        if (type == typeid(PerishableItem).name()) {
            string expirationDate;
            inFile >> expirationDate;
            items.push_back(make_unique<PerishableItem>(id, name, quanity, price, expirationDate));

        } else if (type == typeid(NonPerishableItem).name()) {
            int warrantyPeriod;
            inFile >> warrantyPeriod;
            items.push_back(make_unique<NonPerishableItem>(id, name, quanity, price, warrantyPeriod));
        }

        else {
            throw runtime_error("Item type not recognized");
        }
    }
}

//checks to ensure id is unique with auto iterator
bool Inventory::uniqueId(int id) const {
    for (const auto& item : items) {
        if (item->getId() == id) {
            return false;
        }
    }
    return true;
}


