/* 6

修改程序清单8.8中的get_first()函数，
让该函数返回读取的第1个非空白字符，并在一个简单的程序中测试。
*/

#include <stdio.h>
char get_first(void);


int main(int argc, char const *argv[])
{
    char ch;
    ch = get_first();
    printf("%c\n", ch);
    return 0;
}

char get_first(void) {
    int ch;
    while((ch = getchar()) == ' ' ) {
        continue;
    }
        
    return ch;
}