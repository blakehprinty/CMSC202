#ifndef TRAIN_H
#define TRAIN_H
/*Title: LinkedList.h
Author: Eddie Nieberding
Date: 3/8/2020
Description: This is a train linked list for lab 7.
*/

#include <iostream>
#include <string>
using namespace std;

//Each node of the linked list holds at least one piece of data and
//at least one pointer (usually to the m_next node in the linked list)
struct TrainCar {
    string m_name;   //Data for the linked list
    TrainCar *m_next; //Pointer to the m_next node of the linked list
};

class Train{ //Linked list structure
public:
    Train(); //Default constructor that builds an empty linked list
    ~Train(); //Destructor that cleans up linked list
    void InsertCar(string name); //Function that inserts node at front with data value
    void RemoveLast(); //Function removes the first node in the list
    void Display(); //Function that iterates over the linked list to display the contents
private:
    TrainCar *m_head; //Pointer to the beginning of the linked list
    TrainCar *m_tail; //Pointer to the end of the linked list
    int m_size; //Counter for the size of the linked list
};

#endif
