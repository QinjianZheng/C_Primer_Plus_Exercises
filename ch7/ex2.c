/* 2
编写一个程序读取输入，读到#字符停止。
程序要打印每个输入的字符以及对应的ASCII码(十进制)。
一行打印8个字符。
建议:使用字符计数和求模运算符(%)在每8个循环周期时打印一个换行符。

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ret;
    int count = 0;
    while((ret = getchar()) != '#') {
        
            count ++;
            if(ret == '\n') {
                printf("'\\n': %03d", ret);
            } else if(ret == '\t') {
                printf("'\\t': %03d", ret);
            } else {
                printf("%c: %03d", ret, ret);
            }

            if(count % 8 == 0) {
                printf("\n");
            }
        

    }
    return 0;
}