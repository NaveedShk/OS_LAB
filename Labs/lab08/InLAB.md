Q1: PART A:
CODE :
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000000  // 10 million
float A[SIZE], B[SIZE], C[SIZE];
void fill_arrays() {
    for (int i = 0; i < SIZE; i++) {
        A[i] = (float)i;
        B[i] = (float)(SIZE - i);
    }
}
void add_arrays() {
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] + B[i];
    }
}
int main() {
    clock_t start, end;
    double cpu_time_used;
    fill_arrays();
    start = clock();
    add_arrays();
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Serial execution time: %f seconds\n", cpu_time_used);
    printf("C[0] = %f, C[%d] = %f\n", C[0], SIZE-1, C[SIZE-1]);  // Print first and last element

    return 0;
}

OUTPUT:
![image](https://github.com/user-attachments/assets/b1b63080-91b9-4f7c-b965-ab7ee0dc938e)

