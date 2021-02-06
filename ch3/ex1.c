/* 1
通过试验(即编写带有此类问题的程序)观察系统如何处理整数上
溢、浮点数上溢和浮点数下溢的情况。

*/

#include <stdio.h>


int main(int argc, char const *argv[])
{

    printf("%d\n", __INT_MAX__+1); // integer overflow
    // 补码形式，得到-2147483648
    printf("%e\n", __FLT_MAX__ * 100.0f); // float overflow
    // inf
    printf("%e\n", __FLT_MIN__/10.0f); // float underflow
    return 0;
}
