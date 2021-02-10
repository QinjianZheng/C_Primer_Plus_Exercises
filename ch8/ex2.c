/* 2

编写一个程序，在遇到 EOF 之前，把输入作为字符流读取。
程序要打印每个输入的字符及其相应的ASCII十进制值。
注意，在ASCII序列中，空格字符前面的字符都是非打印字符，要特殊处理这些字符。
如果非打印字符是换行符或制表符，则分别打印\n或\t。
否则，使用控制字符表示法。例如，ASCII的1是Ctrl+A，可显示为^A。
注意，A的ASCII值是Ctrl+A的值加上64。
其他非打印字符也有类似的关系。
除每次遇到换行符打印新的一行之外，每行打印10对值。
(注意:不同的操作系统其控制字符可能不同。)

*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ch;
    int count = 0;
    while((ch = getchar()) != EOF) {
        count ++;
        if(count == 10) {
            printf("\n");
            count = 0;
        }
        if(ch >= 32) {
            printf("\'%c\' - %3d ", ch, ch);
        } else if(ch == '\n') {
            printf("\\n - %3d\n", ch);
        } else if(ch == '\t') {
            printf("\\t - %3d\t", ch);
        } else {
            printf("\'^%c\' - %3d ", ch+64, ch);
        }

    }
    return 0;
}
