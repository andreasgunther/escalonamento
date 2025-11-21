# 🖥️ Simulador de Escalonamento de Processos (CPU Scheduling)

![Linguagem](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)
![Contribuidores](https://img.shields.io/badge/Contributors-4-purple?style=flat-square)
![Tipo](https://img.shields.io/badge/Sistemas-Operacionais-orange?style=flat-square)
![Status](https://img.shields.io/badge/Status-Concluído-green?style=flat-square)
![Licença](https://img.shields.io/badge/License-MIT-green?style=flat-square)

Este repositório contém a implementação prática de algoritmos de escalonamento de CPU, desenvolvidos em **C** para a disciplina de Sistemas Operacionais. O objetivo é simular como o processador decide qual processo deve ser executado em um ambiente multitarefa.

## 📂 Estrutura do Projeto

O código-fonte está organizado dentro da pasta `src/`, contendo um arquivo para cada algoritmo implementado:

```text
.
├── src/
│   ├── fcfs.c       # First-Come, First-Served
│   ├── sjf.c        # Shortest Job First
│   ├── priority.c   # Priority Scheduling
│   └── rr.c         # Round Robin
└── README.md
```

## ⚙️ Algoritmos Implementados

### 1. First-Come, First-Served (FCFS)
* **Arquivo:** `src/fcfs.c`
* **Tipo:** Não-preemptivo.
* **Descrição:** O algoritmo mais simples. O primeiro processo a chegar na fila de prontos é o primeiro a ser executado pela CPU. Funciona como uma fila de banco convencional.
* **Características:** Simples de implementar, mas sujeito ao "Efeito Comboio" (processos curtos esperando por um longo).

### 2. Shortest Job First (SJF)
* **Arquivo:** `src/sjf.c`
* **Tipo:** Pode ser Preemptivo ou Não-preemptivo.
* **Descrição:** Seleciona o processo que possui o menor tempo de execução (burst time) estimado.
* **Características:** Ótimo para minimizar o tempo médio de espera, mas difícil de implementar em sistemas reais pois requer saber o tempo de execução futuro.

### 3. Priority Scheduling
* **Arquivo:** `src/priority.c`
* **Tipo:** Preemptivo ou Não-preemptivo.
* **Descrição:** Cada processo recebe um número de prioridade. A CPU é alocada ao processo com a maior prioridade (menor número inteiro, geralmente).
* **Características:** Eficiente para sistemas de tempo real, mas pode causar *Starvation* (processos de baixa prioridade nunca executam).

### 4. Round Robin (RR)
* **Arquivo:** `src/rr.c`
* **Tipo:** Preemptivo.
* **Descrição:** Projetado para sistemas de tempo compartilhado (Time-Sharing). Cada processo recebe uma pequena fatia de tempo de CPU (Quantum). Quando o tempo acaba, o processo vai para o fim da fila.
* **Características:** Garante resposta rápida e justiça entre processos, mas o desempenho depende muito do tamanho do Quantum escolhido.

## 🚀 Como Compilar e Executar

Para rodar qualquer um dos escalonadores, você precisará de um compilador C (como o GCC).

1. Clone o repositório:
   ```bash
   git clone https://github.com/andreasgunther/escalonamento
   ```

2. Compile o algoritmo desejado (exemplo com o Round Robin):
   ```bash
   gcc src/rr.c -o rr
   ```

3. Execute o programa:
   ```bash
   ./rr
   ```

## 👩‍💻 Contribuidores

<table border="0" cellpadding="0" cellspacing="0">
  <tr>
    <td align="center" valign="top">
      <a href="https://github.com/andreasgunther">
        <img src="https://images.weserv.nl/?url=avatars.githubusercontent.com/u/113151524?v=4&w=100&h=100&fit=cover&mask=circle" width="100px;" alt="Dev 1"/>
        <br />
        <sub><b>Andreas Gunther</b></sub>
      </a>
    </td>
    <td align="center" valign="top">
      <a href="">
        <img src="https://images.weserv.nl/?url=avatars.githubusercontent.com/u/ID_AQUI?v=4&w=100&h=100&fit=cover&mask=circle" width="100px;" alt="Dev 2"/>
        <br />
        <sub><b>Rubens Ian</b></sub>
      </a>
    </td>
    <td align="center" valign="top">
      <a href="">
        <img src="https://images.weserv.nl/?url=avatars.githubusercontent.com/u/ID_AQUI?v=4&w=100&h=100&fit=cover&mask=circle" width="100px;" alt="Dev 3"/>
        <br />
        <sub><b>Pedro Porto</b></sub>
      </a>
    </td>
    <td align="center" valign="top">
      <a href="https://github.com/Thaylon-B">
        <img src="https://images.weserv.nl/?url=avatars.githubusercontent.com/u/227187458?v=4&w=100&h=100&fit=cover&mask=circle" width="100px;" alt="Dev 4"/>
        <br />
        <sub><b>Thaylon Brenner</b></sub>
      </a>
    </td>
  </tr>
</table>
