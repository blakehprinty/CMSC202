//Title: FriendFinder.cpp
//Author: Blake Printy
//Date: 10/5/2021

#include "FriendFinder.h"
using namespace std;

const int displayOrg = 1;
const int displayFriends = 2;
const int searchFriend = 3;
const int removeFriend = 4;
const int stop = 5;

FriendFinder::FriendFinder() {
    cout << "*****************************" << endl;
    cout << "Welcome to UMBC Friend Finder" << endl;
    cout << "*****************************" << endl;

    Start();
}

void FriendFinder::GetDetails() {
    string firstName;
    string lastName;
    int age;
    int id;

    cout << "What is your first name?" << endl;
    cin >> firstName;
    cout << "What is your last name?" << endl;
    cin >> lastName;
    cout << "What is your age?" << endl;
    cin >> age;
    cout << "What is your ID?" << endl;
    cin >> id;

    m_me.SetDetails(firstName, lastName, age, id);
}

void FriendFinder::DisplayMenu(int &choice) {
    cout << "What would you like to do?" << endl;
    cout << "1. Display Entire Organization" << endl;
    cout << "2. Display Friends List" << endl;
    cout << "3. Search for a Friend" << endl;
    cout << "4. Remove Friend" << endl;
    cout << "5. Exit" << endl;

    cin >> choice;
    cout << endl;
}

void FriendFinder::Start() {
    int choice;

    GetDetails();
    m_organization.SetName();
    m_organization.LoadRoster();

    do {
        DisplayMenu(choice);

        if (choice == displayOrg) {
            cout << "You are: ";
            m_me.DisplayDetails();
            cout << endl;
            m_organization.DisplayRoster();
            cout << endl;
        } else if (choice == displayFriends) {
            m_me.DisplayFriends();
            cout << endl;
        } else if (choice == searchFriend) {
            m_me.AddFriend(m_organization.GetPerson());
            cout << endl;
        } else if (choice == removeFriend) {
            m_me.RemoveFriend();
            cout << endl;
        }
    } while (choice != stop);

    cout << "Thank you for using UMBC Friend Finder!" << endl;
}