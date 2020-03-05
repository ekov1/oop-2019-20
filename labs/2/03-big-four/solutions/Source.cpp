#include <iostream>
#include "Vector.h"

int main()
{
    // Testing our class
    Vector vec;   // Calling the default constructor
    vec.push_back(5);
    vec.push_back(8);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(9);

    // Since at(..) returns int&, which gives us
    // the actual element wihout copying it, we
    // can change the element in the array like this:
    vec.at(2) = -5; // Changes the element at index 2

    // Printing each element
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec.at(i) << ' ';

    std::cout << std::endl;

    // What about a lot more elements?
    Vector vec2;  // Calling the default constructor
    
    // We can easily add a lot of elements
    for (int i = 0; i <= 100; i++)
        vec2.push_back(2 * i);  // adding all the 

    // And printing each one
    for (int i = 0; i < vec2.size(); i++)
        std::cout << vec2.at(i) << ' ';

    return 0;
}
