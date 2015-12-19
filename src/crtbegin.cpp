/*************************************************************************
    > File Name: crtbegin.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Thu 17 Dec 2015 08:34:14 PM CST
 ************************************************************************/

#if defined(MINI_DEBUG)
#include "minicrt.h"
#endif

typedef void (* ctor_func)(void);

#if defined(MINI_DEBUG)
void at_crtbegin()
{
    printf("%s:%s:%d\n", __FILE__, __func__, __LINE__);
}

ctor_func ctors_begin[2] __attribute__((section(".ctors"))) =
{
    (ctor_func) -1,
    (ctor_func) at_crtbegin,
};

void run_hooks()
{
    const ctor_func * list = ctors_begin;

    printf("%s:%s:%d, addr:%d\n", __FILE__, __func__, __LINE__, (int) *list);
    while ((int) * ++ list != -1) {
        printf("%s:%s:%d\n", __FILE__, __func__, __LINE__);
        (**list)();
    }
}
#else
ctor_func ctors_begin[1] __attribute__((section(".ctors"))) =
{
    (ctor_func) -1,
};

void run_hooks()
{
    const ctor_func * list = ctors_begin;

    while ((int) * ++ list != -1) {
        (**list)();
    }
}
#endif
