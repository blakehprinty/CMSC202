//
//
//

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
    string firstName;
    string lastName;
    string userAge;
    int age;
    string userID;
    int id;

    string line;

    ifstream file (m_fileName);

    if (!file.is_open()) {
        LoadRoster();
    }

    while (getline(file, line)) {
        stringstream ss(line);

        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, userAge, ',');
        getline(ss, userID, ',');

        age = stoi(userAge);
        id = stoi(userID);

        Person newP;
        newP.SetDetails(firstName, lastName, age, id);
        m_roster[m_numRoster] = newP;
        m_numRoster += 1;
    }
    file.close();

    cout << m_numRoster << " people loaded into the roster" << endl;
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

    DisplayRoster();

    cout << endl << "Who would you like to friend?" << endl;
    cin >> personLocation;

    if (personLocation <= m_numRoster) {
        Person *returnPerson = &m_roster[personLocation-1];
        return returnPerson;
    } else {
        cout << "There is no person at that location" << endl;
        GetPerson();
    }

}