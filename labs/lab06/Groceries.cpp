//
// Created by Blake Printy on 10/13/21.
//

#include "Groceries.h"

Groceries::Groceries() {
    // Default constructor
}

Groceries::Groceries(string item, double price, int quantity) {
    // Overloaded
    setItem(item);
    setPrice(price);
    setQuantity(quantity);
}

void Groceries::setItem(string item) {
    m_item = item;
}

void Groceries::setPrice(double price) {
    m_price = price;
}

void Groceries::setQuantity(int quantity) {
    m_quantity = quantity;
}

string Groceries::getItem() {
    return m_item;
}

double Groceries::getPrice() {
    return m_price;
}

int Groceries::getQuantity() {
    return m_quantity;
}
