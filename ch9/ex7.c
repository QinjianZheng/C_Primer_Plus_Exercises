/* 7

编写一个函数，从标准输入中读取字符，直到遇到文件结尾。
程序要报告每个字符是否是字母。
如果是，还要报告该字母在字母表中的数值位置。
例如，c和C在字母表中的位置都是3。
合并一个函数，以一个字符作为参数，如果该字符是一个字母则返回一个数值位置，否则返回-1。

*/


#include <stdio.h>
#include <ctype.h>

int indexLetter(char);

int main(int argc, char const *argv[])
{
    char ch;
    int index;
    while((ch = getchar()) != EOF) {
        if((index = indexLetter(ch)) > 0) {
            printf("%c is a letter with index of %d\n", ch, index);
        } else {
            printf("%c is not a letter.\n", ch);
        }
    }
    return 0;
}

int indexLetter(char ch) {
    int index = -1;
    if(ch >= 'a' && ch <= 'z') {
        index = ch - 'a' + 1;
    } else if(ch >= 'A' && ch <= 'Z') {
        index = ch - 'A' + 1;
    }
    return index;
}
