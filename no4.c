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
    int i;
    pthread_t id = pthread_self();
    int fak, j, k;

    for(k=0; k<x; k++){
	fak = 1;
	if(pthread_equal(id,tid[k]))
	{
	   for(i=0; i<bil[k]; i++){
		fak = fak * (i+1);
	   }
	   
	   printf("hasil %d! = %d \n",bil[k], fak);
	}
    }
    return NULL;
}

int main(int argc, char **argv)
{
    int i=0, j, temp=0;
    int err, a, b, N;
    char T;
    int rings;
    x=0;
    //if(argc != 2){
    //}
    while(1){
	//scanf("%d",&argv[x]);
	//scanf("%c",&T);
	//bil[x] = argv[x];
	if(argv[x] == NULL) break;
	rings = atoi(argv[x]); //atoi=convert char to int
	bil[x] = rings;
	x++;
    }
    while(i<=x){
        pthread_create(&(tid[i]),NULL,&faktorial,NULL);
        i++;
    }
    for(j=0; j<=x; j++){
	pthread_join(tid[j],NULL);
    }
    return 0;
}
