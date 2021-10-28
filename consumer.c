//Ramone Fields
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>



#define BufferSize 5 
#define MaxItems 5 

sem_t empty;
sem_t full;

int inside = 0;
int outside = 0;

int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *prod)
{   
    int product;
    for(int i = 0; i < MaxItems; i++) {
        // produce an random item
        product = rand(); 
        sem_wait(&empty);

        pthread_mutex_lock(&mutex);
        buffer[inside] = product;

        printf("Producer %d: Produce Product %d at %d index\n", *((int *)prod),buffer[inside],inside);

        inside = (inside+1)%BufferSize;
        pthread_mutex_unlock(&mutex);

        sem_post(&full);
    }
}
void *consumer(void *cons)
{   
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item = buffer[outside];
        printf("Consumer %d: Consume Product %d from %d index\n",*((int *)cons),item, outside);

        outside = (outside+1)%BufferSize;
        pthread_mutex_unlock(&mutex);

        sem_post(&empty);
    }
}

int main(){   

    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);

    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);

    //Just used for numbering the producer and consumer
    int a[5] = {1,2,3,4,5}; 

    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }


    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(con[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    sem_destroy(&empty);

    sem_destroy(&full);

    return 0;
}