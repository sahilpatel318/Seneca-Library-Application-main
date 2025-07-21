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

#include <iostream>
#include "Streamable.h"

namespace sdds
{
    Streamable::~Streamable() {}

    std::ostream& operator<<(std::ostream & os, const Streamable& s1)
    {
        if(s1)
        {
            s1.write(os);
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& s1)
    {
        s1.read(is);
        return is;
    }
}
