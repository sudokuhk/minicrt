/*************************************************************************
    > File Name: iostream.h
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Thu 17 Dec 2015 08:57:24 PM CST
 ************************************************************************/

#include "iostream.h"

namespace std 
{
    
stdout_stream cout;

stdout_stream::stdout_stream() : ofstream()
{
    fp = stdout;
}

ofstream::ofstream() : fp(0)
{
}

ofstream::ofstream(const char * filename, ofstream::openmode md)
{
    open(filename, md);
}

ofstream::~ofstream()
{
    close();
}

ofstream& ofstream::operator << (char c)
{
    fputc(c, fp);
    return *this;
}

ofstream& ofstream::operator << (int n)
{
    fprintf(fp, "%d", n);
    return *this;
}

ofstream& ofstream::operator << (const char * lhs)
{
    fprintf(fp, "%s", lhs);
    return *this;
}

ofstream& ofstream::operator << (ofstream& (*manip)(ofstream&))
{
    return manip(*this);
}

void ofstream::open(const char * filename, ofstream::openmode md)
{
    char mode[4];
    close();
    
    switch (md) {
        case out | trunc: {
            strcpy(mode, "w");
            break;
        }
        case out | in | trunc : {
            strcpy(mode, "w+");
            break;
        }
        case out | trunc | binary: {
            strcpy(mode, "wb");
            break;
        }
        case out | in | trunc | binary : {
            strcpy(mode, "wb+");
            break;
        }
    }
    fp = fopen(filename, mode);
}

void ofstream::close()
{
    if (fp != NULL && fp != stdin && fp != stdout && fp != stderr) {
        fclose(fp);
        fp = 0;
    }
}

ofstream& ofstream::write(const char * buf, unsigned size)
{
    fwrite(buf, 1, size, fp);
    return * this;
}
  
}
