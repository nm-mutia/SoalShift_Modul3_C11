#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#define BELUM_SIAP 0
#define SIAP 1

struct Memory{
int MP4A1;
int PM2_V1;
int SPR_3;
int SS2_V5;
int SPG1_V3;
int MINE;
int status;
};

int main(){
key_t sharedKEY;
int sharedID;

struct Memory *data;
int menu;
char nama_barang[99];
int tambahan;

sharedKEY = ftok("#", 'A');
sharedID = shmget(sharedKEY, sizeof(struct Memory), IPC_CREAT | 0666);

if (sharedID < 0){
printf("SHMGET ERROR!\n");
exit(1);
}

data = (struct Memory *) shmat(sharedID, NULL, 0);
data->status = BELUM_SIAP;

data->MP4A1=0;
data->PM2_V1=0;
data->SPR_3=0;
data->SS2_V5=0;
data->SPG1_V3=0;
data->MINE=0;

while(1)
{
printf("==Menu==\n");
printf("1. Lihat stock senjata\n");
printf("2. Beli senjata\n");
printf(">> ");
scanf("%d", &menu);

if (menu == 1)
{
printf("Jumlah MP4A1 = %d\n", data->MP4A1);
printf("Jumlah PM2-V1 = %d\n", data->PM2_V1);
printf("Jumlah SPR-3 = %d\n", data->SPR_3);
printf("Jumlah SS2-V5 = %d\n", data->SS2_V5);
printf("Jumlah SPG1-V3 = %d\n", data->SPG1_V3);
printf("Jumlah MINE = %d\n", data->MINE);
}

else if(menu == 2){
printf("KETIK NAMA BARANG YANG INGIN DIBELI!\n");
printf("1. MP4A1\n2. PM2-V1\n3. SPR-3\n4. SS2-V5\n5. SPG1-V3\n6. MINE\n");
printf(">> ");
scanf("%s", nama_barang);

if (strcmp(nama_barang,"MP4A1")==0){
printf("Jumlah barang yang ingin dibeli: ");
scanf("%d",&tambahan);
data->MP4A1 -= tambahan;
printf("Jumlah stock MP4A1 = %d \n", data->MP4A1);
}

if (strcmp(nama_barang,"PM2-V1")==0){
printf("Jumlah barang yang ingin dibeli: ");
scanf("%d",&tambahan);
data->PM2_V1 -= tambahan;
printf("Jumlah stock PM2-V1 = %d \n", data->PM2_V1);
}

if (strcmp(nama_barang,"SPR-3")==0){
printf("Jumlah barang yang ingin dibeli: ");
scanf("%d",&tambahan);
data->SPR_3 -= tambahan;
printf("Jumlah stock SPR-3 = %d \n", data->SPR_3);
}

if (strcmp(nama_barang,"SS2-V5")==0){
printf("Jumlah barang yang ingin dibeli: ");
scanf("%d",&tambahan);
data->SS2_V5 -= tambahan;
printf("Jumlah stock SS2-V5 = %d \n", data->SS2_V5);
}

if (strcmp(nama_barang,"SPG1-V3")==0){
printf("Jumlah barang yang ingin dibeli: ");
scanf("%d",&tambahan);
data->SPG1_V3 -= tambahan;
printf("Jumlah stock SPG1-V3 = %d \n", data->SPG1_V3);
}

if (strcmp(nama_barang,"MINE")==0){
printf("Jumlah barang yang ingin dibeli: ");
scanf("%d",&tambahan);
data->MINE -= tambahan;
printf("Jumlah stock MINE = %d \n", data->MINE);
}


else{
return 0;
}

getchar();
}


}
}

