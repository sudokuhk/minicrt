/*************************************************************************
    > File Name: crtend.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Thu 17 Dec 2015 08:36:25 PM CST
 ************************************************************************/

typedef void (* ctor_func)(void);

ctor_func crt_end[1] __attribute__((section(".ctors"))) = 
{
    (ctor_func)(-1)
};
