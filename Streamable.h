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

#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_
#include <iostream>

using namespace std;
namespace sdds
{
    class Streamable{
    public:
        virtual std::ostream& write(std::ostream& ) const = 0;
        virtual std::istream& read(std::istream& ) = 0;
        virtual bool conIO(std::ios& )const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable();
    };
    std::ostream& operator<<(std::ostream& ,const Streamable& );
    std::istream& operator>>(std::istream& , Streamable& );
}


#endif /* SDDS_STREAMABLE_H_ */
