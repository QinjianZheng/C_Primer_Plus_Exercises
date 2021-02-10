#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char ch;
    int letter = 0;
    int word = 0;
    while((ch = getchar()) != EOF) {
        if(isalpha(ch)) {
            letter ++;
        }
        if(ispunct(ch) || ch == ' ') {
            word++;
        }

    }
    printf("There are %d words, and %d characters, %.2f C/W\n",
         word, letter, 1.0 * letter/word);
    return 0;
}
