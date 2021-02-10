/* 14
以变长数组作为函数形参，完成编程练习13。

*/

/* 13

编写一个程序，提示用户输入3组数，每组数包含5个double类型的数
 (假设用户都正确地响应，不会输入非数值数据)。
 该程序应完成下列任务。 
 a.把用户输入的数据储存在3×5的数组中 
 b.计算每组(5个)数据的平均值 
 c.计算所有数据的平均值 
 d.找出这15个数据中的最大值 
 e.打印结果
每个任务都要用单独的函数来完成(使用传统C处理数组的方式)。
完成任务b，要编写一个计算并返回一维数组平均值的函数，利用循环调用该函数3次。
对于处理其他任务的函数，应该把整个数组作为参数，
完成任务c 和d的函数应把结果返回主调函数。
*/

#include <stdio.h>
#define ROWS       3
#define SIZE       5

char getChoice(void);
void setValue(int, int, double [*][*]);
double calMean(int, double[]);
double max2DArray(int, int, double [*][*]);
void print2DArray(int, int, double [*][*]);

int main(int argc, char const *argv[])
{
    char ch;
    double sum;
    double array[ROWS][SIZE];
    while((ch = getChoice()) != 'q') {
        switch (ch)
        {
        case 'a':
            setValue(ROWS, SIZE, array);
            break;
        case 'b':
            printf("means:\n");
            for(int i = 0; i < ROWS; i++) {
                printf("\tarray %d: %.2lf\n", i+1, calMean(SIZE, array[i]));
            }    
            break;
        case 'c':
            sum = 0.0;
            printf("total mean:\n");
            for(int i = 0; i < ROWS; i++) {
                sum += calMean(SIZE, array[i]);
            }
            printf(" %.2lf\n", sum/ROWS);
            break;
        case 'd':
            printf("max value: %.2lf\n", max2DArray(ROWS, SIZE, array));
            break;
        case 'e':
            print2DArray(ROWS, SIZE, array);
            break;
        default:
            printf("Incorrect input...\n");
            break;
        }
    }
    return 0;
}


char getChoice(void) {
    printf("请输入命令\n");
    printf("a.把用户输入的数据储存在3×5的数组中\n");
    printf("b.计算每组(5个)数据的平均值\n");
    printf("c.计算所有数据的平均值\n");
    printf("d.找出这15个数据中的最大值\n"); 
    printf("e.打印结果\n");
    printf("q.结束任务\n");
    char ch;
    
    while((ch = getchar()) == '\n')
        continue;

    return ch;
}
void setValue(int row, int col, double array[row][col]) {
    double input;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%lf", &input);
            array[i][j] = input;
        }
    }
}
double calMean(int n, double array[]) {
    double sum = 0.0;
    for(int i = 0; i < n; i++) {
        sum += array[i];
    }
    return (sum / n);
}
double max2DArray(int row, int col, double array[row][col]) {
    double max = array[0][0];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    return max;
}

void print2DArray(int row, int col, double array[row][col])  {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%.2lf ", array[i][j]);
        }
        putchar('\n');
    }
}