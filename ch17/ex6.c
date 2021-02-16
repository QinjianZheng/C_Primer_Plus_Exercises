/* 6
编写一个函数接受 3 个参数:
一个数组名(内含已排序的整数)、
该数组的元素个数和待查找的整数。
如果待查找的整数在数组中，那么该函数 返回 1;
如果该数不在数组中，该函数则返回 0。用二分查找法实现。

*/ 

#include <stdio.h>
#include <stdlib.h>
#define SIZE    10

int isIn(int [], int n, int key);
static int cmp(const void *, const void *);


int main(int argc, char const *argv[])
{   
    int i;
    int arr[SIZE];
    for(i = 0; i < SIZE; i++) {
        arr[i] = rand() % 20;
    }
    qsort(arr, SIZE, sizeof(int), cmp);
    for(i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    puts("Please enter the key for search.");
    puts("Press q to stop.");
    scanf("%d", &i);
    while(1) {
        if(isIn(arr, SIZE, i)) {
            printf("%d is in the array.\n", i);
        } else {
            printf("%d is not found.\n", i);
        }
        while(getchar() != '\n')
            continue;
        if(scanf("%d", &i) != 1) {
            break;
        }
        
    }
    return 0;
}

static int cmp(const void *record, const void *key) {
    const int *r = (const int *) record;
    const int *k = (const int *) key;
    return (*r - *k);
}

int isIn(int arr[], int n, int key) {
    int high = n-1;
    int low = 0;
    int middle = (high + low)/2;
    while(low <= high) {
        if(key == arr[middle]) {
            return 1;
        } else if(key > arr[middle]) {
            low = middle+1;
        } else {
            high = middle-1;
        }
        middle = (high + low)/ 2;
    }
    return 0;

}
