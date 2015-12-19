/*************************************************************************
    > File Name: crtn.c
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: 2015-12-18 20:07:05
 ************************************************************************/

typedef void (* end_func)(void);

end_func init_array_end[1] __attribute__((section(".init_array"))) = 
{
    (end_func)-1,
};
