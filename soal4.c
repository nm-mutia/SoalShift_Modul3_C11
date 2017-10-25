#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

int x;
int bil[100];
pthread_t tid[100];

void* faktorial(void *arg)
{
    int i, k;
    pthread_t id = pthread_self();
    long long int fak;

    for(k=0; k<x; k++){
	fak = 1;
	if(pthread_equal(id,tid[k]))
	{
	   for(i=0; i<bil[k]; i++)
		fak = fak * (i+1);
	   printf("Hasil %d! = %lld \n",bil[k],fak);
	}
    }
    return NULL;
}

int main(int argc, char **argv)
{
    int i=0, j, err, rings;
    x=0;
    while(1){
	if(argv[x+1] == NULL) break;
	rings = atoi(argv[x+1]); //atoi convert char to int
	bil[x] = rings;
	x++;
    }
    while(i<x){
        pthread_create(&(tid[i]),NULL,&faktorial,NULL);
        i++;
    }
    for(j=0; j<x; j++){
	pthread_join(tid[j],NULL);
    }
    return 0;
}
