/* 12
创建一个文本文件，内含20行，每行30个整数。
这些整数都在0~9之间，用空格分开。
该文件是用数字表示一张图片，0~9表示逐渐增加的灰度。
编写一个程序，把文件中的内容读入一个20×30的int数组中。
一种把这些数字转换为图片的粗略方法是:
该程序使用数组中的值初始化一个20×31 的字符数组，
用值0对应空格字符，1对应点字符，以此类推。
数字越大表示字符所占的空间越大。
例如，用#表示9。
每行的最后一个字符(第31个) 是空字符，
这样该数组包含了20个字符串。
最后，程序显示最终的图片 (即，打印所有的字符串)，
并将结果储存在文本文件中。
例如，下面是开始的数据:
[数据在"ex12data"中]
根据以上描述选择特定的输出字符，最终输出如下:
[一个十字的图片，有点像徽章]
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ex14.h"
#define ROW 20
#define COL 30
#define NUMBER_CHAR 10

int main(int argc, char const *argv[])
{
    char ch[NUMBER_CHAR] = {' ', '`', '.', '^', ',', ':', '~', '"', '<', '!'};
    int arr[ROW][COL];
    char line[COL+3];
    FILE *fp = fopen("ex12data", "r");
    assert(fp != NULL);
    int i = 0, j = 0;
    char *p;
    while(fgets(line, COL+3, fp) != NULL) {
        p = line;

        while(*p != '\0' && j < COL) {

            arr[i][j] = *p - '0';
            p++;
            j++;
        }
        i++;
        j = 0;

    }
    eliminateDistortion(ROW, COL, arr);
    FILE *out = fopen("char_draw", "w");
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            fprintf(out, "%c", ch[arr[i][j]]);
        }
        fputc('\n', out);
    }
    return 0;
}
