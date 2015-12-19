/*************************************************************************
    > File Name: init.c
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: 2015-12-18 20:02:48
 ************************************************************************/

#include "minicrt.h"

typedef void (* init_func)(void);

init_func init_array_begin[1] __attribute__((section(".init_array"))) = 
{
    (init_func)-1,
};

void run_init_array(void)
{
    const init_func * list = init_array_begin;
    while ((int)* ++list  != -1) {
        printf("%s:%d::%d, addr:%d\n", __FILE__, __func__, __LINE__, (int)*list);
        (**list)();
    } 
}
