/* 10

编写一个程序，通过一个函数指针数组实现菜单。
例如，选择菜单中的a，将激活由该数组第1个元素指向的函数。

*/ 

#include <stdio.h>

void printFirst(void) {
    printf("First!\n");
}
void printSecond(void) {
    printf("Second!\n");
}
void printThird(void) {
    printf("Third!\n");
}

void showMenu(void);

int main(int argc, char const *argv[])
{
    void (*functions[3]) (void);
    functions[0] = printFirst;
    functions[1] = printSecond;
    functions[2] = printThird;
    char ch;
    showMenu();
    printf("To choose a function, enter the letter command.\n");
    printf("Press [q] to stop\n");
    while((ch = getchar()) != 'q') {
        switch (ch)
        {
        case 'a':
            functions[0]();
            break;
        case 'b':
            functions[1]();
            break;
        case 'c':
            functions[2]();
            break;
        default:
            printf("Incorrect command, try again.\n");
            break;
        }
        showMenu();
        while(getchar() != '\n') continue;
    }
    return 0;
}
void showMenu(void) {
    printf("To choose a function, enter its letter label:\n");
    printf("a) print \"First\"\n");
    printf("b) print \"Second\"\n");
    printf("c) print \"Third\"\n");
    printf("q) Quit\n");
}