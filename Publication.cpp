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
#include <cstring>
#include <iomanip>
#include "Publication.h"
using namespace std;

namespace sdds
{
    Publication::Publication()
    {
        setToDefault();
    }

    Publication::Publication(const Publication& p1)
    {
        *this = p1;
    }

    Publication& Publication::operator=(const Publication& p1)
    {
        set(p1.m_membership);
        setRef(p1.m_libRef);
        strcpy(m_shelfId, p1.m_shelfId);
        m_date = p1.m_date;

        if(m_title)
        {
            delete [] m_title;
            m_title = nullptr;
        }

        if(p1.m_title != nullptr)
        {
            m_title = new char[strlen(p1.m_title) + 1];
            strcpy(m_title, p1.m_title);
        }
        else {
            m_title = nullptr;
        }
        return *this;
    }

    Publication::~Publication()
    {
        delete [] m_title;
    }

    void Publication::setToDefault()
    {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();
    }

    void Publication::set(int member_id)
    {
        m_membership = member_id;
    }

    void Publication::setRef(int value)
    {
        m_libRef = value;
    }

    void Publication::resetDate()
    {
        m_date = Date();
    }

    char Publication::type() const
    {
        return 'P';
    }

    bool Publication::onLoan() const
    {
        if(m_membership != 0)
            return true;
        else
            return false;
    }

    Date Publication::checkoutDate() const
    {
        return m_date;
    }

    bool Publication::operator==(const char* title) const
    {
        return strstr(m_title, title) != nullptr;
    }

    Publication::operator const char* ()const
    {
        return m_title;
    }

    int Publication::getRef() const
    {
        return m_libRef;
    }

    bool Publication::conIO(std::ios& io)const
    {
        return (&io == &std::cin || &io == &std::cout);

    }

    std::ostream& Publication::write(std::ostream& os) const
    {
        if(conIO(os))
        {
            os << " | " << m_shelfId << " | ";
            int p = 0;
        for (p = 0; p < SDDS_TITLE_WIDTH; p++) {
            if (m_title[p] == '\0') {
                break;
            }
            else {
                os << m_title[p];
            }
        }
        for (p = p; p < SDDS_TITLE_WIDTH; p++) {
            os << ".";
        }
            os << " | ";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << " | " << m_date << " | ";
        }
        else {
            os << type() << "\t" << "\t" << m_libRef << "\t" << m_shelfId << "\t";
            os << m_title;
            os << "\t";
            (m_membership != 0) ? os << m_membership : os << " N/A ";
            os << "\t" << m_date;
        }
        return os;
    }

    std::istream& Publication::read(std::istream& is)
    {
        char title[256] {}, shelfId[SDDS_SHELF_ID_LEN + 1] {};
        int libRef = -1, membership = 0;
        Date date;
        if(m_title) {
          delete [] m_title;
        }
        setToDefault();

        if(conIO(is))
        {
            cout << "Shelf No: ";
            is.getline(shelfId, SDDS_SHELF_ID_LEN + 1);
            if(strlen(shelfId) != SDDS_SHELF_ID_LEN)
                is.setstate(ios::failbit);

            cout << "Title: ";
            is.getline(title,256);

            cout << "Date: ";
            is >> date;
        }
        else {
            is >> libRef;
            is.ignore();
            is.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
            is.getline(title, 256, '\t');
            is >> membership;
            is.ignore();
            is >> date;
        }

        if(!date)
            is.setstate(ios::failbit);

        if(is)
        {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            strcpy(m_shelfId, shelfId);
            m_membership = membership;
            m_date = date;
            m_libRef = libRef;
        }

        return is;
    }

    Publication::operator bool() const
    {
        if(m_title != nullptr && m_shelfId[0] != '\0')
            return true;
        else
            return false;
    }
}

