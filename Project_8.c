#include <stdio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

// 
int fib(int n) {
    if (n<=2) {
        return 1;
    } 
    return fib(n-1) + fib(n-2);
}

int fibo(int n) {
    if(n<=2) {
        return 1;
    }
    
    int f1 = 1;
    int f2 = 1;
    int fn = 0;

    for (int i = 3; i <= n; i++) {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn; 
    }
    return fn;
}
int main() {
    int n;

    for(n = 1; n <= 40; n++) {
        clock_t start1 = clock();
        fib(n);
        clock_t end1 = clock();
        double time1 = (double)(end1-start1) / CLOCKS_PER_SEC * 1000;

        clock_t start2 = clock();
        fibo(n);
        clock_t end2 = clock();
        double time2 = (double)(end2-start2) / CLOCKS_PER_SEC * 1000;

        printf("N = %2d, Recursive: %6.0fms, Iterative: %6.0fms\n", n, time1, time2);
    }
}
