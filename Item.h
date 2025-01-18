//
// Created by geoff on 2025-01-17.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

//Base Item Class Declarations
class Item {

    //Class Attributes
    private:
        int id;
        string name;
        int quantity;
        double price;

    public:
        // Constructor
        Item(int id, const string& name, int quantity, double price);

        // Getters
        int getId() const;
        const string& getName() const;
        int getQuantity() const;
        double getPrice() const;

        // Setters
        void setId(int id);
        void setName(const string& name);
        void setQuantity(int quantity);
        void setPrice(double price);

        // Display
        virtual void display() const;
        virtual ~Item() = default;
};



#endif //ITEM_H
