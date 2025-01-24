//
// Created by geoff on 2025-01-17.
//

#ifndef NONPERISHABLEITEM_H
#define NONPERISHABLEITEM_H
#include "Item.h"
using namespace std;

//Destructor inherited

//Declarations
class NonPerishableItem : public Item {
    int warrantyPeriod;

    public:
        //Constructor
        NonPerishableItem(int id, const string& name, int quantity, double price, int warrantyPeriod);

        //Getter
        int getWarrantyPeriod() const;

        //Setter
        void setWarrantyPeriod(int period);

        //Display
        void display() const override;
};



#endif //NONPERISHABLEITEM_H
