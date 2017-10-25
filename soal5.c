#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

int x;
char *word[100];
pthread_t tid[50];

void* find(void *arg)
{
    pthread_t id = pthread_self();
    int k, num;
    
    for(k=0; k<x; k++){
	num = 0;
	if(pthread_equal(id,tid[k]))
	{
	   FILE *novel;
    	   char read[1000];
	   novel = fopen("Novel.txt", "r");

	   while(!feof(novel)){
		fscanf(novel, "%s", read);
		if(strstr(read, word[k]) != NULL) num++;
	   }
	   fclose(novel);
	   printf("%s = %d\n", word[k], num);
	}
    }
    return NULL;
}

int main(int argc, char **argv)
{
    int i=0, j;
    x=0;
    while(1){
	if(argv[x+1] == NULL) break;
	word[x] = argv[x+1];
	x++;
    }
   
    while(i<x){
        pthread_create(&(tid[i]),NULL,&find,NULL);
        i++;
    }
    for(j=0; j<x; j++){
	pthread_join(tid[j],NULL);
    }
    return 0;
}
