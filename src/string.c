/*************************************************************************
    > File Name: string.c
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Thu 17 Dec 2015 05:28:01 PM CST
 ************************************************************************/

#include "minicrt.h"

char * itoa(int n, char * str, int radix)
{
    char digit[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char * p = str;
    char * head = str;
    int neg = 0;
       
    if (p == NULL || radix < 2 || radix > 36) {
        return p;
    }
        
    if (radix != 10 && n < 0) {
        return p;
    }

    if (n == 0) {
        *p ++ = '0';
        *p = 0;
        return p;
    }

    if (radix == 10 && n < 0) {
        *p ++ = '-';
        n = -n;
        neg = 1;
    }

    while (n) {
        * p++ = digit[n % radix];
        n /= radix;
    }
    *p = 0;

    head = head + neg;
    for (--p; head < p; ++head, --p) {
        char tmp = *head;
        *head = *p;
        *p = tmp;
    }
    return str;
}

int strcmp(const char * src, const char * dst)
{
    unsigned char * p1 = (unsigned char *)src;
    unsigned char * p2 = (unsigned char *)dst;
    unsigned char c1, c2;

    do {
        c1 = (unsigned char) * p1 ++;
        c2 = (unsigned char) * p2 ++;
        if (c1 == '\0' || c2 == '\0') {
            return c1 - c2;
        }
    } while (c1 == c2);

    return c1 - c2;
}

char * strcpy(char * dst, const char * src)
{
    char * pdst = dst;
    const char * psrc = src;

    while (*psrc) {
        * pdst ++ = * psrc ++;
    }
    * pdst = '\0';
    return dst;
}

unsigned strlen(const char * str)
{
    int cnt = 0;
    const char * ptr = str;

    if (str == NULL) {
        return 0;
    }

    while (*ptr ++ != '\0') {
        cnt ++;
    }
    return cnt;
}
