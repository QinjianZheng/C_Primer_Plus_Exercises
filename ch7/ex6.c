/* 6

编写程序读取输入，读到#停止，报告ei出现的次数。
注意
该程序要记录前一个字符和当前字符。
用“Receive your eieio award”这样的输入来测试。

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ret = '0';
    char prev = '0';
    int count = 0;

    while(1) {
        prev = ret;
        ret = getchar();
        if(ret == '#') {
            break;
        }
        printf("%c %c\n", prev, ret);
        if(ret == 'i' && prev == 'e') {
            count ++;
        }

    
    
    }
    printf("count : %d\n", count);
    return 0;
}
