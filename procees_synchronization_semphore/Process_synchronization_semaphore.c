#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#define MaxItems 5
#define BufferSize 5
sem_t empty,full,mutex;
int in = 0,out = 0;
int buffer[BufferSize];
void *producer(void *pno)
{
    int item;
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = rand();
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
        in = (in+1)%BufferSize;
        sem_post(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cno)
{
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out);
        out = (out+1)%BufferSize;
        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main()
{
    pthread_t pro[5],con[5];
    sem_init(&mutex, 0,1);
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);
    int a[5] = {1,2,3,4,5};
    printf("In this program, only one consumer but 5 producer are there so the buffer gets full as there are no enough consumers.. \nso the program does not get terminated\n\n");
    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 1; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 1; i++) {
        pthread_join(con[i], NULL);
    }
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}

