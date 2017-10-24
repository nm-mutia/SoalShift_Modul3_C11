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

int main(void)
{
    int i=0, j, temp=0;
    int err, a, b, N;
    char T;
    x=0;
    while(1){
	scanf("%d",&N);
	scanf("%c",&T);
	bil[x] = N;
	x++;
	if(T == '\n') break;
    }
    for(a=0; a<x; a++){
	for(b=a+1; b<x; b++){
	    if(bil[a] > bil[j]){
		temp = bil[a];
		bil[a] = bil[b];
		bil[b] = temp;
	    }
	}
    }
    while(i<=x){
        err = pthread_create(&(tid[i]),NULL,&faktorial,NULL);
       /* if(err != 0){
            printf("can't create thread : [%s]\n",strerror(err));
        }
        else{
            printf("create thread %d success\n",i+1);
        } */
        i++;
    }
    for(j=0; j<=x; j++){
	pthread_join(tid[j],NULL);
    }
    return 0;
}
