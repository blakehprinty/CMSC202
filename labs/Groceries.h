//File: Groceries.h

#ifndef LAB_GROCERIES_H
#define LAB_GROCERIES_H

#include <iostream>
#include <string>
using namespace std;

class Groceries
{
public:
    //Default Constructor for Classes
    Groceries();
    //Overloaded Constructor for Classes
    Groceries(string item, double price, int quantity);
    //Name: setItem
    //Sets what the item is
    void setItem(string item);
    //Name setPrice
    //Sets the price for one item
    void setPrice(double price);
    //Name: setQuantity
    //Sets the quantity of the grocery item to be purchased
    void setQuantity(int quantity);
    //Name: getItem
    //Returns the name of the item
    string getItem();
    //Name: getPrice
    //Returns the price of the item
    double getPrice();
    //Name: getQuantity
    //Returns the quantity of the grocery item
    int getQuantity();

private:
    string m_item; //name of the item
    double m_price; //price of the item
    int m_quantity; //quantity of the item
};
#endif
