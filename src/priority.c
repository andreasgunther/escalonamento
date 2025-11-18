#include <stdio.h>
#include <unistd.h>   
#include <string.h>

struct Process {
    int id;
    int burst;
    int priority;
    int waiting;
    int turnaround;
};

int main() {
    int n;

    printf("Digite o número de processos: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Processo %d\n", p[i].id);

        printf("Tempo de Burst: ");
        scanf("%d", &p[i].burst);

        printf("Prioridade: ");
        scanf("%d", &p[i].priority);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[j].priority < p[i].priority) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].waiting = 0;
    for (int i = 1; i < n; i++) {
        p[i].waiting = p[i-1].waiting + p[i-1].burst;
    }

    for (int i = 0; i < n; i++) {
        p[i].turnaround = p[i].waiting + p[i].burst;
    }

    printf("\nOrdem de execução (por prioridade):\n");
    for (int i = 0; i < n; i++) {
        printf("P%d (Prioridade %d)\n", p[i].id, p[i].priority);
    }

    int width;
    int total;

    for (int i = 0; i < n; i++){

        width = 40;  
        total = (p[i].burst * 1000000) / 40;        
        useconds_t delay = total; 

        for (int i = 0; i <= width; ++i) {
            float fraction = (float)i / width;
            int percent = (int)(fraction * 100);

            int filled = i;
            int empty = width - filled;

            printf("\r[");
            for (int j = 0; j < filled; ++j) putchar('=');
            if (filled < width) putchar('>');
            for (int j = 0; j < empty - 1; ++j) putchar(' ');
            printf("] %3d%%", percent);

            fflush(stdout);
            usleep(delay);
        }

    }
    

    printf("\nTabela:\n");
    printf("Proc\tBurst\tPrior\tWait\tTurn\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].burst,
               p[i].priority,
               p[i].waiting,
               p[i].turnaround);
    }

    return 0;
}