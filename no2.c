#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct game{
    int lubang1[17];
    int lubang2[17];
}hole;

pthread_t tid1;
pthread_t tid2;
hole ho;

void* playandcount(void *arg)
{
    int i;
    pthread_t id = pthread_self();

       	if(pthread_equal(id,tid1)){
	   
    	}
	else if(pthread_equal(id,tid2){
	   
    	}
    
    return NULL;
}

int main()
{
    

    pthread_create(&(tid1), NULL, &playandcount, NULL);
    pthread_create(&(tid2), NULL, &playandcount, NULL);
    while(1){
    	
    }
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}
