/*************************************************************************
  > File Name: string.cpp
  > Author: sudoku.huang
  > Mail: sudoku.huang@gmail.com 
  > Created Time: Thu 17 Dec 2015 08:57:18 PM CST
 ************************************************************************/

#include "string.h"

namespace std 
{
    string::string(void)  : len(0), pbuf(NULL)
    {
    }

    string::string(const char * lhs) : len(0), pbuf(NULL)
    {
#if defined(MINI_DEBUG)
        printf("%s:%s:%d, %s\n", __FILE__, __func__, __LINE__, lhs);
        *this = lhs;
        printf("%s:%s:%d, this:%d\n", __FILE__, __func__, __LINE__, (int)this);
#else
        *this = lhs;
#endif
    }

    string::string(const string& lhs) : len(0), pbuf(NULL)
    {
        * this = lhs;
    }

    string::~string(void)
    {
#if defined(MINI_DEBUG)
        printf("%s:%s:%d\n", __FILE__, __func__, __LINE__);
#endif
        if (pbuf != NULL) {
            delete [] pbuf;
            pbuf = NULL;
        }            
        len = 0;
    }

    string & string::operator=(const string& lhs)
    {
        if (&lhs == this) {
            return * this;
        }

        this->~string();
        len = lhs.len;
        pbuf = strcpy(new char[len + 1], lhs.pbuf);
        return * this;
    }

    string & string::operator=(const char * lhs)
    {
#if defined(MINI_DEBUG)
        printf("%s:%s:%d, %s\n", __FILE__, __func__, __LINE__, lhs);
#endif
        this->~string();
        len = strlen(lhs);      
        pbuf = strcpy(new char[len + 1], lhs);
#if defined(MINI_DEBUG)
        printf("%s:%s:%d, addr:%d, %s\n", __FILE__, __func__, __LINE__, (int)pbuf, pbuf);
        printf("%s:%s:%d, this:%d \n", __FILE__, __func__, __LINE__, (int)this);
#endif
        return *this;
    }

    const char & string::operator[](unsigned idx) const
    {
        return pbuf[idx];
    }

    const char * string::c_str() const
    {
        return pbuf;
    }

    unsigned string::length() const
    {
        return len;        
    }

    unsigned string::size() const
    {
        return len; 
    }

    ofstream & operator << (ofstream & lhs, const string& rhs)
    {
        return lhs << rhs.c_str();
    }

}
