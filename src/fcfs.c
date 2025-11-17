#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//criação da estrutura do nó
typedef struct no{
    int id;
    int tempo_chegada;
    int tempo_execucao;
    struct no *proximo;
} processo;

//função para adicionar os processos
void adicionar(processo **cabeca, int tempo_c, int tempo_e){
    processo*novo = malloc(sizeof(processo));
    if (novo == NULL){
        printf("falha na alocação!\n");
        return;
    }   
    novo->proximo = NULL;
    novo->tempo_chegada = tempo_c;
    novo->tempo_execucao = tempo_e;
    if(*cabeca == NULL){
        novo->id = 1;
        *cabeca = novo;
        return;
    }
    int cont = 1;
    processo *aux = *cabeca;
    while(aux->proximo != NULL){
        cont = cont +1;
        aux = aux->proximo;
    }
    novo->id = cont;
    aux->proximo = novo;
}

//função para exibir a lista
void exibir(processo**cabeca){
    if(*cabeca == NULL){
        printf("lista vazia!\n");
        return;
    }
    processo *aux = *cabeca;
    printf("---------------------------------\n");
    printf(" T A B E L A   P R O C E S S O S \n");
    printf("---------------------------------\n");
    printf("ID    |T.CHEGADA    |T.EXECUÇÃO\n");
    while(aux != NULL){
        printf("%-7d%-14d%-12d\n",aux->id,aux->tempo_chegada,aux->tempo_execucao);
        aux = aux->proximo;
    }
    printf("---------------------------------\n");
}

//função para calcular o tamanho da lista
int tamanho(processo **cabeca){
    int tam=0;
    processo *aux = *cabeca;
    while(aux != NULL){
        tam++;
        aux = aux->proximo;
    }
    return tam;
}

//função para remover um processo
void remover(processo**cabeca,int indice){
     processo *lixo;
    if ((*cabeca)->proximo == NULL){
        lixo = *cabeca;
        *cabeca = NULL;
        free(lixo);
        return;
    }
    if(indice == 1){
        lixo = *cabeca;
        *cabeca = (*cabeca)->proximo;
        free(lixo);
        return;
    }
    processo *aux = *cabeca;
    int cont = 1;
    while(cont != indice-1){
        aux = aux->proximo;
        cont ++;
    }
    if(aux->proximo->proximo == NULL){
        lixo = aux->proximo;
        aux->proximo = NULL;
        free(lixo);
        return;
    }
    lixo = aux->proximo;
    aux->proximo = aux->proximo->proximo;
    free(lixo);
}

//função para ordenar os indices dos processos
void ordenar_i(processo**cabeca){
    if(*cabeca == NULL){
        printf("lista vazia!\n");
        return;
    }
    processo*aux = *cabeca;
    int cont=1;
    while(aux != NULL){
        aux ->id = cont;
        cont++;
        aux = aux->proximo;
    }
}

//função para ordenar os processos com base no tempo de chegada
void ordenar(processo**cabeca){
    if(*cabeca == NULL){
        printf("lista vazia!\n");
        return;
    }
    processo *aux = *cabeca;
    processo *aux2 = *cabeca;
    int troca;
    while(aux->proximo != NULL){
        aux2 = aux->proximo;
        while(aux2!=NULL){
            if(aux->tempo_chegada > aux2->tempo_chegada){
                troca = aux2->id;
                aux2->id = aux->id;
                aux->id = troca;
                troca = aux2->tempo_chegada;
                aux2->tempo_chegada = aux->tempo_chegada;
                aux->tempo_chegada = troca;
                troca = aux2->tempo_execucao;
                aux2->tempo_execucao= aux->tempo_execucao;
                aux->tempo_execucao=troca;
            }
            aux2 = aux2->proximo;
        }
        aux = aux->proximo;
    }
}

int main(){
    processo *cabeca = NULL;
    int fim=0,escolha,tempo_c,tempo_e,tam,indice,cont;
    while(fim != 999){
        printf("-----------\n");
        printf("= M E N U =\n");
        printf("-----------\n");
        printf("1 - Ver Processos\n");
        printf("2 - Adicionar Processo\n");
        printf("3 - Remover Processo\n");
        printf("4 - Finalizar Cadastro\n");
        printf("escolha: ");
        scanf("%d",& escolha);
        system("clear");
        printf("\n");
        switch (escolha){
            case 1:
                if(cabeca == NULL){
                    printf("lista vazia!\n");
                    break;
                }
                ordenar_i(&cabeca);
                exibir(&cabeca);
                break;
            case 2:
                printf("digite o tempo de chegada do processo: \n");
                scanf("%d",&tempo_c);
                printf("digite o tempo de execução do processo: \n");
                scanf("%d",&tempo_e);
                adicionar(&cabeca,tempo_c,tempo_e);
                ordenar_i(&cabeca);
                break;
            case 3:
                if (cabeca == NULL){
                    printf("lista vazia!\n");
                    break;
                }
                exibir(&cabeca);
                while(1){
                    printf("digite o indice do processo: \n");
                    scanf("%d",&indice);
                    tam = tamanho(&cabeca);
                    if (indice < 1 || indice > tam){
                        printf("índice inválido, digite um índice correto: \n");
                    }
                    else{
                        break;
                    }
                }
                remover(&cabeca,indice);
                ordenar_i(&cabeca);
                break;
            case 4:
                fim = 999;
                break;
        }
    }
    ordenar(&cabeca);
    while(1){
        if(cabeca == NULL){
            printf("\nFIM...\n");
            break;
        }
        system("clear");
        exibir(&cabeca);
        printf("\n\nEXECUTANDO PROCESSO: %d \n", cabeca->id);
        cont = cabeca->tempo_execucao;
        while(cont > 0){
            printf("__");
            fflush(stdout);
            usleep(1000000);
            cont--;
        }
        cabeca = cabeca->proximo;
    }
    return 0;
}