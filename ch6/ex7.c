/* 7
编写一个程序把一个单词读入一个字符数组中，然后倒序打印这个单词。
提示:strlen()函数(第4章介绍过)可用于计算数组最后一个字符的下标。

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *word;
    word = malloc(12);
    printf("Please enter a word: ");
    scanf("%s", word);
    for(int i = strlen(word) - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
    putchar('\n');
    free(word);
    return 0;
}
