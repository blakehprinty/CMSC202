#include <iostream>
#include <string>
#include "Train.h"
using namespace std;

int main(){
    Train* polarExpress = new Train();
    polarExpress->InsertCar("locomotive");
    polarExpress->InsertCar("Passenger");
    polarExpress->InsertCar("Passenger");
    polarExpress->InsertCar("Hot Chocolate");
    polarExpress->Display();
    polarExpress->RemoveLast();
    polarExpress->Display();
    polarExpress->InsertCar("Storage");
    polarExpress->Display();

    // clean up
    delete polarExpress;
}
