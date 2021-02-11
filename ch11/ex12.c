/* 12
编写一个程序，读取输入，直至读到 EOF，
报告读入的单词数、大写字母数、小写字母数、标点符号数和数字字符数。
使用ctype.h头文件中的 函数。

*/ 

#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char ch;
    int uppercase = 0;
    int lowercase = 0;
    int punctuation = 0;
    int number = 0;
    while((ch = getchar()) != EOF) {
        if(isupper(ch)) {
            uppercase ++;
        } else if(islower(ch)) {
            lowercase ++;
        } else if(ispunct(ch)) {
            punctuation ++;
        } else if(isnumber(ch)) {
            number ++;
        }
    }
    printf("uppercase letter: %d\n", uppercase);
    printf("lowercase letter: %d\n", lowercase);
    printf("punctuation: %d\n", punctuation);
    printf("number: %d\n", number);
    return 0;
}

