/*************************************************************************
    > File Name: new_delete.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Thu 17 Dec 2015 07:53:52 PM CST
 ************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
    void * malloc(unsigned int);
    void free(void *);
#ifdef __cplusplus
}
#endif

#if defined(MINI_DEBUG)
#include "minicrt.h"

void * operator new(unsigned int size)
{
    printf("%s:%s:%d, size:%d\n", __FILE__, __func__, __LINE__, size);
    void * ptr = malloc(size);
    printf("%s:%s:%d, Addr:%d\n", __FILE__, __func__, __LINE__, (int)ptr);
    
    return ptr;
}

void operator delete(void * p)
{
    free(p);
}

void * operator new[](unsigned int size)
{
    return malloc(size);
}

void operator delete[](void * p)
{
    free(p);
}

#else

void * operator new(unsigned int size)
{
    return malloc(size);
}

void operator delete(void * p)
{
    free(p);
}

void * operator new[](unsigned int size)
{
    return malloc(size);
}

void operator delete[](void * p)
{
    free(p);
}

#endif
