// Book Module
// File    Book.h
// Version 1.0
// Full Name  : Sahil Hareshbhai Patel
// Student ID#: 173793225
// Email      : shpatel27@myseneca.ca
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
// -----------------------------------------------------------

#include "Utils.h"
using namespace std;
namespace sdds {
    int getInteger()
    {
        int p;
        cin >> p;
        while (cin.fail() || cin.get() != '\n')
        {
            if (cin.fail())
                cout << "Invalid Selection, try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> p;
        }
        return p;
    }

    int getIntegerRange(int Min, int Max)
    {
        int i = getInteger();
        while (i < Min || i > Max)
        {
            cout << "Invalid Selection, try again: ";
            i = getInteger();
        }
        return i;
    }
}
