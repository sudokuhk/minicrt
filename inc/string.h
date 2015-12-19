/*************************************************************************
    > File Name: string.h
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Thu 17 Dec 2015 08:53:31 PM CST
 ************************************************************************/

#ifndef __STRING_H__
#define __STRING_H__

#include "minicrt.h"
#include "iostream.h"

namespace std {
    class string {
    private:
        unsigned len;
        char * pbuf;
    public:
        explicit string(void);
        string(const char * lhs);
        string(const string& lhs);
        ~string(void);
        string & operator=(const string& lhs);
        string & operator=(const char * lhs);
        const char & operator[](unsigned idx) const;
        const char * c_str() const;
        unsigned length() const;
        unsigned size() const;
    };
    ofstream & operator << (ofstream & lhs, const string& rhs);
}

#endif
