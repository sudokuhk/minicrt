/*************************************************************************
    > File Name: stdio.c
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Thu 17 Dec 2015 05:07:24 PM CST
 ************************************************************************/

#include "minicrt.h"

int mini_crt_io_init(void)
{
    return 1;
}

static int open(const char * pathname, int flag, int mode)
{
    int fd = 0;
    
    int eax, ebx, ecx, edx;
        
    asm("movl %%eax, %0 \n\t"
        "movl %%ebx, %1 \n\t"
        "movl %%ecx, %2 \n\t"
        "movl %%edx, %3 \n\t"
        :"=m"(eax), "=m"(ebx), "=m"(ecx), "=m"(edx));
    
    asm("movl $5, %%eax     \n\t"
        "movl %1, %%ebx     \n\t"
        "movl %2, %%ecx     \n\t"
        "movl %3, %%edx     \n\t"
        "int $0x80          \n\t"
        "movl %%eax, %0     \n\t"
        :"=m"(fd):"m"(pathname), "m"(flag), "m"(mode));

    asm("movl %0, %%eax     \n\t"
        "movl %1, %%ebx     \n\t"
        "movl %2, %%ecx     \n\t"
        "movl %3, %%edx     \n\t"
        ::"m"(eax), "m"(ebx), "m"(ecx), "m"(edx));

    return fd;
}

static int read(int fd, void * buffer, unsigned size)
{
    int ret = 0;
    int eax, ebx, ecx, edx;
        
    asm("movl %%eax, %0 \n\t"
        "movl %%ebx, %1 \n\t"
        "movl %%ecx, %2 \n\t"
        "movl %%edx, %3 \n\t"
        :"=m"(eax), "=m"(ebx), "=m"(ecx), "=m"(edx));
    asm("movl $3, %%eax     \n\t"
        "movl %1, %%ebx     \n\t"
        "movl %2, %%ecx     \n\t"
        "movl %3, %%edx     \n\t"
        "int $0x80          \n\t"
        "movl %%eax, %0     \n\t"
        :"=m"(ret):"m"(fd), "m"(buffer), "m"(size));
    asm("movl %0, %%eax     \n\t"
        "movl %1, %%ebx     \n\t"
        "movl %2, %%ecx     \n\t"
        "movl %3, %%edx     \n\t"
        ::"m"(eax), "m"(ebx), "m"(ecx), "m"(edx));
    return ret;
}

static int write(int fd, const void * buffer, unsigned size)
{
    int ret = 0;
    int eax, ebx, ecx, edx;
        
    asm("movl %%eax, %0 \n\t"
        "movl %%ebx, %1 \n\t"
        "movl %%ecx, %2 \n\t"
        "movl %%edx, %3 \n\t"
        :"=m"(eax), "=m"(ebx), "=m"(ecx), "=m"(edx));
    asm("movl $4, %%eax     \n\t"
        "movl %1, %%ebx     \n\t"
        "movl %2, %%ecx     \n\t"
        "movl %3, %%edx     \n\t"
        "int $0x80          \n\t"
        "movl %%eax, %0     \n\t"
        :"=m"(ret):"m"(fd), "m"(buffer), "m"(size));
    asm("movl %0, %%eax     \n\t"
        "movl %1, %%ebx     \n\t"
        "movl %2, %%ecx     \n\t"
        "movl %3, %%edx     \n\t"
        ::"m"(eax), "m"(ebx), "m"(ecx), "m"(edx));
    return ret;
}

static int close(int fd)
{
    int ret = 0;
    int eax, ebx, ecx, edx;
        
    asm("movl %%eax, %0 \n\t"
        "movl %%ebx, %1 \n\t"
        "movl %%ecx, %2 \n\t"
        "movl %%edx, %3 \n\t"
        :"=m"(eax), "=m"(ebx), "=m"(ecx), "=m"(edx));
    asm("movl $4, %%eax     \n\t"
        "movl %1, %%ebx     \n\t"
        "int $0x80          \n\t"
        "movl %%eax, %0     \n\t"
        :"=m"(ret):"m"(fd));
    asm("movl %0, %%eax     \n\t"
        "movl %1, %%ebx     \n\t"
        "movl %2, %%ecx     \n\t"
        "movl %3, %%edx     \n\t"
        ::"m"(eax), "m"(ebx), "m"(ecx), "m"(edx));
    return ret;
}

static int seek(int fd, int offset, int mode)
{
    int ret = 0;
    int eax, ebx, ecx, edx;
        
    asm("movl %%eax, %0 \n\t"
        "movl %%ebx, %1 \n\t"
        "movl %%ecx, %2 \n\t"
        "movl %%edx, %3 \n\t"
        :"=m"(eax), "=m"(ebx), "=m"(ecx), "=m"(edx));
    asm("movl $19, %%eax     \n\t"
        "movl %1, %%ebx     \n\t"
        "movl %2, %%ecx     \n\t"
        "movl %3, %%edx     \n\t"
        "int $0x80          \n\t"
        "movl %%eax, %0     \n\t"
        :"=m"(ret):"m"(fd), "m"(offset), "m"(mode));
    asm("movl %0, %%eax     \n\t"
        "movl %1, %%ebx     \n\t"
        "movl %2, %%ecx     \n\t"
        "movl %3, %%edx     \n\t"
        ::"m"(eax), "m"(ebx), "m"(ecx), "m"(edx));
    return ret;
}

FILE * fopen(const char * filename, const char * mode)
{
    int fd = -1;
    int flags = 0;
    int access = 00700;
    if (mode == NULL) {
        mode = "r+";
    }

#define O_RDONLY    00
#define O_WRONLY    01
#define O_RDWR      02
#define O_CREAT     0100
#define O_TRUNC     01000
#define O_APPEND    02000

    if (strcmp(mode, "w") == 0) {
        flags |= O_WRONLY | O_CREAT | O_TRUNC;
    }

    if (strcmp(mode, "w+") == 0) {
        flags |= O_WRONLY | O_CREAT | O_TRUNC;
    }

    if (strcmp(mode, "r") == 0) {
        flags |= O_RDONLY;
    }

    if (strcmp(mode, "r+") == 0) {
        flags |= O_RDWR | O_CREAT;
    }

    fd = open(filename, flags, access);
    return (FILE *)fd;
}

int fread(void * buffer, int size, int count, FILE * fp)
{
    if (count * size == 0) {
        return 0;
    }
    return read((int)fp, buffer, size * count);
}

int fwrite(const void * buffer, int size, int count, FILE * fp)
{
    if (count * size == 0) {
        return 0;
    }
    return write((int)fp, buffer, size * count);
}

int fclose( FILE * fp)
{
    return close((int)fp);
}

int fseek(FILE * fp, int offset, int set)
{
    return seek((int)fp, offset, set);
}
