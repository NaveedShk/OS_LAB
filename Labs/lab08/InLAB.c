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



PART B
CODE :
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 10000000  // 10 million
#define NUM_THREADS 10
float A[SIZE], B[SIZE], C[SIZE];
typedef struct {
    int start, end;
} ThreadData;
void fill_arrays() {
    for (int i = 0; i < SIZE; i++) {
        A[i] = (float)i;
        B[i] = (float)(SIZE - i);
    }
}
void* add_arrays(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    for (int i = data->start; i < data->end; i++) {
        C[i] = A[i] + B[i];
    }
    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    clock_t start, end;
    double cpu_time_used;
    fill_arrays();
    start = clock();
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].start = i * (SIZE / NUM_THREADS);
        thread_data[i].end = thread_data[i].start + (SIZE / NUM_THREADS);
        pthread_create(&threads[i], NULL, add_arrays, &thread_data[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Multithreaded execution time: %f seconds\n", cpu_time_used);
    printf("C[0] = %f, C[%d] = %f\n", C[0], SIZE-1, C[SIZE-1]);  // Print first and last element

    return 0;
}




