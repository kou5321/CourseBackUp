/*  debug.c  */
#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

/*  计算n的阶乘n!  */
long Fac(int n);

/* 主函数
 * 输入一个n计算n的阶乘  */
int main(void)
{
    int     n;
    long    fac;

    while(scanf("%d", &n) != EOF)
    {
        printf("%d! = %ld\n", n, Fac(n));
    }

    return EXIT_SUCCESS;
}


/*  计算n的阶乘n!  */
long Fac(int n)
{
    int i;
    long fac;

    for(i = 1; i <= n; i++)
    {
        fac *= i;
        printf("调试信息 %d! = %ld\n", i, fac);/*  调试信息  */

    }

    return fac;
}