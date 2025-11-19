#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define QUANTUM 3   // Execution time per process

typedef struct Process {
    char name[20];
    int time;
    struct Process *next;
} Process;


int main_layout() {
    int num;
    system("clear");
    printf("+==============================+\n");
    printf("|=======| Round  Robin |=======|\n");
    printf("+==============================+\n");
    printf("|   QUANTUM:            %d      |\n", QUANTUM);
    printf("|==============================|\n");
    printf("|   [1] - Insert Process       |\n");
    printf("|   [2] - List Processes       |\n");
    printf("|   [3] - Execute Processes    |\n");
    printf("|   [0] - Exit                 |\n");
    printf("+==============================+\n");
    printf("Option: ");
    scanf("%d", &num);
    return num;
}

Process* alloc() {
    Process *temp = (Process*)malloc(sizeof(Process));
    if (temp == NULL) printf("Allocation error");
    temp->next = NULL;
    return temp;
}

void insert(Process **array, char name[], int time){
    if ((*array) == NULL) {
        (*array) = alloc();
        strcpy((*array)->name, name);
        (*array)->time = time;
        return;
    }

    Process *process = (*array);
    while (process->next != NULL) process = process->next;

    process->next = alloc();
    process = process->next;
    strcpy(process->name, name);
    process->time = time;
}

void print_array(Process *array) {
    Process *process = array;
    system("clear");
    printf("+------------------+--------+\n");
    printf("|   Process Name   |  Time  |\n");
    printf("+------------------+--------+\n");

    // 2. Se a lista estiver vazia
    if (array == NULL) {
        printf("|      VOID        |   --   |\n");
        printf("+------------------+--------+\n");
        return;
    }

    do {
        printf("| %-16s |  %-5d |\n", process->name, process->time);
        process = process->next;
    } while (process != NULL);

    printf("+------------------+--------+\n");
}

void execute(Process **array) {
    if ((*array) == NULL) {
        printf("Error: Void Array\n");
        return;
    }

    Process *current = (*array);
    Process *aux;

    while ((*array) != NULL) {
        if (current->time > QUANTUM) {
            printf("Executing %s...", current->name);
            current->time -= QUANTUM;
            printf(" Remaining time: %d\n", current->time);
            if (current->next == NULL) {
                current = (*array);
            } else {
                current = current->next;
            } 
        } else {
            // Remove process from list
            if (current == (*array)) {
                (*array) = current->next;
                if (current->next == NULL) {
                    free(current);
                    (*array) = NULL;
                } else {
                    free(current);
                    current = (*array);
                }
            } else {
                aux = (*array);
                while (aux->next != current) {
                    aux = aux->next;
                }
                if (current->next == NULL) {
                    aux->next = NULL;
                    free(current);
                    current = (*array);
                } else {
                    aux->next = current->next;
                    free(current);
                    current = aux->next;
                }
            }
        }
        print_array(*array);
        printf("Executing...\n");
        sleep(1);
    }

    printf("Execution finished!\n");
}


void main() {
    Process *array = NULL;
    bool exit = false;
    char name[20];
    int time;

    while (exit == false) {
        switch (main_layout()) {
        case 1:
            system("clear");
            printf("+==============================+\n");
            printf("Process Name: ");
            scanf(" %[^\n]", name);
            printf("Execution Time: ");
            scanf("%d", &time);
            insert(&array, name, time);
            break;

        case 2:
            print_array(array);
            break;

        case 3:
            execute(&array);
            break;
        case 4:
            system("clear");
            printf("+==============================+\n");
            insert(&array, "Process 1", 4);
            insert(&array, "Process 2", 2);
            insert(&array, "Process 3", 9);
            insert(&array, "Process 4", 4);
            insert(&array, "Process 5", 9);
            insert(&array, "Process 6", 3);
            insert(&array, "Process 7", 5);
            break;

        default:
            exit = true;
            break;
        }
        printf("Press [ENTER] to continue ");
        getchar();
        getchar();
    }

}