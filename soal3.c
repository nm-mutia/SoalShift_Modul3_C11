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
    pthread_t id = pthread_self();

    while(1)
    {	
	if(fis.statl <= 100 || fis.statk <= 100 || fis.statl > 0 || fis.statl > 0)
	{
	       	if(pthread_equal(id,tid[0])){
		   if(fis.statl <= 0 || fis.statl > 100) exit(EXIT_SUCCESS);
		   sleep(10);
		   fis.statl -= 15;
		   printf("10s Status Lohan : %d\n",fis.statl);
	    	}
		else if(pthread_equal(id,tid[1])){
		   if(fis.statk <= 0 || fis.statk > 100) exit(EXIT_SUCCESS);
		   sleep(20);
		   fis.statk -= 10;
		   printf("20s Status Kepiting : %d\n",fis.statk);
	    	}
	}
	else exit(EXIT_FAILURE);
    }
    return NULL;
}

int main()
{
    int comm;
    int err1 = 0, err2 = 0;
    fis.statl = 100;
    fis.statk = 100;
    printf("Status Lohan 1st: %d\n",fis.statl);
    printf("Status Kepiting 1st: %d\n",fis.statk);
    printf("1 = Beri Makan Lohan (+10)\n");
    printf("2 = Beri Makan Kepiting (+10)\n");

    err1 = pthread_create(&(tid[0]), NULL, &playandcount, NULL);
    err2 = pthread_create(&(tid[1]), NULL, &playandcount, NULL);

    if (err1 != 0) printf("\ncan’t create thread : [%s]", strerror(err1));
    if (err2 != 0) printf("\ncan’t create thread : [%s]", strerror(err2));

    while(1){
    	scanf("%d", &comm);
	if(comm == 1){
	   fis.statl += 10;
	   printf("Status Lohan : %d\n",fis.statl);
	}
	else if(comm == 2){
	   fis.statk += 10;
	   printf("Status Kepiting : %d\n",fis.statk);
	} 
	//pthread_create(&(tid[comm+1]), NULL, &playandcount, NULL);
	//if(fis.statl > 100|| fis.statk > 100 || fis.statl <= 0 || fis.statk <= 0)
	  // exit(EXIT_FAILURE);
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
