/* 4

编写一个程序，创建一个有两个成员的结构模板:
a.第1个成员是社会保险号，第2个成员是一个有3个成员的结构，
第1个成员代表名，第2个成员代表中间名，第3个成员表示姓。
创建并初始化一个内含5个该类型结构的数组。
该程序以下面的格式打印数据:
Dribble, Flossie M. -- 302039823
如果有中间名，只打印它的第1个字母，后面加一个点(.);
如果没有中间名，则不用打印点。
编写一个程序进行打印，把结构数组传递给这个函数。
b.修改a部分，传递结构的值而不是结构的地址。

*/ 

#include <stdio.h>
#define NAMESIZE    12
#define SIZE        5
typedef struct person PersonT;

struct nameT {
    char firstname[NAMESIZE];
    char middlename[NAMESIZE];
    char lastname[NAMESIZE];
};
struct person {
    long SSN;
    struct nameT name;
};

void printPersonsInfo(PersonT *, int);
void printPersonsInfoV2(PersonT);

int main(int argc, char const *argv[])
{
    PersonT persons[SIZE];
    
    for(int i = 0; i < SIZE; i++)  {
        printf("Please enter the social security number: ");
        scanf("%ld", &persons[i].SSN);
        printf("Please enter the firstname: ");
        scanf("%s", persons[i].name.firstname);
        printf("Please enter the middlename: (enter # if you don't have a middlename)");
        scanf("%s", persons[i].name.middlename);
        printf("Please enter the lastname: ");
        scanf("%s", persons[i].name.lastname);
    }
    printPersonsInfo(persons, SIZE);
    
    return 0;
}

void printPersonsInfoV2(PersonT person) {
    printf("%s, %s", person.name.lastname, person.name.firstname);
    if(person.name.middlename[0] != '#') {
        printf(" %c.", person.name.middlename[0]);
    }
    printf(" -- %ld\n", person.SSN);
}

void printPersonsInfo(PersonT *persons, int n) {
    for(int i = 0; i < n; i++) {
        printPersonsInfoV2(persons[i]);
    }
}
