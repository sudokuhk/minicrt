/*************************************************************************
    > File Name: test.c
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Thu 17 Dec 2015 06:14:14 PM CST
 ************************************************************************/

#include "minicrt.h"

int main(int argc, char * argv[])
{
    int i ;
    printf("hello, world![%d]\n", argc);
    for (i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    } 
    return 0;
}

