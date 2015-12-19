/*************************************************************************
    > File Name: test.cpp
    > Author: sudoku.huan
    > Mail: sudoku.huan@gmail.com 
    > Created Time: Thu 17 Dec 2015 09:27:50 PM CST
 ************************************************************************/

#include "iostream.h"
#include "string.h"
#include "minicrt.h"

void exit_fun(void)
{
    printf("%s:%d\n", __func__, __LINE__);
}

const char * t = "12345687654";
std::string str_huang = t;

int main(int arc, char * argv[])
{
    std::string * msg = new std::string("abcd");
    const char * ptr = msg->c_str();

    std::cout << msg->c_str() << std::endl;
    std::cout << "abcd:" << msg->c_str() << ", end" << std::endl;
    std::cout << "abcd:" << msg->c_str() << std::endl;
    std::cout << "pointer:" << ptr << ", end" << std::endl;
    std::cout << "string:" << *msg << std::endl;
    std::cout << t << std::endl;
    delete msg;

    printf("negative:%d\n", -1);
    atexit(exit_fun);

    printf("------------------------------\n");
    std::string sss = t;
    std::cout << sss << std::endl;
    printf("------------------------------\n");
    std::cout << str_huang << std::endl;
    printf("------------------------------\n");

    return 0;
}
