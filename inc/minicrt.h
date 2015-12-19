/*************************************************************************
    > File Name: minicrt.h
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Thu 17 Dec 2015 05:25:27 PM CST
 ************************************************************************/

#ifndef __MINI_CRT_H__
#define __MINI_CRT_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#define NULL (0)
#endif

void free(void * ptr);
void * malloc(unsigned size);
static int brk(void * end_data_segment);
int mini_crt_heap_init();

char * itoa(int n, char * str, int radix);
int strcmp(const char * src, const char * dst);
char * strcpy(char * dst, const char * src);
unsigned strlen(const char * str);

typedef int FILE;
#define EOF (-1)

#define stdin   ((FILE *)0)
#define stdout  ((FILE *)1)
#define stderr  ((FILE *)2)

int mini_crt_io_init(void);
FILE * fopen(const char * filename, const char * mode);
int fread(void * buffer, int size, int count, FILE * fp);
int fwrite(const void * buffer, int size, int count, FILE * fp);
int fclose( FILE * fp);
int fseek(FILE * fp, int offset, int set);


int fputc(char c, FILE * fp);
int fputs(const char * str, FILE * fp);
int printf(const char * format, ...);
int fprintf(FILE * fp, const char * format, ...);

void do_global_ctors();
void mini_crt_call_exit_routine();

typedef void (*atexit_func_t)(void);
int atexit(atexit_func_t func);

void run_init_array(void);

#ifdef __cplusplus
}
#endif

#endif
