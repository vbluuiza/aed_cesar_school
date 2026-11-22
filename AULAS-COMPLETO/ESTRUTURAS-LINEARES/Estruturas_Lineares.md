# Estruturas Lineares
## Aula 03 — Listas, Filas e Pilhas

---

## Tipos de Dados Abstratos (ADT)

ADT é um tipo de dados que implementa objetos cujo comportamento é definido por um conjunto de valores e operações.

- O conceito da estrutura é **separado** de sua implementação subjacente
- O que importa é **o que ela faz**, e não como ela faz
- Empregadas para simplificar diversas operações em programação

Os principais tipos de ADTs são:

| ADT | Regra | Descrição |
|-----|-------|-----------|
| **Lista** | livre | inserção e remoção em qualquer posição |
| **Pilha** | LIFO | Last In, First Out |
| **Fila** | FIFO | First In, First Out |

---

## Listas (Linked List)

Em uma lista os dados são armazenados de forma sequencial em estruturas chamadas **nós**. Cada nó tem um campo de informação e um ponteiro que conecta ao próximo nó.

### Lista Simplesmente Encadeada

```
  head
   |
   v
+-------+------+    +-------+------+    +-------+------+
| dado  | prox |--->| dado  | prox |--->| dado  | prox |---> NULL
+-------+------+    +-------+------+    +-------+------+
   10                   20                   30
```

### Lista Duplamente Encadeada

```
  head
   |
   v
+------+-------+------+    +------+-------+------+    +------+-------+------+
| ant  | dado  | prox |--->| ant  | dado  | prox |--->| ant  | dado  | prox |
+------+-------+------+    +------+-------+------+    +------+-------+------+
 NULL     10        <-----------    20        <-----------    30       NULL
```

### Lista Circular

```
  head
   |
   v
+-------+------+    +-------+------+    +-------+------+
| dado  | prox |--->| dado  | prox |--->| dado  | prox |---+
+-------+------+    +-------+------+    +-------+------+   |
   10                   20                   30             |
   ^                                                        |
   +--------------------------------------------------------+
```

### Vantagens

- Inserção ou remoção **não implica mover outros elementos**
- Não é necessário definir tamanho máximo na criação — memória alocada dinamicamente

### Desvantagens

- Encadeamento mal feito pode **perder toda a lista**
- Para acessar o elemento na posição `n`, é necessário percorrer os `n-1` anteriores

### Operações

| Operação | Descrição |
|----------|-----------|
| `get()` | retorna elemento em posição específica |
| `insert()` | insere em qualquer posição |
| `remove()` | remove a primeira ocorrência de um elemento |
| `removeAt()` | remove o elemento em posição especificada |
| `replace()` | substitui elemento em qualquer posição |
| `size()` | retorna o número de elementos |
| `isEmpty()` | retorna se a lista está vazia |
| `isFull()` | retorna se a lista está cheia |

### Código — Lista Encadeada em C

```c
typedef struct No {
    int dado;
    struct No* prox;
} No;

// inserir no início
No* inserir_inicio(No* head, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = head;
    return novo;
}

// imprimir lista
void imprimir_lista(No* head) {
    No* atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}
```

---

## Pilha (Stack)

Estrutura linear onde a inserção e remoção seguem o princípio **LIFO** — Last In, First Out. Elementos só entram e saem pelo **topo**.

```
        push(D)         pop()
           |              |
           v              v
        +-----+        +-----+
 topo ->|  D  |        |  C  |<-- topo (D foi removido)
        +-----+        +-----+
        |  C  |        |  C  |
        +-----+        +-----+
        |  B  |        |  B  |
        +-----+        +-----+
        |  A  |        |  A  |
        +-----+        +-----+
```

```
  empilhando: A -> B -> C -> D
  desempilhando: D -> C -> B -> A
  (sempre o último que entrou sai primeiro)
```

### Operações

| Operação | Descrição |
|----------|-----------|
| `push()` | insere no topo |
| `pop()` | remove e retorna o elemento do topo |
| `peek()` | retorna o topo sem remover |
| `size()` | retorna o número de elementos |
| `isEmpty()` | retorna se a pilha está vazia |
| `isFull()` | retorna se a pilha está cheia |

### Aplicações

- Implementação de funções **recursivas**
- Mecanismos de **desfazer/refazer** em aplicações
- Verificação sintática em **compiladores**
- Avaliação de **expressões aritméticas**
- Operações de **backtracking** (mapas, jogos)
- **NLP** (Natural Language Processing)

### Código — Pilha em C

```c
typedef struct Pilha {
    int dado;
    struct Pilha* prox;
} Pilha;

// push — inserir no topo
Pilha* push(Pilha* topo, int valor) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->dado = valor;
    novo->prox = topo;
    return novo;
}

// pop — remover do topo
Pilha* pop(Pilha* topo) {
    if (topo == NULL)
        return NULL;
    Pilha* temp = topo;
    topo = topo->prox;
    free(temp);
    return topo;
}
```

---

## Fila (Queue)

Estrutura linear onde a inserção e remoção seguem o princípio **FIFO** — First In, First Out. Elementos entram pelo **final** e saem pelo **início**.

```
  enqueue(D)                          dequeue()
      |                                   |
      v                                   v
  +---+---+---+---+               +---+---+---+
  | A | B | C | D |               | B | C | D |
  +---+---+---+---+               +---+---+---+
  ^               ^               ^           ^
início           fim           início        fim
 (sai)          (entra)         (A saiu)
```

```
  chegada na fila:  A  B  C  D
  saída da fila:    A  B  C  D
  (quem chegou primeiro, sai primeiro)
```

### Operações

| Operação | Descrição |
|----------|-----------|
| `enqueue()` | insere no final da fila |
| `dequeue()` | retira e retorna o elemento do início |
| `peek()` | retorna o início sem remover |
| `size()` | retorna o número de elementos |
| `isEmpty()` | retorna se a fila está vazia |
| `isFull()` | retorna se a fila está cheia |

### Aplicações

- Filas de **impressão** e acesso a disco
- **Teclas digitadas** no teclado (buffer)
- **Agendamento de CPU**
- Transferência de dados **assíncrona** entre processos
- **Gerenciamento de filas** por senha (hospitais, etc.)

### Código — Fila em C

```c
typedef struct Fila {
    int dado;
    struct Fila* prox;
} Fila;

// enqueue — inserir no final
Fila* enqueue(Fila* fim, int valor) {
    Fila* novo = (Fila*)malloc(sizeof(Fila));
    novo->dado = valor;
    novo->prox = NULL;
    if (fim != NULL)
        fim->prox = novo;
    return novo;
}

// dequeue — remover do início
Fila* dequeue(Fila* inicio) {
    if (inicio == NULL)
        return NULL;
    Fila* temp = inicio;
    inicio = inicio->prox;
    free(temp);
    return inicio;
}
```

---

## Pilha vs Fila

```
        PILHA (LIFO)                      FILA (FIFO)

        push ->  +---+                  enqueue ->  +---+---+---+
                 | C | <- topo (pop)                | A | B | C |
                 +---+                              +---+---+---+
                 | B |                              ^           ^
                 +---+                           início        fim
                 | A |                          (dequeue)   (enqueue)
                 +---+

    entra pelo topo, sai pelo topo      entra pelo fim, sai pelo início
```

| | Pilha | Fila |
|---|---|---|
| **Regra** | LIFO | FIFO |
| **Inserção** | topo | final |
| **Remoção** | topo | início |
| **Inserir** | `push()` | `enqueue()` |
| **Remover** | `pop()` | `dequeue()` |
| **Ponteiros** | 1 (topo) | 2 (início e fim) |
| **Uso típico** | elemento mais recente | ordem de chegada |

---

## Exercícios

### Lista — Inserção no Início e no Final

Implemente uma lista encadeada simples com:
- Inserir elementos no **início**
- Inserir elementos no **final**
- Imprimir todos os elementos

```
Inserir no início: 10, 20, 30
Inserir no final:  40, 50

Saída: 30 -> 20 -> 10 -> 40 -> 50 -> NULL
```

---

### Pilha — Inverter uma Palavra

Crie um programa que receba uma palavra e a inverta usando uma pilha.

```
Entrada: C A D E R N O
         | | | | | | |
         v v v v v v v
        push em sequência

Pilha:   +---+
         | O |  <- topo
         +---+
         | N |
         +---+
         | R |
         +---+
         | E |
         +---+
         | D |
         +---+
         | A |
         +---+
         | C |
         +---+

pop em sequência: O N R E D A C

Saída: ONREDAC
```

---

### Fila — Simulador de Atendimento

Crie um programa que simule uma fila de atendimento com:
- Adicionar uma pessoa
- Atender (remover) a próxima pessoa
- Exibir a fila atual

```
Adicionar: Ana, Bruno, Carlos

Fila: Ana <- Bruno <- Carlos <- NULL
      ^
    início (próximo a ser atendido)

Atender: Ana

Fila: Bruno <- Carlos <- NULL
```