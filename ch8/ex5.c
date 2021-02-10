/* 5
修改程序清单8.4的猜数字程序，使用更智能的猜测策略。
例如，程序最初猜50，询问用户是猜大了、猜小了还是猜对了。
如果猜小了，那么下一 次猜测的值应是50和100中值，也就是75。
如果这次猜大了，那么下一次猜 测的值应是50和75的中值，等等。
使用二分查找(binary search)策略，如 果用户没有欺骗程序，那么程序很快就会猜到正确的答案。

*/

#include <stdio.h>
int main(int argc, char const *argv[])
{
    int guess = 50;
    int low = 1;
    int high = 100;
    char ch;
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and  with");
    printf("\na b if it is too big and a s if is too small.\n"); 
    printf("Uh...is your number %d?\n", guess);
    while((ch = getchar()) != 'y') {
        getchar();
        switch (ch)
        {
        case 'b':
            low = guess;
            guess = (high + low) / 2;
            break;
        case 's':
            high = guess;
            guess = (high + low) / 2;
            break;
        default:
            printf("incorrect input, try again\n");
            break;
        }
        printf("Uh...is your number %d?\n", guess);
    }

    printf("I knew I could do it!\n");
    return 0;
}
