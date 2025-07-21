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

#include "Book.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace sdds {
    Book::Book() {
        m_authorName = nullptr;
    }

    Book::Book(const Book& b1)    : Publication(b1){
        m_authorName = nullptr;
        if (b1.m_authorName != nullptr) {
            m_authorName = new char[strlen(b1.m_authorName) + 1];
            strcpy(m_authorName, b1.m_authorName);
        }
    }

    Book& Book::operator=(const Book& b1) {
        Publication::operator=(b1);

        if (m_authorName) {
            delete[] m_authorName;
            m_authorName = nullptr;
        }

        if (b1.m_authorName != nullptr) {
            m_authorName = new char[strlen(b1.m_authorName) + 1];
            strcpy(m_authorName, b1.m_authorName);
        }
        else {
            m_authorName = nullptr;
        }
        return *this;
    }

    Book::~Book() {
        delete[] m_authorName;
    }

    bool Book::conIO(std::ios& io) const {
        return &io == &std::cin || &io == &std::cout;
    }

    char Book::type() const {
        return 'B';
    }

    std::ostream& Book::write(std::ostream& os) const
    {
        Publication::write(os);

        if (conIO(os))
        {
            os << " ";
            int i = 0;
            for (i = 0; i < SDDS_AUTHOR_WIDTH; i++)
            {
                if (m_authorName[i] == '\0') {
                    break;
                }
                else {
                    os << m_authorName[i];
                }
            }
            for (i = i; i < SDDS_AUTHOR_WIDTH; i++) {
                os << " ";
            }
            os << " |";
        }
        else {
            os << '\t' << m_authorName;
        }
        return os;
    }

    std::istream& Book::read(std::istream& is) {
        char name[256]{};

        Publication::read(is);

        if (m_authorName) {
            delete[] m_authorName;
        }
        m_authorName = nullptr;

        if (conIO(is)) {
            is.ignore();
            cout << "Author: ";
            is.getline(name, 256);
        }
        else {
            is.ignore();
            is.get(name, 256);
        }

        if (is) {
            m_authorName = new char[strlen(name) + 1];
            strcpy(m_authorName, name);
        }
        return is;
    }

    void Book::set(int member_id) {
        Publication::set(member_id);
        resetDate();
    }

    Book::operator bool() const {
        if (m_authorName != nullptr && Publication::operator bool()) {
            return true;
        }
        else
            return false;
    }
}


