/* 7

编写一个与编程练习 6 功能相同的程序，
使用 unsigned long 类型的变 量储存字体信息，
并且使用按位运算符而不是位成员来管理这些信息。
*/


#include <stdio.h>
#include <limits.h>
#define SIZE    CHAR_BIT * sizeof(int) + 1
#define TYPE_MASK   0xff
#define SIZE_MASK   0x3f
#define ALIGN_MASK  0x30000
#define FORMAT_MASK 0x700000
#define BOLD        0x100000 // 1 << 20
#define ITALY       0x200000 // 1 << 21
#define UNDERLINE   0x400000 // 1 << 22
typedef enum alignment {LEFT, CENTER, RIGHT} Alignment;

typedef struct fontT {
    u_int32_t id       : 8;
    u_int32_t size     : 7;
    u_int32_t          : 1;
    u_int32_t align    : 2;
    u_int32_t          : 2;
    u_int32_t bold     : 1;
    u_int32_t italy    : 1;
    u_int32_t underline: 1;
    u_int32_t          : 1;
} Font;

// 
typedef union viewsU {
    Font stView;
    unsigned long ulView;
} Views;

void printFontInfo(Font);
void printFontInfoUL(unsigned long);
void showMenu(void);
void changeSettings(Font);
void changeSettingsUL(unsigned long);

char * itobs(int n, char *binStr) {
    int i;
    const static int size = SIZE - 1;
    for(i = size - 1; i>=0; i--, n >>= 1) {
        binStr[i] = (01 & n) + '0';
    }
    binStr[size] = '\0';
    return binStr;
}


int main(int argc, char const *argv[])
{
    Views font = {{255, 0, RIGHT, 0, 1, 0}};
    
    changeSettingsUL(font.ulView);
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

void printFontInfoUL(unsigned long ul) {
    char binStr[SIZE];
    printf("%s\n", itobs(ul, binStr));
    printf(" ID  SIZE ALIGNMENT  B    I    U\n");
    printf("%3lu %5lu ", ul & TYPE_MASK, (ul >> 8) & SIZE_MASK);
    switch ((ul & ALIGN_MASK) >> 16)
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
    printf("%5s", (ul & BOLD) == BOLD ? "on" : "off");
    printf("%5s", (ul & ITALY) == ITALY ? "on" : "off");
    printf("%5s\n", (ul & UNDERLINE) == UNDERLINE ? "on" : "off");
}

void changeSettings(Font font) {
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
            printf("l) left    c) center    r) righta\n");
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

}


void changeSettingsUL(unsigned long ul) {
    char align;
    printFontInfoUL(ul);
    showMenu();
    int temp;
    char ch;
    while((ch = getchar()) != 'q') {
        switch (ch)
        {
        case 'f':
            printf("Enter font type (0-255): ");
            if(scanf("%d", &temp) == 1 && temp >= 0 && temp <= 255) {
                ul &= ~TYPE_MASK;
                ul |= temp;
            } else {
                printf("Incorrect input, font type is not changed.\n");
            }
            
            break;
        case 's':
            printf("Enter font size (0-127): ");
            if(scanf("%d", &temp) == 1 && temp >= 0 && temp <= 127) {
                ul &= ~SIZE_MASK;
                ul |= temp;
            } else {
                printf("Incorrect input, font size is not changed.\n");
            }
            break;
        case 'a':
            ul &= ~ALIGN_MASK;
            printf("Select alignment:\n");
            printf("l) left    c) center    r) righta\n");
            while (getchar() != '\n') {
                continue;
            }
            align = getchar();
            switch (align)
            {
            case 'l':
                
                ul |= (LEFT << 16);
                break;
            case 'c':
                ul |= (CENTER << 16);
                break;
            case 'r':
                ul |= (RIGHT << 16);
                break;
            default:
                printf("incorrect command, alignment is not changed.\n");
                break;
            }
            break;
        case 'b':
            
            ul ^= BOLD;
            break;
        case 'i':
            ul ^= ITALY;
            break;
        case 'u':
            ul ^= UNDERLINE;
            break;
        default:
            printf("Incorrect command, try again.\n");
            break;
        }
        while (getchar() != '\n') {
            continue;
        }
        printFontInfoUL(ul);
        showMenu();
    }

}
