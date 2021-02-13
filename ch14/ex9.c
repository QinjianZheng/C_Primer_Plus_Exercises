/* 9

巨人航空公司(编程练习 8)需要另一架飞机(容量相同)，
每天飞 4 班(航班 102、311、444 和519)。
把程序扩展为可以处理4个航班。
用一个顶层菜单提供航班选择和退出。
选择一个特定航班，就会出现和编程练习8类似的菜单。
但是该菜单要添加一个新选项:确认座位分配。
而且，菜单中的退出是返回顶层菜单。
每次显示都要指明当前正在处理的航班号。
另外，座位分配显示要指明确认状态。

*/ 

#include <stdio.h>
#include <string.h>
#define NUM_OF_FLIGHTS 4
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

typedef struct flightT {
    int id;
    Plane plane;
} Flight;

typedef int Cmp (Seat *, Seat *);
int nameCmp(Seat *, Seat *);
void showMenu(void);
void showSeatInfo(Seat);
void showListOfSeats(Plane, int);
void sortByName(Plane *, int, Cmp *);
char * s_gets(char * st, int n);
void assignSeat(Plane *);
void deleteAssign(Plane *, int);
void initializePlane(Plane *, int);
void dealAssign(Plane *, int n, int flightID);
void showTopMenu(void);
void showSeatStatus(Plane p, int n);

int main(int argc, char const *argv[])
{
    Flight flights[NUM_OF_FLIGHTS];
    
    int flightIDs[NUM_OF_FLIGHTS] = {102, 311, 444, 519};
    char ch;
    int i;
    int id;
    for(i = 0; i < NUM_OF_FLIGHTS; i++) {
        flights[i].id = flightIDs[i];
        initializePlane(&(flights[i].plane), NUM_OF_SEATS);
    }


    showTopMenu();
    while((ch = getchar()) != 'q') {

        switch (ch)
        {
        case 'a':
            printf("List of flights: \n");
            for(i = 0; i < NUM_OF_FLIGHTS; i++) {
                printf("%d ", flights[i].id);
            }
            putchar('\n');
            break;
        case 'b':
            puts("Please choose a flight id.");
            scanf("%d", &id);
            while (getchar() != '\n')
                continue;   // 清理输入行
            int index = -1;
            for(i = 0; i < NUM_OF_FLIGHTS; i++) {
                if(flights[i].id == id) {
                    index = i;
                    dealAssign(&(flights[index].plane), NUM_OF_SEATS, id);
                    break;
                }
            }
            if(index == -1) {
                printf("Sorry, there is no flight %d\n", id);
            }
            break;
        default:
            printf("Incorrect command, try again.\n");
            break;
        }
        while (getchar() != '\n') 
            continue;     /* 清理输入行 */ 
        showTopMenu();
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
    printf("f) Check seat status.\n");
    printf("q) Return to top menu\n");
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
void showTopMenu(void) {
    printf("To choose a function, enter its letter label:\n");
    printf("a) Show list of flights\n");
    printf("b) Choose a flight\n");
    printf("q) Quit\n");
}


void initializePlane(Plane *p, int n) {
    p->numOfEmptySeats = n;
    for(int i = 0; i < n; i++) {
        p->seats[i].id = i;
        p->seats[i].reserved = 0;
        p->seats[i].firstname[0] = '\0';
        p->seats[i].lastname[0] = '\0';
    }
}

void dealAssign(Plane *p, int n, int flightID) {
    char ch;
    printf("Current flight id: %d\n", flightID);
    showMenu();
    while((ch = getchar()) != 'q') {
        switch (ch)
        {
        case 'a':
            printf("Number of empty seats: %d\n", p->numOfEmptySeats);
            break;
        case 'b':
            printf("Empty seats: ");
            for(int i = 0; i < n; i++) {
                if(p->seats[i].reserved == 0) {
                    printf("%d ", p->seats[i].id);
                }
            }
            putchar('\n');
            break;
        case 'c':
            sortByName(p, n, nameCmp);
            showListOfSeats(*p, n);
            break;
        case 'd':
            assignSeat(p);
            break;
        case 'e':
            deleteAssign(p, n);
            break;
        case 'f':
            showSeatStatus(*p, n);
            break;
        default:
            printf("Incorrect command, try again.\n");
            break;
        }
        while (getchar() != '\n') 
            continue;     /* 清理输入行 */ 
        printf("Current flight id: %d\n", flightID);
        showMenu();
    }
}

void showSeatStatus(Plane p, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", i);
        if(p.seats[i].reserved == 0) {
            printf("Not ");
        }
        printf("Reserved.\n");
    }
}