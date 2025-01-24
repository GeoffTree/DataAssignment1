//
// Created by geoff on 2025-01-17.
//

#ifndef PERISHABLEITEM_H
#define PERISHABLEITEM_H
#include "Item.h"
using namespace std;

//Destructor inherited

//Class Declarations
class PerishableItem : public Item {

    //Class Attributes
    private:
        string expirationDate;

    public:
        //Constructor
        PerishableItem(int id, const string& name, int quantity, double price, const string& expirationDate);
            //const to prevent modification and 'string&' to prevent a copy of string being made

        //Getter
        const string& getExpirationDate() const;

        //Setter
        void setExpirationDate(const string& expirationDate);

        //Display
        void display() const override;
};


#endif //PERISHABLEITEM_H
