#ifndef PERSON_H //Protects against multiple inclusion
#define PERSON_H //Protects against multiple inclusion
//Name: Person.h
//Project: CMSC 202 Project 2, Fall 2021
//Author:  Jeremy Dixon
//Date:    9/22/21
//Desc: This file contains the header details for a Person class.
#include <iostream>
#include <string>
using namespace std;

//constants
const int MAX_FRIENDS = 10; //Maximum number of friends a person can have

class Person{
public:
    // Name: Person
    // Desc - Default Constructor for a Person
    // Preconditions - Creates a Person with no data associated with it
    // Postconditions - a Person is created
    Person();

    // Name: Person
    // Desc - Overloaded Constructor for a Person
    // Preconditions - Creates a Person with passed data
    // Postconditions - a Person is created
    Person(string, string, int, int);

    // Name: AddFriend
    // Desc - A person pointer is stored from the roster of people in an organization
    // Preconditions - A person pointer is passed
    // Postconditions - A person pointer is added to this person's m_friend's array
    //                  if not at maximum and not already in the array
    void AddFriend(Person*);

    // Name: RemoveFriend
    // Desc - Removes a person pointer from this person's m_friend array
    // Preconditions - Person pointer exists in m_friend
    // Postconditions - Person is removed from m_friend and all pointers are moved towards front
    void RemoveFriend();

    // Name: CheckID
    // Desc - Checks to see if a specific person ID exists in m_friends - Note: IDs will always be unique in proj2
    // Preconditions - m_friends is populated
    // Postconditions - Returns true if id exists in m_friends else false
    bool CheckID(int);

    // Name: DisplayFriends
    // Desc - Displays information about each friend in the m_friend array
    // Preconditions - People are in the m_friend array
    // Postconditions - Displays information about person object in array
    void DisplayFriends();

    // Name: DisplayDetails
    // Desc - Displays information about this person
    // Preconditions - Person data is populated
    // Postconditions - Displays information about person object
    void DisplayDetails();

    // Name: SetDetails
    // Desc - Used as a setter for first name, last name, age, and id
    // Preconditions - Person already created
    // Postconditions - Member variables populated
    void SetDetails(string, string, int, int);

private:
    string m_fName; //Person's first name
    string m_lName; //Person's last name
    int m_age; //Person's age
    int m_ID; //Person's ID
    Person* m_friends[MAX_FRIENDS]; //Person's array of friends
    int m_friendCount; //Person's count of friends
};

#endif //Protects against multiple inclusion
