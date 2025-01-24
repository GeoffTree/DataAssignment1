#include <iostream>
#include <limits>
#include <memory>
#include "Item.h"
#include "Inventory.h"
#include "PerishableItem.h"
#include "NonPerishableItem.h"

using namespace std;

/*Add Item uses make_unique to assign a unique_ptr to newly constructed object
 *deletes and deallocates the object and associated memory when pointer out of scope
 */

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

int main() {
    //Initialize an Inventory and an option variable
    Inventory inventory(100);
    int option;

    //do-while not exit option, displays menu and runs functionality for each option
    //on exit return 0
    do {
        displayMenu();
        cin >> option;

        switch (option) {

            //Add an Item
            case 1: {

                // Initialize itemType
                int itemType;

                //Get user input for object creation
                cout << "Enter 1 if Item is Perishable or Enter 2 for Non-Perishable\n";
                while (!(cin >> itemType) || (itemType != 1 && itemType != 2)) {
                    cout << "Invalid option. Enter 1 if Item is Perishable or Enter 2 for Non-Perishable\n";
                    cin.clear();
                    //clears unwanted characters from buffer
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Enter ID: ";
                int id;
                while (!(cin >> id)) {
                    cout << "Invalid Id. Enter Id: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Enter Name: ";
                string name;
                cin >> name;

                cout << "Enter Price: ";
                double price;
                while (!(cin >> price)) {
                    cout << "Invalid Price. Enter Price: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Quantity: ";
                int quantity;
                while (!(cin >> quantity)) {
                    cout << "Invalid Quantity. Enter Quantity: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                //expiration and warranty period attribute if/else statement
                if (itemType == 1) {
                    cout << "Enter Expiration Date (YYYY-MM-DD): ";
                    string expirationDate;
                    cin >> expirationDate;
                    inventory.addItem(make_unique<PerishableItem>(id, name, quantity, price, expirationDate));
                }
                else if (itemType == 2) {
                    cout << "Enter Warranty Period (In Months): ";
                    int warrantyPeriod;
                    while (!(cin >> warrantyPeriod)) {
                        cout << "Invalid Warranty Period. Enter Warranty Period: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    inventory.addItem(make_unique<NonPerishableItem>(id, name, quantity, price, warrantyPeriod));
                }
                else {
                    cout << "Invalid Input\n";
                }

                break;
            }

            //Remove an Item
            case 2: {
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
                break;
            }

            //Display Inventory
            case 3: {
                inventory.displayItems();
                break;
            }

            //Save to File
            case 4: {
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

                break;
            }

            //Load from File
            case 5: {
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

                break;
            }

            //Exit
            case 6: {
                cout << "Exit\n";
                break;
            }

            //base case
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input\n";
                break;
        }
    }while (option != 6);
    return 0;
}
