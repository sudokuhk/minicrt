/*************************************************************************
    > File Name: iostream.h
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Thu 17 Dec 2015 08:57:24 PM CST
 ************************************************************************/

#ifndef __IOSTREAM_H__
#define __IOSTREAM_H__

#include "minicrt.h"

namespace std {
    class ofstream {
        protected:
            FILE * fp;
            ofstream(const ofstream& lhs);
        public:
            enum openmode {
                in      = 1 << 0, 
                out     = 1 << 1, 
                binary  = 1 << 2, 
                trunc   = 1 << 3,
            };
            
            ofstream();
            explicit ofstream(const char * filename, 
                ofstream::openmode md = ofstream::out);
            ~ofstream();
            ofstream& operator << (char c);
            ofstream& operator << (int n);
            ofstream& operator << (const char * lhs);
            ofstream& operator << (ofstream& (*)(ofstream&));
            
            void open(const char * filename, 
                ofstream::openmode md = ofstream::out);
            void close();
            ofstream& write(const char * buf, unsigned size);                    
    };
    
    inline ofstream & endl(ofstream & lhs)
    {
        return lhs << '\n';
    }
    
    class stdout_stream : public ofstream {
        public:
            stdout_stream();                
    };
    
    extern stdout_stream cout;
}

#endif
