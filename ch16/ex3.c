/* 3
极坐标用向量的模(即向量的长度)和向量相对x轴逆时针旋转的角度来描述该向量。
直角坐标用向量的x轴和y轴的坐标来描述该向量(见图 16.3)。
编写一个程序，读取向量的模和角度(单位:度)，然后显示x轴和y轴的坐标。相关方程如下:
x = r*cosA 
y = r*sinA

需要一个函数来完成转换，该函数接受一个包含极坐标的结构，
并返回一个包含直角坐标的结构(或返回指向该结构的指针)。

*/ 

#include <stdio.h>
#include <math.h>
#define DEG_TO_RAD ((4 * atan(1))/180)

typedef struct polarT {
    double magnitude;
    double angle;
} Polar;

typedef struct rectT {
    double x;
    double y;
} Rect;

Rect polarToRect(Polar);

int main(int argc, char const *argv[])
{
    Polar input;
    Rect result;
    puts("Enter magnitude and angle for a polar coordinate; enter q to quit:"); 
    while (scanf("%lf %lf", &input.magnitude, &input.angle) == 2) {
        result = polarToRect(input);
        printf("x = %0.2f, y = %0.2f\n", result.x, result.y);
    }
    puts("Bye.");
    return 0;
}
Rect polarToRect(Polar p) {
    Rect res;
    res.x = p.magnitude * cos(DEG_TO_RAD * p.angle);
    res.y = p.magnitude * sin(DEG_TO_RAD * p.angle);
    return res;
}
