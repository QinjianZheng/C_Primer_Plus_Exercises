/* 13

用变长数组(VLA)代替标准数组，完成编程练习12。
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUMBER_CHAR 10

int main(int argc, char const *argv[])
{
    char ch[NUMBER_CHAR] = {' ', '`', '.', '^', ',', ':', '~', '"', '<', '!'};
    const int row = 20;
    const int col = 30;
    int arr[row][col];
    char line[col+3];
    FILE *fp = fopen("ex12data", "r");
    assert(fp != NULL);
    int i = 0, j = 0;
    char *p;
    while(fgets(line, col+3, fp) != NULL) {
        p = line;

        while(*p != '\0' && j < col) {

            arr[i][j] = *p - '0';
            p++;
            j++;
        }
        i++;
        j = 0;

    }
    FILE *out = fopen("char_draw2", "w");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            fprintf(out, "%c", ch[arr[i][j]]);
        }
        fputc('\n', out);
    }
    return 0;
}


