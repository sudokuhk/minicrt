/*************************************************************************
    > File Name: ctors.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Thu 17 Dec 2015 08:33:05 PM CST
 ************************************************************************/

typedef void (* init_func)(void);

void run_hooks();

extern "C" {
    void do_global_ctors() 
    {
        run_hooks();
    }
}
