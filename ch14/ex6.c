/* 6
一个文本文件中保存着一个垒球队的信息。
每行数据都是这样排列: 
4 Jessie Joybat 5 2 1 1
第1项是球员号，为方便起见，其范围是0~18。
第2项是球员的名。第3项是球员的姓。名和姓都是一个单词。
第4项是官方统计的球员上场次数。 
接着3项分别是击中数、走垒数和打点(RBI)。
文件可能包含多场比赛的数据，所以同一位球员可能有多行数据，
而且同一位球员的多行数据之间可能有其他球员的数据。
编写一个程序，把数据储存到一个结构数组中。
该结构中的成员要分别表示球员的名、姓、上场次数、击中数、走垒数、打点和安打率(稍后计算)。
可以使用球员号作为数组的索引。
该程序要读到文件结尾，并统计每位球员的各项累计总和。世界棒球统计与之相关。
例如，一次走垒和触垒中的失误不计入上场次数，但是可能产生一个RBI。
但是该程序要做的是像下面描述的一样读取和处理数据文件，不会关心数据的实际含义。
要实现这些功能，最简单的方法是把结构的内容都初始化为零，
把文件中的数据读入临时变量中，然后将其加入相应的结构中。
程序读完文件后，应计算每位球员的安打率，并把计算结果储存到结构的相应成员中。
计算安打率是用球员的累计击中数除以上场累计次数。这是一个浮点数计算。
最后，程序结合整个球队的统计数据，一行显示一位球员的累计数据
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMESIZE    12
#define NUM_OF_PLAYERS   19
#define MAX_LINE    100
#define WORD_SIZE   12
typedef struct playerT {
    int id;
    char firstname[NAMESIZE];
    char lastname[NAMESIZE];
    int numOfGamePlayed;
    int hitCount;
    int walkCount;
    int RBI;
    float battingAverage;
} Player;

void getInfo(FILE *, Player *, int);

void printPlayerInfo(Player);

int main(int argc, char const *argv[])
{
    int i;
    Player players[NUM_OF_PLAYERS];
    // 初始化数据
    for(i = 0; i < NUM_OF_PLAYERS; i++) {
        players[i].id = i;
        players[i].numOfGamePlayed = 0;
        players[i].hitCount = 0;
        players[i].walkCount = 0;
        players[i].RBI = 0;
        players[i].battingAverage = 0;
    }

    FILE *fp = fopen("ex6data", "r");
    if(fp == NULL) {
        fprintf(stderr, "open file failed.\n");
        exit(1);
    }
#if 0
    char line[MAX_LINE];
    char *token;
    char delim[2] = " ";
    int id;
    while(fgets(line, MAX_LINE, fp) != NULL) {
        token = strtok(line, delim);
        id = atoi(token);
        int count = 0;
        while (token != NULL) {
            
            switch (count)
            {
            case 1:
                strcpy(players[id].firstname, token);
                break;
            case 2:
                strcpy(players[id].lastname, token);
                break;
            case 3:
                players[id].numOfGamePlayed += atoi(token);
                break;
            case 4:
                players[id].hitCount += atoi(token);
                break;
            case 5:
                players[id].walkCount += atoi(token);
                break;
            case 6:
                players[id].RBI += atoi(token);
            default:
                break;
            }
            
            token = strtok(NULL, delim); 
            count ++;
        }
    }
#endif
    getInfo(fp, players, NUM_OF_PLAYERS);
    printf("id    firstname     lastname # played hit walk RBI batting average\n");
    for(i = 0; i < NUM_OF_PLAYERS; i++) {
        if(players[i].numOfGamePlayed != 0) {
            players[i].battingAverage = 1.0 * players[i].hitCount / players[i].numOfGamePlayed;
            printPlayerInfo(players[i]);
        }
    }
    
    return 0;
}

void printPlayerInfo(Player p) {
    printf("%2d %12s %12s %7d %4d %4d %3d %5.2f\n", p.id, p.firstname, p.lastname, 
                                             p.numOfGamePlayed, p.hitCount, 
                                             p.walkCount, p.RBI, p.battingAverage);
}

void getInfo(FILE *fp, Player *players, int n) {
    int id;
    char firstname[NAMESIZE];
    char lastname[NAMESIZE];
    int numOfGamePlayed;
    int hitCount;
    int walkCount;
    int RBI;
    while(fscanf(fp, "%d %s %s %d %d %d %d", &id, firstname, lastname, 
                &numOfGamePlayed, &hitCount, &walkCount, &RBI) == 7) {
        strcpy(players[id].firstname, firstname);
        strcpy(players[id].lastname, lastname);
        players[id].numOfGamePlayed += numOfGamePlayed;
        players[id].hitCount += hitCount;
        players[id].walkCount += walkCount;
        players[id].RBI += RBI;
    }
}