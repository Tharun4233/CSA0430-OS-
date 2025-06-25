#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Thread function 1
void* task1(void* arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Task 1 - Count %d\n", i);
        sleep(1);
    }
    return NULL;
}

// Thread function 2
void* task2(void* arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Task 2 - Count %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread finished.\n");
    return 0;
}

