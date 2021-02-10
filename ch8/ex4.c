/* 4

编写一个程序，在遇到EOF之前，把输入作为字符流读取。
该程序要报告平均每个单词的字母数。
不要把空白统计为单词的字母。
实际上，标点符号也不应该统计，但是现在暂时不同考虑这么多
(如果你比较在意这点，考虑使用ctype.h系列中的ispunct()函数)。
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char ch, prev;
    int chCount = 0;
    int wordCount = 0;
    prev = 'a';
    while((ch = getchar()) != EOF) {
        if(!ispunct(ch)) {
            chCount ++;
            if(ch == ' ' || ch == '\n') {
                if(prev != ' ' && prev != '\n') {
                    wordCount ++;
                }

            }
            prev = ch;
        }


    }
    printf("word count: %d | char count: %d | average ch: %.2f\n", 
            wordCount, chCount, 1.0 * chCount/wordCount);
    return 0;
}
