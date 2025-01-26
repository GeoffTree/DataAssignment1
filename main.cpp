#include <iostream>
#include <limits>
#include <memory>
#include <regex>
#include "Inventory.h"
#include "PerishableItem.h"
#include "NonPerishableItem.h"
using namespace std;

/*addItem uses make_unique to assign a unique_ptr to newly constructed object
 *deletes and deallocates the object and associated memory when pointer out of scope
 */

//Function Declarations, Implementation handled at bottom of file
void displayMenu();
void clearBuffer();
bool validDate(const string& date);
void addItem(Inventory& inventory);
void removeItem(Inventory& inventory);
void saveToFile(const Inventory& inventory);
void loadFromFile(Inventory& inventory);

//Menu functionality
int main() {
    //Initialize an Inventory and an option variable
    Inventory inventory(100);
    int option;

    //do-while exit option not selected, displays menu and runs functionality for each option
    //on exit return 0
    do {
        displayMenu();
        cin >> option;
        switch (option) {
            //Add an Item
            case 1: {
                addItem(inventory);
                break;
            }
            //Remove an Item
            case 2: {
                removeItem(inventory);
                break;
            }
            //Display Inventory
            case 3: {
                inventory.displayItems();
                break;
            }
            //Save to File
            case 4: {
                saveToFile(inventory);
                break;
            }
            //Load from File
            case 5: {
                loadFromFile(inventory);
                break;
            }
            //Exit
            case 6: {
                cout << "Exit\n";
                break;
            }
            //base case
            default:
                clearBuffer();
                cout << "Invalid Input\n";
                break;
        }
    }while (option != 6);
    return 0;
}

//Logic implementations
void addItem(Inventory& inventory) {
    // Initialize itemType
    int itemType;
    clearBuffer();

    //Get user input for object creation
    cout << "Enter 1 if Item is Perishable or Enter 2 for Non-Perishable\n";
    while (!(cin >> itemType) && (itemType != 1 && itemType != 2)) {
        cout << "Invalid option. Enter 1 if Item is Perishable or Enter 2 for Non-Perishable\n";
        clearBuffer();
    }

    clearBuffer();

    cout << "Enter ID: ";
    int id;
    while (!(cin >> id) && !inventory.uniqueId(id)){
        cout << "Invalid Id. Enter Id: ";
        clearBuffer();
    }

    clearBuffer();

    cout << "Enter Name: ";
    string name;
    cin >> name;

    clearBuffer();

    cout << "Enter Price: ";
    double price;
    while (!(cin >> price)) {
        cout << "Invalid Price. Enter Price: ";
        clearBuffer();
    }

    clearBuffer();

    cout << "Quantity: ";
    int quantity;
    while (!(cin >> quantity) && quantity < 0) {
        cout << "Invalid Quantity. Enter Quantity: ";
        clearBuffer();
    }

    clearBuffer();

    //expiration and warranty period attribute if/else statement
    if (itemType == 1) {
        cout << "Enter Expiration Date (YYYY-MM-DD): ";
        string expirationDate;

        while(!(cin >> expirationDate && validDate(expirationDate))) {
            cout << "Invalid Date. Enter Expiration Date (YYYY-MM-DD): ";
            clearBuffer();
        };
        inventory.addItem(make_unique<PerishableItem>(id, name, quantity, price, expirationDate));
    }
    else if (itemType == 2) {
        cout << "Enter Warranty Period (In Months): ";
        int warrantyPeriod;
        while (!(cin >> warrantyPeriod)) {
            cout << "Invalid Warranty Period. Enter Warranty Period: ";
            clearBuffer();
        }
        inventory.addItem(make_unique<NonPerishableItem>(id, name, quantity, price, warrantyPeriod));
    }
    else {
        cout << "Invalid Input\n";
    }
}

void removeItem(Inventory& inventory) {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    try {
        inventory.removeItem(id);
        cout << "Item Deleted\n";
    }
    catch (const exception& e) {
        cout << "Error:" << e.what() << "\n";
    }
}

void saveToFile(const Inventory& inventory) {
    string fileName;
    cout << "Name of save file: ";
    cin >> fileName;

    try {
        inventory.saveToFile(fileName);
        cout << "File saved\n";
    }
    catch (const exception& e) {
        cout << "Error:" << e.what() << "\n";
    }
}

void loadFromFile(Inventory& inventory) {
    string fileName;
    cout << "Name of load file: ";
    cin >> fileName;

    try {
        inventory.loadFromFile(fileName);
        cout << "File Loaded\n";
    }
    catch (const exception& e) {
        cout << "Error:" << e.what() << "\n";
    }
}

void clearBuffer() {
    cin.clear();
    //clears unwanted characters from buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool validDate(const string& date) {
    const regex datePattern(R"(\d{4}-\d{2}-\d{2})");
    return regex_match(date, datePattern);
}

void displayMenu() {
    cout << "\nInventory Management System\n";
    cout << "1.Add Item to Inventory\n";
    cout << "2.Remove Item from Inventory\n";
    cout << "3.Display Inventory Items\n";
    cout << "4.Save Inventory to File\n";
    cout << "5.Load Inventory from File\n";
    cout << "6.Exit\n";
    cout << "\nPlease Select an Option from the Menu: ";
};