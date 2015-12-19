/*************************************************************************
    > File Name: atexit.c
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Thu 17 Dec 2015 08:40:08 PM CST
 ************************************************************************/

#include "minicrt.h"

typedef struct _func_node
{
    atexit_func_t func;
    void * arg;
    int is_xca;
    struct _func_node * next;
} func_node;

static func_node * atexit_list = NULL;

int register_atexit(atexit_func_t func, void * arg, int is_xca)
{
    func_node * node;
    if (func == NULL) {
        return -1;
    }

    node = (func_node *)malloc(sizeof(func_node));
    if (node == NULL) {
        return -1;
    }

    node->func = func;
    node->arg  = arg;
    node->is_xca = is_xca;
    node->next = atexit_list;
    atexit_list = node;

    return 0;
}

typedef void (*cxa_func_t)(void *);

int __cxa_atexit(cxa_func_t func, void * arg, void * unused)
{
    return register_atexit((atexit_func_t)func, arg, 1);
}

int atexit(atexit_func_t func)
{
    return register_atexit(func, NULL, 0);
}

void mini_crt_call_exit_routine(void)
{
    func_node * p = atexit_list;
    func_node * tmp = NULL;

    while (p != NULL) {
        if (p->is_xca) {
            ((cxa_func_t)p->func)(p->arg);
        } else {
            p->func();
        }
        tmp = p;
        p = p->next;        
        free(tmp);
    }
    atexit_list = NULL;
}
