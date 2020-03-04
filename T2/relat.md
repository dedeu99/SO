
# SO 2020 TP2
##### 62362
##### André Martins

* [Primeira parte](#primeira-parte)
	- [Tarefas](#tarefas)
    - [Escalonamento](#escalonamento)
* [Segunda parte](#segunda-parte)
	- [Sequencial](#sequencial)
    - [Concorrente](#concorrente)
    - [Observações](#observacoes)
* [Terceira parte](#terceira-parte)

---
## 2.1 - Primeira parte
### Tarefas

#### 1. Relembre o conceito de tarefas apresentado na aula teórica e explique-o por palavras suas.
Sequência de acções programadas indivisíveis, i.e., um conjunto de instruções que têm de ser executadas sequencialmente pois, quando executadas em paralelo, produzem resultados diferentes.

#### 2. Considere a figura abaixo que representa as transições de estado de uma tarefa e explique-a.

![alt text][Fig1]

#### 3. Identifique o objetivo de cada uma das seguintes funções:
  + pthread_create
##### Assinatura
``` manpage
int pthread_create(pthread_t* t, const pthread_attr_* attr, void* (*fx)(void*), void* p);
```
##### Descrição
Inicia uma nova thread endereçada em t com atributos definidos no endereço attr que executa fx em que p é o endereço do inicio dos parâmetros de fx;

---
+ pthread_exit
##### Assinatura 
``` manpage
void pthread_exit(void* r);
```
##### Descrição
Termina a thread *caller* com o status r, NULL ou 0 (mesmo em C) representa execução terminada sem erros.

---
  + pthread_yield
##### Assinatura
``` manpage
int pthread_yield(void);
```
##### Descrição
Coloca a thread *caller* no final da *queue* do *scheduler* do sistema operativo e provoca uma mudança de contexto para uma nova thread.
O comportamento não está especificado para políticas de scheduling não deterministicas.

---
4. Passe para a sua área de trabalho os exemplos apresentados na aula teórica. Execute-os várias vezes e
comente os resultados obtidos.
5. Considere o programa hello_m.c. Compile com
gcc -Wall hello_m.c -o hello_m -lpthread
e execute repetidamente com
./hello_m | grep "#" | wc -l
Justifique os resultados obtidos.
6. Altere a função child do programa osm-p2.4_m.c, substituindo as referências a 3 segundos por 5, na
chamada da função e na informação impressa. Compile, execute e explique os resultados obtidos.

---
### Escalonamento
1. Explique, por palavras suas, os conceitos e relações expressos na figura 3.6 do livro e que a seguir se
reproduz.

![alt text][Fig3.6]
---
### Segunda parte
#### Sequencial
1. Escreva em C um programa que calcule a soma C de dois vetores de inteiros A e B. O programa deve
receber da consola a dimensão dos vetores e os elementos de cada um deles e escrever os elementos do
vetor resultante
``` C
asd
```
#### Concorrente
2. Implemente uma versão concorrente desse programa usando POSIX threads.
``` C
asd
```
#### Observações
### Terceira parte
1. O que entende pelos conceitos abaixo, qual o seu impacto no desempenho do sistema:
   a) cache hit
   b) cache miss
   c) temporal locality
   d) spatial locality
   e) cache coherence protocol
2. Comente, justificando, a validade das seguintes afirmações: 
a) Maximizar a taxa de produção de resultados melhora o desempenho do sistema.
b) Minimizar o tempo médio de resposta do sistema melhora o desempenho do sistema.
c) É possível maximizar a taxa de produção de resultados e minimizar o tempo médio de resposta do
sistema.
d) Uma tarefa passa do estado bloqueado (waiting) para em execução (running) quando é selecionada
para execução.
e) Uma tarefa passa do estado em execução (running) para bloqueado (waiting) quando outra tarefa
que estava pronta a executar (runnable) é selecionada para execução (running).
<

[Fig1]: https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 2"
[Fig3.6]: https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 2"