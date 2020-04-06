// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "rational.hpp"
#include "matrix.hpp"
#include "linearSystem.hpp"
using namespace std;

int main() {
    Rational data[] = {
        Rational(0), Rational(7, 3), Rational(2, 3), Rational(3),
        Rational(3,4), Rational(5,3), Rational(7,12), Rational(3),
        Rational(2), Rational(-1,2), Rational(-1,2), Rational(1)
    };

    Matrix m1(data, 3, 4);
    //cin >> m1;

    LinearSystem ls(m1);
    cout << m1 << "-------------------------\n";
    Vector res = ls.getSolution();
    for (int i = 0; i < 3; ++i) {
        cout << res[i]<< " ";
    }
    cout << endl;

    /*Matrix m1;

    ifstream f("C:\\Users\\dtrz\\Desktop\\input.txt");
    f >> m1;
    f.close();

    cout << m1;*/

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
