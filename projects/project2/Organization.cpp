//Title: Organization.cpp
//Author: Blake Printy
//Date: 10/5/2021

#include "Organization.h"
using namespace std;

Organization::Organization() {
    m_numRoster = 0;
    m_fileName = FILE_NAME;
}

void Organization::SetName() {
    cout << "What is the name of your organization?" << endl;
    cin >> m_name; // Sets the member variable m_name to the org name given by the user
}

void Organization::LoadRoster() {
    ifstream file (FILE_NAME);
    string line;

    string firstName;
    string lastName;
    string userAge;
    string userID;
    int age;
    int id;

    while (getline(file, firstName, ',')) {
        getline(file, lastName, ',');
        getline(file, userAge, ',');
        getline(file, userID);

        age = stoi(userAge);
        id = stoi(userID);

        Person newPerson(firstName, lastName, age, id);
        m_roster[m_numRoster] = newPerson;
        m_numRoster += 1;
    }
}

void Organization::DisplayRoster() {
    cout << "***" << m_name << "***" << endl;

    for (int i = 0; i < m_numRoster; i++) {
        cout << (i+1) << ". ";
        m_roster[i].DisplayDetails();
        // Displays the details for each person in m_roster
    }
}

Person* Organization::GetPerson() {
    int personLocation;

    DisplayRoster(); // Start by showing the roster

    // If the user enters a number greater than the number of people in the roster
    do {
        cout << endl << "Who would you like to friend?" << endl;
        cin >> personLocation;
    } while (personLocation > m_numRoster);

    Person *returnPerson = &m_roster[personLocation-1];
    return returnPerson; // Return the person found at the location given
}
