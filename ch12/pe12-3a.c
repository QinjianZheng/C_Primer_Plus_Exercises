#include <stdio.h>
#include "pe12-3a.h"


void get_info(int *modeP, int *fallbackModeP, float *distanceP, float *fuelP) {
    switch (*modeP)
    {
    case 0:
        printf("Enter distance traveled in kilometers: ");
        scanf("%f", distanceP);
        printf("Enter fuel consumed in liters: ");
        scanf("%f", fuelP);
        break;
    case 1:
        printf("Enter distance traveled in miles: ");
        scanf("%f", distanceP);
        printf("Enter fuel consumed in gallons: ");
        scanf("%f", fuelP);
        break;
    default:
        printf("Invalid mode specified. Mode %d ", *fallbackModeP);
        if(*fallbackModeP == 0) {
            printf("(metric) ");
        } else if(*fallbackModeP == 1) {
            printf("(US) ");
        }
        printf("used.\n");
        *modeP = *fallbackModeP;
        get_info(modeP, fallbackModeP, distanceP, fuelP);
        break;
    }
    *fallbackModeP = *modeP;
}
void show_info(int mode, float distance, float fuel) {

    if(mode == 0) {
        printf("Fuel consumption is %.2f liters per 100 km.\n", 
                fuel/(distance/100));
    } else {
        printf("Fuel consumption is %.1f miles per gallon.\n", 
                distance/fuel);
    }
}