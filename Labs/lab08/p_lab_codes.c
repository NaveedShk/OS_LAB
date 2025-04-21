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


Q2 :
CODE:
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int *numbers;
int count;
float average;
int minimum;
int maximum;
void* calculate_average(void* arg) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    average = (float)sum / count;
    pthread_exit(0);
}
void* calculate_minimum(void* arg) {
    minimum = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }
    pthread_exit(0);
}
void* calculate_maximum(void* arg) {
    maximum = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }
    pthread_exit(0);
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s num1 num2 num3 ...\n", argv[0]);
        return -1;
    }
    count = argc - 1;
    numbers = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }
    pthread_t avg_thread, min_thread, max_thread;
    pthread_create(&avg_thread, NULL, calculate_average, NULL);
    pthread_create(&min_thread, NULL, calculate_minimum, NULL);
    pthread_create(&max_thread, NULL, calculate_maximum, NULL);
    pthread_join(avg_thread, NULL);
    pthread_join(min_thread, NULL);
    pthread_join(max_thread, NULL);
    printf("The average value is %.2f\n", average);
    printf("The minimum value is %d\n", minimum);
    printf("The maximum value is %d\n", maximum);
    free(numbers);
    return 0;
}



