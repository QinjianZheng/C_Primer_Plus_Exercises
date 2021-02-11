#include <stdio.h>
#include "pe12-2a.h"

int mode;
int fallbackMode = 0;
float distance;
float fuel;

void set_mode(int m) {
    mode = m;
}
void get_info(void) {
    switch (mode)
    {
    case 0:
        printf("Enter distance traveled in kilometers: ");
        scanf("%f", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", &fuel);
        break;
    case 1:
        printf("Enter distance traveled in miles: ");
        scanf("%f", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", &fuel);
        break;
    default:
        printf("Invalid mode specified. Mode %d ", fallbackMode);
        if(fallbackMode == 0) {
            printf("(metric) ");
        } else if(fallbackMode == 1) {
            printf("(US) ");
        }
        printf("used.\n");
        mode = fallbackMode;
        get_info();
        break;
    }
    fallbackMode = mode;
}
void show_info(void) {

    if(mode == 0) {
        printf("Fuel consumption is %.2f liters per 100 km.\n", 
                fuel/(distance/100));
    } else {
        printf("Fuel consumption is %.1f miles per gallon.\n", 
                distance/fuel);
    }
}