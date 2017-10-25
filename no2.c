#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct game{
    int lubang1[17];
    int lubang2[17];
    int poin1;
    int poin2;
}hole;

pthread_t tid[3];
hole ho;

void* playandcount(void *arg)
{
    int i;
    pthread_t id = pthread_self();

       	if(pthread_equal(id,tid[0])){
	   
    	}
	else if(pthread_equal(id,tid[1]){
	   
    	}
    
    return NULL;
}

int main()
{
    int giliran, holes, lub, teb;
    giliran = 1;
    for(i=0; i<16; i++){
	ho.lubang1[i] = 0;//pemain1
	ho.lubang2[i] = 0;//pemain2
    }
    
    while(1){
	if(giliran == 1){
	   printf("Giliranmu! Pasang brp lubang? ");
    	   scanf("%d", &holes);
	   for(i=0; i<holes; i++){
		scanf("%d",&lub);
		ho.lubang1[lub-1] = 1;
	   }
	   printf("Tebak : ");
	   for(i=0; i<holes; i++){
	   	scanf("%d",&teb);
	   	if(ho.lubang1[teb-1] == 1) ho.poin1++;
		else pho.oin2++;
	   }
	   giliran++;
	}
	else{
	   printf("Giliranmu!! Pasang brp lubang? ");
    	   scanf("%d", &holes);
	   for(i=0; i<holes; i++){
		scanf("%d",&lub);
		ho.lubang2[lub-1] = 1;
	   }
	   printf("Tebak : ");
	   for(i=0; i<holes; i++){
	   	scanf("%d",&teb);
	   	if(ho.lubang2[teb-1] == 1) ho.poin2++;
		else ho.poin1++;
	   }
	   giliran--;
	}
	pthread_create(&(tid[giliran-1]), NULL, &playandcount, NULL);
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
