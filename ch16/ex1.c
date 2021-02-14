/* 1
开发一个包含你需要的预处理器定义的头文件。
*/ 


#include "ex1.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Person p = {"Xiaoming", 12};
    printf("%s is %d years old.\n", p.name, p.age);
    return 0;
}

