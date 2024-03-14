#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void printBuffer() {
    printf("Buffer: [");
    for (int i = 0; i < count; i++) {
        printf("%d ", buffer[i]);
    }
    printf("]\n");
}

void* producer(void* arg) {
    int item = 0;
    while (1) {
        item++;
        pthread_mutex_lock(&mutex);

        while (count == BUFFER_SIZE) {
            pthread_mutex_unlock(&mutex); 
            sched_yield();
            pthread_mutex_lock(&mutex);
        }

        buffer[count++] = item;
        printf("Produced: %d. ", item);
        printBuffer();

        pthread_mutex_unlock(&mutex);
        usleep(100000);
    }
}

void* consumer(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        while (count == 0) {
            pthread_mutex_unlock(&mutex);
            sched_yield();
            pthread_mutex_lock(&mutex);
        }

        int item = buffer[--count];
        printf("Consumed: %d. ", item);
        printBuffer();

        pthread_mutex_unlock(&mutex);
        usleep(200000);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
