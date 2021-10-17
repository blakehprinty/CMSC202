//Name: FriendFinder.h
//Project: CMSC 202 Project 2, Fall 2021
//Author:  Jeremy Dixon
//Date:    9/29/2021
//Desc: This file contains the header details for a FriendFinder class.

#ifndef FRIEND_FINDER_H //Protects against multiple inclusion
#define FRIEND_FINDER_H //Protects against multiple inclusion

#include <iostream>
#include <string>
#include "Organization.h" //Must be implemented before FriendFinder
#include "Person.h" //Must be implemented before FriendFinder

using namespace std;

class FriendFinder{
public:
    // Name: FriendFinder
    // Desc - Default constructor for application for finding friends
    // Preconditions - Creates a Person and an organization
    // Postconditions - Welcomes user and calls Start()
    FriendFinder();

    // Name: GetDetails
    // Desc - Asks user for their first name, last name, age, and ID to populate m_me
    // Preconditions - None
    // Postconditions - Populates information related to m_me
    void GetDetails();

    // Name: DisplayMenu
    // Desc - Displays main menu for application
    // Preconditions - None
    // Postconditions - Called from Start updates integer passed
    void DisplayMenu(int &choice);

    // Name: Start
    // Desc - Main function running FriendFinder
    //        Calls GetDetails
    //        Populates data for organization
    //        Continually calls DisplayMenu until someone enters 4 (exit)
    // Preconditions - m_me and m_organization are created but not populated
    // Postconditions - Runs until user enters 4. Thanks user for usage. Ends application
    void Start();
private:
    Person m_me; //Information about me
    Organization m_organization; //Information about my organization
};

#endif
