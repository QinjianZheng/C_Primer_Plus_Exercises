/* 3
编写一个程序，发出一声警报，然后打印下面的文本: 
Startled by the sudden sound, Sally shouted, 
"By the Great Pumpkin, what was that!"

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    while(i < 10) {
        printf("\a");
        i++;
    }


    printf("Startled by the sudden sound, Sally shouted,\nBy the Great Pumpkin, what was that!\n");
    return 0;
}
