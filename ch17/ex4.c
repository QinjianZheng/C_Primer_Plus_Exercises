/* 4

重写mall.c(程序清单17.7)，用两个队列模拟两个摊位。

*/ 

// mall.c -- 使用 Queue 接口
// 和 queue.c 一起编译

#include <stdio.h>
#include <stdlib.h>       // 提供 rand() 和 srand() 的原型 
#include <time.h>         // 提供 time() 的原型
#include "queue.h"        // 更改 Item 的 typedef 
#define MIN_PER_HR 60.0
bool newcustomer(double x);   // 是否有新顾客到来?
Item customertime(long when);  // 设置顾客参数

int main(void) {
    Queue lines[2];
    Item temp;          // 新的顾客数据
    int hours;          // 模拟的小时数
    int perhour;         // 每小时平均多少位顾客
    long cycle, cyclelimit;   // 循环计数器、计数器的上限
    long turnaways = 0;     // 因队列已满被拒的顾客数量
    long customers = 0;     // 加入队列的顾客数量
    long served_l1 = 0;       // 在模拟期间咨询过Sigmund的顾客数量 first line
    long served_l2 = 0;         // second line
    long sum_line = 0;      // 累计的队列总长
    int wait_time_l1 = 0;      // 从当前到Sigmund空闲所需的时间 first line
    int wait_time_l2 = 0;       // second line
    double min_per_cust;    // 顾客到来的平均时间
    long line_wait_l1 = 0;     // 队列累计的等待时间  first line
    long line_wait_l2 = 0;      // second line
    int whichLine;           // randomly choose a line
    InitializeQueue(&lines[0]);
    InitializeQueue(&lines[1]);
    srand((unsigned int) time(0)); // rand() 随机初始化 
    puts("Case Study: Sigmund Lander's Advice Booth"); 
    puts("Enter the number of simulation hours:"); 
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours; 
    puts("Enter the average number of customers per hour:"); 
    scanf("%d", &perhour); 
    min_per_cust = MIN_PER_HR / perhour; 
    for (cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if (QueueIsFull(&lines[0]) && QueueIsFull(&lines[1]))
                turnaways++;
            else {
                customers++;
                temp = customertime(cycle);
                if(QueueIsFull(&lines[0])) {
                    EnQueue(temp, &lines[1]);
                } else if(QueueIsFull(&lines[1])) {
                    EnQueue(temp, &lines[0]);
                } else {
                    whichLine = rand() % 2;
                    EnQueue(temp, &lines[whichLine]);
                }

            }
        } 
        if (wait_time_l1 <= 0 && !QueueIsEmpty(&lines[0])) {
            DeQueue(&temp, &lines[0]); 
            wait_time_l1 = temp.processtime; 
            line_wait_l1 += cycle - temp.arrive;
            served_l1++;
        }
        if (wait_time_l2 <= 0 && !QueueIsEmpty(&lines[1])) {
            DeQueue(&temp, &lines[1]); 
            wait_time_l2 = temp.processtime; 
            line_wait_l2 += cycle - temp.arrive;
            served_l2++;
        }
        if (wait_time_l1 > 0)
            wait_time_l1--;
        if (wait_time_l2 > 0)
            wait_time_l2--;
        sum_line += QueueItemCount(&lines[0]);
        sum_line += QueueItemCount(&lines[1]);
    }
    if (customers > 0) {
        printf("customers accepted: %ld\n", customers);
        printf("customers served: %ld\n", served_l1 + served_l2); 
        printf("turnaways: %ld\n", turnaways); 
        printf("average queue size: %.2f\n", (double) sum_line / cyclelimit); 
        printf("average wait time: %.2f minutes\n", 
            (((double) line_wait_l1 / served_l1) + ((double) line_wait_l2/ served_l2 ))/2 );
    } else
        puts("No customers!"); 
    EmptyTheQueue(&lines[0]);
    EmptyTheQueue(&lines[1]);
    puts("Bye!");
    return 0;
}
// x是顾客到来的平均时间(单位:分钟) // 如果1分钟内有顾客到来，则返回true 
bool newcustomer(double x) {
    if (rand() * x / RAND_MAX < 1) 
        return true;
    else
        return false;
}
// when是顾客到来的时间
// 该函数返回一个Item结构，该顾客到达的时间设置为when， 
// 咨询时间设置为1~3的随机值 
Item customertime(long when) { 
    Item cust;
    cust.processtime = rand() % 3 + 1; 
    cust.arrive = when;
    return cust;
}