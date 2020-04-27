// SoftwareCompany.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Person.h"
#include "Client.h"
#include "Employee.h"

using namespace std;

int main() {
    Person p1("georgi", "todorov", 42);

    cout << p1;

    string ordersArr[] = { "order1", "order2" };
    Vector<string> orders(ordersArr, 2);
    Client c(p1, orders);
    cout << c;

    Employee e(p1);
    cout << e;

}