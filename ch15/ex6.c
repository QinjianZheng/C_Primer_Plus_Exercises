/* 6

设计一个位字段结构以储存下面的信息。 
字体ID:0~255之间的一个数; 
字体大小:0~127之间的一个数; 
对齐:0~2之间的一个数，表示左对齐、居中、右对齐;
加粗:开(1)或闭(0);
斜体:开(1)或闭(0);
在一个程序中使用该结构来打印字体参数，并使用循环菜单来让用户改变参数。
例如，该程序的一个运行示例如下:


该程序要使用按位与运算符(&)和合适的掩码来把字体ID和字体大小信息转换到指定的范围内。

*/ 

#include <stdio.h>

typedef enum alignment {LEFT, CENTER, RIGHT} Alignment;

typedef struct fontT {
    u_int32_t id       : 8;
    u_int32_t size     : 7;
    u_int32_t          : 1;
    u_int32_t align    : 2;
    u_int32_t bold     : 1;
    u_int32_t italy    : 1;
    u_int32_t underline: 1;
    u_int32_t          : 3;
} Font;

void printFontInfo(Font);
void showMenu(void);

int main(int argc, char const *argv[])
{
    Font font = {1, 12, LEFT, 0, 0, 0};
    char align;
    printFontInfo(font);
    showMenu();
    int temp;
    char ch;
    while((ch = getchar()) != 'q') {
        switch (ch)
        {
        case 'f':
            printf("Enter font type (0-255): ");
            if(scanf("%d", &temp) == 1 && temp >= 0 && temp <= 255) {
                font.id = temp;
            } else {
                printf("Incorrect input, font type is not changed.\n");
            }
            
            break;
        case 's':
            printf("Enter font size (0-127): ");
            if(scanf("%d", &temp) == 1 && temp >= 0 && temp <= 127) {
                font.size = temp;
            } else {
                printf("Incorrect input, font size is not changed.\n");
            }
            break;
        case 'a':
            
            printf("Select alignment:\n");
            printf("l) left    c) center    r) right\n");
            while (getchar() != '\n') {
                continue;
            }
            align = getchar();
            switch (align)
            {
            case 'l':
                font.align = LEFT;
                break;
            case 'c':
                font.align = CENTER;
                break;
            case 'r':
                font.align = RIGHT;
                break;
            default:
                printf("incorrect command, alignment is not changed.\n");
                break;
            }
        case 'b':
            
            font.bold = ~font.bold;
            break;
        case 'i':
            font.italy = ~font.italy;
            break;
        case 'u':
            font.underline = ~font.underline;
            break;
        default:
            printf("Incorrect command, try again.\n");
            break;
        }
        while (getchar() != '\n') {
            continue;
        }
        printFontInfo(font);
        showMenu();
    }
    puts("Bye!");
    
    return 0;
}

void showMenu(void) {
    printf("f) change font     s) change size     a) change alignment\n");
    printf("b) toggle bold     i) toggle italic   u) toggle underline\n");
    printf("q) quit\n");
}

void printFontInfo(Font f) {
    printf(" ID  SIZE ALIGNMENT  B    I    U\n");
    printf("%3d %5d ", f.id, f.size);
    switch (f.align)
    {
    case LEFT:
        printf("   left   ");
        break;
    case CENTER:
        printf("   center   ");
        break;
    case RIGHT:
        printf("   right   ");
        break;
    default:
        break;
    }
    printf("%5s", f.bold == 1 ? "on" : "off");
    printf("%5s", f.italy == 1 ? "on" : "off");
    printf("%5s\n", f.underline == 1 ? "on" : "off");
}
