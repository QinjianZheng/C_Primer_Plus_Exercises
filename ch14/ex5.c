/* 5

编写一个程序满足下面的要求。
a.外部定义一个有两个成员的结构模板name:一个字符串储存名，一个字符串储存姓。
b.外部定义一个有3个成员的结构模板student:
一个name类型的结构， 
一个grade数组储存3个浮点型分数，
一个变量储存3个分数平均数
c.在main()函数中声明一个内含CSIZE(CSIZE = 4)个student类型结构的数组，
并初始化这些结构的名字部分。
用函数执行g、e、f和g中描述的任务。
d.以交互的方式获取每个学生的成绩，提示用户输入学生的姓名和分数。
把分数储存到grade数组相应的结构中。可以在main()函数或其他函数中用循环来完成。
e.计算每个结构的平均分，并把计算后的值赋给合适的成员。 
f.打印每个结构的信息。 
g.打印班级的平均分，即所有结构的数值成员的平均值

*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CSIZE       4
#define NAMESIZE    12
struct nameT {
    char firstname[NAMESIZE];
    char lastname[NAMESIZE];
};
typedef struct studentT {
    struct nameT name;
    float scores[3];
    float average;
} Student;

void setScores(Student *, int, char *, char *);
float calculateAverage(Student);
void printStudentInfo(Student);
void printTotalAverage(Student *, int);

int main(int argc, char const *argv[])
{
    int i;
    Student students[CSIZE];
    char firstname[NAMESIZE];
    char lastname[NAMESIZE];

    for(i = 0; i < CSIZE; i++) {
        snprintf(students[i].name.firstname, NAMESIZE, "stu%d", i+1);
        snprintf(students[i].name.lastname, NAMESIZE, "last%d", i+1);
    }
    for(i = 0; i < CSIZE; i++) {
        printStudentInfo(students[i]);
    }

    for(i = 0; i < CSIZE; i++) {
        printf("Please enter the student name (firstname lastname): ");
        scanf("%s %s", firstname, lastname);
        setScores(students, CSIZE, firstname, lastname);
    }
    for(i = 0; i < CSIZE; i++) {
        students[i].average = calculateAverage(students[i]);
        printStudentInfo(students[i]);
    }
    printTotalAverage(students, CSIZE);
    return 0;
}

void setScores(Student *students, int n, char *firstname, char *lastname) {
    int i;
    for(i = 0; i < n; i++) {
        if(strcmp(students[i].name.firstname, firstname) == 0 && 
            strcmp(students[i].name.lastname, lastname) == 0) {
                printf("Please enter the scores (seperated by space): ");
                scanf("%f %f %f", &students[i].scores[0], 
                                  &students[i].scores[1], 
                                  &students[i].scores[2]);
                break;
            }
    }
    if(i == n) {
        printf("%s %s Not found\n", firstname, lastname);
    }
}
float calculateAverage(Student student) {
    float sum = 0;
    int i;
    for(i = 0; i < 3; i++) {
        sum += student.scores[i];
    }
    return sum/3;
}
void printStudentInfo(Student s) {
    printf("%s %s %.2f %.2f %.2f %.2f\n", s.name.firstname, 
                                  s.name.lastname,
                                  s.scores[0],
                                  s.scores[1],
                                  s.scores[2],
                                  s.average );
}
void printTotalAverage(Student *students, int n) {
    float sum = 0;
    int i;
    for(i = 0; i < n; i++) {
        sum += students[i].average;
    }
    printf("Class average: %.2f\n", sum/n);
}