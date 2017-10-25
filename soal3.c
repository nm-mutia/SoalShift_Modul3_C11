#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct fish{
    int statl;
    int statk;
}fishy;

pthread_t tid[10];
fishy fis;

void* playandcount(void *arg)
{
    int i;
    pthread_t id = pthread_self();

    int fak, j, k;
    while(fis.statl > 100|| fis.statk > 100 || fis.statl <= 0 || fis.statk <= 0){	
       	if(pthread_equal(id,tid[0])){
	   sleep(10);
	   fis.statl = fis.statl - 15;
	   printf("10s Status Lohan : %d\n",fis.statl);
    	}
	else if(pthread_equal(id,tid[1])){
	   sleep(20);
	   fis.statk = fis.statk - 10;
	   printf("20s Status Kepiting : %d\n",fis.statk);
    	}
    }
    if(pthread_equal(id,tid[2])){
    	//system("clear");
	fis.statl = fis.statl - 15;
	printf("Status Lohan : %d\n",fis.statl);
    }
    else if(pthread_equal(id,tid[3])){
    	//system("clear");
	fis.statk = fis.statk - 10;
	printf("Status Kepiting : %d\n",fis.statk);
    }
    return NULL;
}

int main()
{
    fis.statl = 100;
    fis.statk = 100;
    printf("Status Lohan : %d\n",fis.statl);
    printf("Status Kepiting : %d\n",fis.statk);
    printf("1 = Beri Makan Lohan\n");
    printf("2 = Beri Makan Kepiting\n");

    pthread_create(&(tid[0]), NULL, &playandcount, NULL);
    pthread_create(&(tid[1]), NULL, &playandcount, NULL);
    while(1){
    	int comm;
    	int err = 0;
    	scanf("%d", &comm);
	/*if(comm == 1){
		//system("clear");
	}
	else if(comm == 2){
		//scanf("%s",lagu);
	}*/

	err = pthread_create(&(tid[comm+1]), NULL, &playandcount, NULL);
    	if (err != 0){
    		printf("\ncan’t create thread : [%s]", strerror(err));
	}
    }
    return 0;
}
