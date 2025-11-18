#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>


typedef struct no{
    int id;
    int burst_time;
    int arrival;
}process;

int main(){
    int np,aux,aux1;

    printf("=================================\n");
    printf("------SJF ALGORITHM PROCESS------\n");
    printf("=================================\n");
    printf("Quantos processos vai registrar:\n");
    scanf("%d",&np);
    
     process vet[np];
     for(int c=0;c<np; c++) {
        vet[c].id= c +1;
        printf("Process:%d\n",vet[c].id);
        printf("Digite o tempo de chegada do processo:%d\n",vet[c].id);
        scanf("%d",&vet[c].arrival);
        printf("Digite o tempo de Burst do processo:%d\n",vet[c].id);
        scanf("%d",&vet[c].burst_time);
     }

     for(int c=0; c<np;c++){
        for(int c2=0; c2<np; c2++){
            if(vet[c2].burst_time > vet[c].burst_time){
                aux=vet[c].id;
                vet[c].id=vet[c2].id;
                vet[c2].id=aux;
                aux=vet[c].burst_time;
                vet[c].burst_time=vet[c2].burst_time;
                vet[c2].burst_time=aux;
                aux=vet[c].arrival;
                vet[c].arrival=vet[c2].arrival;
                vet[c2].arrival=aux;
            

            }
            else if(vet[c2].burst_time == vet[c].burst_time){
                if(vet[c2].arrival > vet[c].arrival){
                aux1=vet[c].id;
                vet[c].id=vet[c2].id;
                vet[c2].id=aux1;
                aux1=vet[c].burst_time;
                vet[c].burst_time=vet[c2].burst_time;
                vet[c2].burst_time=aux1;
                aux1=vet[c].arrival;
                vet[c].arrival=vet[c2].arrival;
                vet[c2].arrival=aux1;
                }

            }   
        }
    }
    system("clear");
    printf("\nTabela:\n");
    printf("Proc\tBurst\tchegada\t\n");
    for (int i = 0; i < np; i++) {
        printf("P%d\t%d\t%d\t\n",
               vet[i].id,
               vet[i].burst_time,
               vet[i].arrival);
        }

    for (int i = 0; i<np;i++) {
        printf("\n\nEXECUTANDO PROCESSO: %d \n", vet[i].id);
        aux = vet[i].burst_time;
        while(aux > 0){
            printf(">>");
            fflush(stdout);
            usleep(1000000);
            aux--;
        }
    }
    

    return 0;


};


