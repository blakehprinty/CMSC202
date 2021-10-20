//File: lab6.cpp

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Groceries.h"
using namespace std;


//COMPLETE THIS FUNCTION
void fillVector(vector<Groceries> &groceryList){
    int numItems;
    int itemsAdded = 0;


    cout << "How many grocery items do you want to add to the list?" << endl;
    cin >> numItems;

    do {
        string itemName;
        double itemCost;
        int itemNum;

        cout << "Enter name of grocery item #" << (itemsAdded+1) << ": ";
        cin >> itemName;
        cout << "Enter price of grocery item #" << (itemsAdded+1) << ": ";
        cin >> itemCost;
        cout << "Enter quantity of grocery item #" << (itemsAdded+1) << ": ";
        cin >> itemNum;
        cout << endl;

        Groceries grocery(itemName, itemCost, itemNum);

        groceryList.push_back(grocery);

        itemsAdded += 1;
    } while (itemsAdded < numItems);

    // ask for amount of grocery items
    // ask for name, price, quantity of each item and
    // add them to vector
}

//COMPLETE THIS FUNCTION
void printVectorWithoutIterator(vector<Groceries> &groceryList){
    cout << "Grocery List (without Iterator)" << endl;

    for (unsigned int i = 0; i < groceryList.size(); i++) {
        Groceries a = groceryList[i];
        cout << (i+1) << ". " << a.getItem() << " (" << a.getQuantity();
        cout << ") : $" << fixed << setprecision(2) << a.getPrice() << endl;
    }
    // print each item's name, price, and quantity with correct
    // precision for price
    // DON'T USE ITERATOR

}

//COMPLETE THIS FUNCTION
void printVectorWithIterator(vector<Groceries> &groceryList){
    cout << "Grocery List (with Iterator)" << endl;

    // print each item's name, price, and quantity with correct
    // precision for price
    // USE ITERATOR

}

void checkStatus(vector<Groceries> &groceryList){
    enum status {nonMem = 1, bronze = 2, silver = 3};

    //DEFINE ENUM HERE BASED ON NAMES BELOW
    int listSize = groceryList.size();

    switch (listSize) {
        case nonMem: cout << "You did not purchase enough items to become a member." << endl;
            break;
        case bronze: cout << "You purchased enough items to become a bronze member." << endl;
            break;
        case silver: cout << "You purchased enough items to become a silver member." << endl;
            break;
        default: cout << "You purchased enough items to become a gold member!" << endl;
    }
}

int main(){

    vector<Groceries> groceryList; //Creates a new vector of Groceries

    fillVector(groceryList); //Populates the vector of Groceries
    printVectorWithoutIterator(groceryList); //Displays the contents of the vector
    cout << endl;
    printVectorWithIterator(groceryList); //Alterate way to display the contents of the vector
    checkStatus(groceryList); //calls function defined above (must define enum)

    return 0;
}
