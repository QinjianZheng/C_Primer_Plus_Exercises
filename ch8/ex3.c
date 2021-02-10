/*3

编写一个程序，在遇到EOF之前，把输入作为字符流读取。
该程序要报告输入中的大写字母和小写字母的个数。
假设大小写字母数值是连续的。或者使用ctype.h库中合适的分类函数更方便。
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char ch;
    int lowerCount = 0, upperCount = 0;
    int others = 0;
    while((ch = getchar()) != EOF) {
        if(islower(ch)) {
            lowerCount ++;
        } else if(isupper(ch)) {
            upperCount ++;
        } else {
            others ++;
        }
    }
    printf("lower: %d | uppper: %d | others: %d\n", lowerCount, upperCount, others);
    printf("total: %d\n", lowerCount + upperCount + others);
    return 0;
}
