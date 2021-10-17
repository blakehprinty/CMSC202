//Title: Person.cpp
//Author: Blake Printy
//Date: 10/5/2021

#include "Person.h"
using namespace std;

const int noFriends = 0;

Person::Person() {
    // Person with no data
    m_friendCount = 0;
}

Person::Person(string firstName, string lastName, int userAge, int userID) {
    // Using the function SetDetails, populate the data associated with a new Person
    SetDetails(firstName, lastName, userAge, userID);
}

void Person::AddFriend(Person* personPtr) {
    // Add a new Person to the Persons friends array
    if (m_friendCount == MAX_FRIENDS) { // If the person has reached the maximum number of friends allowed
        cout << "You must remove a friend before adding another" << endl;
    } else {
        if (CheckID(personPtr->m_ID)) { // If the person is already friends with someone they are trying to add
            cout << "You are already friends with " << personPtr->m_fName << endl;
        } else { // Otherwise, add the person to the persons friends
            m_friends[m_friendCount] = personPtr;
            cout << "You are now friends with " << personPtr->m_fName << endl;
            m_friendCount += 1; // Increment number of friends to show a new friend has been made
        }
    }
}

void Person::RemoveFriend() {
    int personToRemove; // Used to store the location of the person that the user wants to unfriend

    DisplayFriends(); // Start by displaying the users friends

    if (m_friendCount > noFriends) { // Make sure the user has friends to remove
        cout << endl << "Who would you like to remove?" << endl;
        cin >> personToRemove; // The numbered location of the friend the user wishes to unfriend

        if (personToRemove <= m_friendCount) {
            Person *removePerson = m_friends[personToRemove-1]; // Create a removePerson pointer for the friend that is to be removed

            Person* temp_m_friends[MAX_FRIENDS]; // A temporary array of Persons that holds the users friends

            // Move all people from the users friends array into the temporary array
            int x = 0;
            for (int i = 0; i < m_friendCount; i++) {
                if (m_friends[i] != removePerson) {
                    temp_m_friends[x] = m_friends[i];
                    x += 1;
                }
            }
            m_friendCount -= 1; // Reduce the number of friends the user has by 1

            // Now update m_friends to hold the new array of friends
            for (int j = 0; j < m_friendCount; j++) {
                m_friends[j] = temp_m_friends[j];
            }
            cout << "You are no longer friends with " << removePerson->m_fName << endl;
        } else {
            cout << "Unable to remove friend." << endl;
        }
    }
}

bool Person::CheckID(int idCheck) {
    // Looks through the users friends to see if the user exists
    for (int i = 0; i < m_friendCount; i++) {
        if (m_friends[i]->m_ID == idCheck) {
            return true; // Returns true when the id is found
        }
    }
    return false; // Returns false if the id is never found
}

void Person::DisplayFriends() {
    if (m_friendCount == noFriends) {
        cout << "You don't have any friends yet" << endl;
    } else {
        // Displays the data for friend
        for (int i = 0; i < m_friendCount; i++) {
            cout << (i+1) << ". ";
            m_friends[i]->DisplayDetails();
            // 1. Blake Printy (19 yrs) 1234567
            // 2. Penelope Torres (18 yrs) 2345678
        }
    }
}

void Person::DisplayDetails() {
    cout << m_fName << " " << m_lName << " (" << m_age << " yrs) " << m_ID << endl;
    // Example : Blake Printy (19 yrs) 1234567
}

void Person::SetDetails(string firstName, string lastName, int userAge, int userID) {
    // Set the first name, last name, age, and user id of a person
    m_fName = firstName;
    m_lName = lastName;
    m_age = userAge;
    m_ID = userID;
}