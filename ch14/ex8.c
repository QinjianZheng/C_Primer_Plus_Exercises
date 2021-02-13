/* 8
巨人航空公司的机群由 12 个座位的飞机组成。它每天飞行一个航 班。
根据下面的要求，编写一个座位预订程序。
a.该程序使用一个内含 12 个结构的数组。
每个结构中包括:一个成员 表示座位编号、一个成员表示座位是否已被预订、
一个成员表示预订人的 名、一个成员表示预订人的姓。
b.该程序显示下面的菜单:
To choose a function, enter its letter label:
a) Show number of empty seats
b) Show list of empty seats
c) Show alphabetical list of seats
d) Assign a customer to a seat assignment
e) Delete a seat assignment
f) Quit
c.该程序能成功执行上面给出的菜单。
选择d)和e)要提示用户进行额外 输入，每个选项都能让用户中止输入。
d.执行特定程序后，该程序再次显示菜单，除非用户选择f)。
*/ 

#include <stdio.h>
#include <string.h>
#define NAMESIZE    12
#define NUM_OF_SEATS    12

typedef struct seatT {
    int id;
    int reserved;
    char firstname[NAMESIZE];
    char lastname[NAMESIZE];
} Seat;

typedef struct planeT {
    Seat seats[NUM_OF_SEATS];
    int numOfEmptySeats;
} Plane;
typedef int Cmp (Seat *, Seat *);
int nameCmp(Seat *, Seat *);
void showMenu(void);
void showSeatInfo(Seat);
void showListOfSeats(Plane, int);
void sortByName(Plane *, int, Cmp *);
char * s_gets(char * st, int n);
void assignSeat(Plane *);
void deleteAssign(Plane *, int);

int main(int argc, char const *argv[])
{
    char ch;
    int i;
    Plane plane;
    // 初始化
    plane.numOfEmptySeats = NUM_OF_SEATS;
    for(i = 0; i < NUM_OF_SEATS; i++) {
        plane.seats[i].id = i;
        plane.seats[i].reserved = 0;
        plane.seats[i].firstname[0] = '\0';
        plane.seats[i].lastname[0] = '\0';
    }
    showMenu();
    while((ch = getchar()) != 'f') {
        switch (ch)
        {
        case 'a':
            printf("Number of empty seats: %d\n", plane.numOfEmptySeats);
            break;
        case 'b':
            printf("Empty seats: ");
            for(i = 0; i < NUM_OF_SEATS; i++) {
                if(plane.seats[i].reserved == 0) {
                    printf("%d ", plane.seats[i].id);
                }
            }
            putchar('\n');
            break;
        case 'c':
            sortByName(&plane, NUM_OF_SEATS, nameCmp);
            showListOfSeats(plane, NUM_OF_SEATS);
            break;
        case 'd':
            assignSeat(&plane);
            break;
        case 'e':
            deleteAssign(&plane, NUM_OF_SEATS);
            break;
        default:
            printf("Incorrect command, try again.\n");
            break;
        }
        while (getchar() != '\n') 
            continue;     /* 清理输入行 */ 
        showMenu();
    }
    return 0;
}

void showMenu(void) {
    printf("To choose a function, enter its letter label:\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Quit\n");
}

void showSeatInfo(Seat s) {
    printf("%d %12s %12s\n", s.id, s.firstname, s.lastname);
}

void showListOfSeats(Plane p, int n) {
    if(p.numOfEmptySeats < n) {
        printf("id    firstname    lastname\n");
        for(int i = 0; i < n; i++) {
            if(p.seats[i].reserved == 1) {
                showSeatInfo(p.seats[i]);
            }
        }
    }

}

int nameCmp(Seat *s1, Seat *s2) {
    return strcmp(s1->firstname, s2->firstname);
}

void sortByName(Plane *p, int n, Cmp *cmp) {
    int i, j;
    Seat temp;
    for(i = 1; i < n; i++) {
        temp = (*p).seats[i];
        j = i - 1;
        while(j >= 0 && cmp(&(*p).seats[j], &temp) > 0) {
            (*p).seats[j+1] = (*p).seats[j];
            j--;
        }
        (*p).seats[j+1] = temp;
    }
}

char * s_gets(char * st, int n) {
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');  // 查找换行符
        if (find)       // 如果地址不是 NULL， 
            *find = '\0';     // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;   // 清理输入行
    }
    return ret_val;
}

void assignSeat(Plane *p) {
    int id;

    puts("Please enter the seat id.");
    puts("Press [q] to stop.");
    while((p->numOfEmptySeats > 0) && scanf("%d", &id) == 1) {
        while (getchar() != '\n') 
            continue;     /* 清理输入行 */ 
        if(p->seats[id].reserved == 1) {
            printf("Sorry, seat %d is taken.\n", id);
        } else {
            puts("Please enter your firstname.");
            s_gets(p->seats[id].firstname, NAMESIZE);
            puts("Please enter your lastname.");
            s_gets(p->seats[id].lastname, NAMESIZE);
            p->seats[id].reserved = 1;
            p->numOfEmptySeats --;
        }
        if(p->numOfEmptySeats > 0) 
            puts("Please enter next seat id.");
    }
}

void deleteAssign(Plane *p, int n) {
    int id;
    if(p->numOfEmptySeats < n) {
        puts("Please enter the seat id you want to delete.");
        puts("Press [q] to stop.");
        while((p->numOfEmptySeats < n) && scanf("%d", &id) == 1) {
            if(p->seats[id].reserved == 0) {
                printf("Sorry, seat %d is not taken.\n", id);
            } else {
                printf("Delete seat %d assignment.\n", id);
                p->seats[id].firstname[0] = '\0';
                p->seats[id].lastname[0] = '\0';
                p->seats[id].reserved = 0;
                p->numOfEmptySeats ++;
            }
            if(p->numOfEmptySeats < n) 
                puts("Please enter next seat id.");
            else
                puts("There is no assignment in the plane.");
        }
    } else
        puts("There is no assignment in the plane.");
    
}