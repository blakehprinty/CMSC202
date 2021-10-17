//Name: Organization.h
//Project: CMSC 202 Project 2, Fall 2021
//Author:  Jeremy Dixon
//Date:    9/29/2021
//Desc: This file contains the header details for an Organization class.

#ifndef ORGANIZATION_H //Protects against multiple inclusion
#define ORGANIZATION_H //Protects against multiple inclusion

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Person.h" //Must be implemented before Organization
using namespace std;

//Constants
const int MAX_PEOPLE = 40; //Maximum number of people in organization
const string FILE_NAME = "proj2_data.txt";

class Organization{
public:
    // Name: Organization
    // Desc - Default constructor for Organization
    // Preconditions - None
    // Postconditions - Organization is created (empty) with 0 people in the roster
    Organization();

    // Name: SetName
    // Desc - Sets m_name by asking user for name
    // Preconditions - m_name exists
    // Postconditions - Asks user for the organization name and populates m_name
    void SetName();

    // Name: LoadRoster
    // Desc - Sets m_fileName by asking user. Then populates all of the people loaded from file
    // Preconditions - m_fileName exists. m_roster empty
    // Postconditions - Asks user for m_fileName. Loads data from file and populates m_roster
    void LoadRoster();

    // Name: DisplayRoster
    // Desc - Displays a numbered list of everyone in the roster (starts at 1)
    // Preconditions - m_roster is populated
    // Postconditions - Displays a numbered list of people
    void DisplayRoster();

    // Name: GetPerson
    // Desc - Displays a list of people in m_roster and user enters number of desired person.
    //        Returns pointer of that person in m_roster
    // Preconditions - m_roster is populated
    // Postconditions - Returns pointer for the person chosen from list
    Person* GetPerson();

private:
    string m_name; //Name of the organization
    string m_fileName; //Name of the input file
    int m_numRoster; //Number of people in roster
    Person m_roster [MAX_PEOPLE]; //Roster of people in the organization
};

#endif
