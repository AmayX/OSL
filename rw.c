#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
sem_t x,y;
pthread_t tid;
pthread_t wt[100],rt[100];
int rc = 0;

void *reader(void* param)
{
    sem_wait(&x);
    rc++;
    if(rc==1)
        sem_wait(&y);
    sem_post(&x);
    printf("%d reader is inside\n",rc);
    usleep(3);
    sem_wait(&x);
    rc--;
    if(rc==0)
    {
        sem_post(&y);
    }
    sem_post(&x);
    printf("%d Reader is leaving\n",rc+1);
    return NULL;
}

void *writer(void* param)
{
    printf("Writer is trying to enter\n");
    sem_wait(&y);
    printf("Writer has entered\n");
    sem_post(&y);
    printf("Writer is leaving\n");
    return NULL;
}

int main()
{
    int n2,i;
    printf("Enter the number of readers:");
    scanf("%d",&n2);
    printf("\n");
    int n1[n2];
    sem_init(&x,0,1);
    sem_init(&y,0,1);
    for(i=0;i<n2;i++)
    {
        pthread_create(&wt[i],NULL,reader,NULL);
        pthread_create(&rt[i],NULL,writer,NULL);
    }
    for(i=0;i<n2;i++)
    {
        pthread_join(wt[i],NULL);
        pthread_join(rt[i],NULL);
    }

}


