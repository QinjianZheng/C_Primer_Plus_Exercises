/* 2

编写一个程序，提示用户输入一个整数，
然后打印从该数到比该数大10的所有整数(例如，用户输入5，则打印5~15的所有整数，包括5和 15)。
要求打印的各值之间用一个空格、制表符或换行符分开。

*/
#include <stdio.h>

int main(int argc, char const *argv[]){
    int num;
    printf("Please enter a number: ");
    scanf("%d", &num);
    int upper_bound = num + 10;
    while(num < upper_bound+1) {
        printf("%d ", num);
        num ++;
    }
    putchar('\n');
    return 0;
}