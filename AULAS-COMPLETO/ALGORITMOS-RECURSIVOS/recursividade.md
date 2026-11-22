# Funções e Procedimentos
## Recursão vs Iteração em C

---

## Funções e Procedimentos

A linguagem C permite modularizar programas usando funções, facilitando organização, reutilização e manutenção do código.

```
                    FUNÇÃO
                      |
         +------------+------------+
         |                         |
    PROCEDIMENTO             FUNÇÃO COM
     (void — sem              RETORNO
      retorno)               (int, float...)
         |                         |
   void saudacao()          int soma(int a, int b)
   {                        {
     printf("Ola!");           return a + b;
   }                         }
```

### Sintaxe básica

```c
// procedimento — não devolve nada
void nome_procedimento(tipo param1, tipo param2) {
    // corpo
}

// função — devolve um valor
tipo nome_funcao(tipo param1, tipo param2) {
    // corpo
    return valor;
}
```

### Procedimento (sem retorno)

```c
#include <stdio.h>

void saudacao() {
    printf("Ola! Seja bem-vindo ao curso de C!\n");
}

int main() {
    saudacao();   // chamando o procedimento
    return 0;
}
```

### Função com retorno

```c
#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}

int main() {
    int resultado = soma(5, 3);
    printf("A soma e: %d\n", resultado);
    return 0;
}
```

---

## Recursão vs Iteração

```
  RECURSÃO                          ITERAÇÃO
  ─────────────────────────         ─────────────────────────
  função chama a si mesma           laço (for, while)
  usa a pilha de chamadas           usa variáveis de controle
  mais elegante para alguns         geralmente mais eficiente
  problemas                         em memória
  precisa de caso base              precisa de condição de parada
```

### Estrutura geral de uma função recursiva

```
  funcao(n)
      |
      v
  +-------------------+
  | caso base?  (n==0)|----> SIM ---> retorna resultado direto
  +-------------------+
      |
     NÃO
      |
      v
  chama funcao(n-1)  <--- subproblema menor
      |
      v
  combina resultado
  e retorna
```

Todo função recursiva precisa de:
- **Caso base** — condição de parada (evita chamadas infinitas)
- **Chamada recursiva** — chama a si mesma com um parâmetro menor

```c
tipo funcao(parametros) {
    if (condicao_base) {
        return resultado;       // para aqui
    } else {
        return funcao(novo_parametro);   // desce um nível
    }
}
```

---

## Fatorial

Definição: `n! = n × (n-1)!`   com caso base `0! = 1`

```
  fatorial(5)
      |
      5 × fatorial(4)
              |
              4 × fatorial(3)
                      |
                      3 × fatorial(2)
                              |
                              2 × fatorial(1)
                                      |
                                      1 × fatorial(0)
                                              |
                                           retorna 1  <-- caso base

  subindo o retorno:
  1 × 1 = 1
  2 × 1 = 2
  3 × 2 = 6
  4 × 6 = 24
  5 × 24 = 120
```

### Recursivo

```c
int fatorial(int n) {
    if (n == 0)
        return 1;              // caso base
    return n * fatorial(n-1); // chamada recursiva
}

int main() {
    printf("Fatorial de 5 = %d\n", fatorial(5));  // 120
    return 0;
}
```

### Iterativo

```c
int fatorialIterativo(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    printf("Fatorial de 5 = %d\n", fatorialIterativo(5));  // 120
    return 0;
}
```

### Comparando a execução

```
  RECURSIVO                         ITERATIVO
  pilha de chamadas                 variável acumuladora

  fatorial(5) ─┐                    resultado = 1
  fatorial(4) ─┤  descendo          i=1: resultado = 1
  fatorial(3) ─┤  (empilhando)      i=2: resultado = 2
  fatorial(2) ─┤                    i=3: resultado = 6
  fatorial(1) ─┤                    i=4: resultado = 24
  fatorial(0) ─┘  retorna 1        i=5: resultado = 120
       ↑
  sobe calculando                   sem pilha — só um loop
  5×4×3×2×1×1 = 120
```

---

## Potência

Definição: `x^y = x × x^(y-1)`   com caso base `x^0 = 1`

```
  potencia(2, 4)
      |
      2 × potencia(2, 3)
              |
              2 × potencia(2, 2)
                      |
                      2 × potencia(2, 1)
                              |
                              2 × potencia(2, 0)
                                      |
                                   retorna 1  <-- caso base

  subindo:  2×1=2  →  2×2=4  →  2×4=8  →  2×8=16
```

### Recursivo

```c
int potencia(int x, int y) {
    if (y == 0)
        return 1;                    // caso base
    return x * potencia(x, y-1);   // chamada recursiva
}

int main() {
    printf("2^4 = %d\n", potencia(2, 4));  // 16
    return 0;
}
```

### Iterativo

```c
int potenciaIterativa(int x, int y) {
    int resultado = 1;
    for (int i = 0; i < y; i++) {
        resultado *= x;
    }
    return resultado;
}

int main() {
    printf("2^4 = %d\n", potenciaIterativa(2, 4));  // 16
    return 0;
}
```

---

## Fibonacci

Definição: `F(n) = F(n-1) + F(n-2)`   com casos base `F(0) = 0` e `F(1) = 1`

```
  sequência:  0  1  1  2  3  5  8  13  21 ...
  índice:     0  1  2  3  4  5  6   7   8

  fibonacci(6) — árvore de chamadas recursivas:

                         fib(6)
                        /      \
                    fib(5)     fib(4)
                   /    \      /    \
               fib(4) fib(3) fib(3) fib(2)
               /   \   /  \   /  \   /  \
           fib(3)fib(2)fib(2)fib(1)...  ...
            ...

  muitas chamadas repetidas! (ineficiente sem memoização)
```

```
  fibonacci(6) passo a passo:

  F(0)=0   F(1)=1   F(2)=0+1=1   F(3)=1+1=2
  F(4)=1+2=3   F(5)=2+3=5   F(6)=3+5=8
```

### Recursivo

```c
int fibonacci(int n) {
    if (n == 0) return 0;   // caso base 1
    if (n == 1) return 1;   // caso base 2
    return fibonacci(n-1) + fibonacci(n-2);   // chamada recursiva
}

int main() {
    printf("Fibonacci(6) = %d\n", fibonacci(6));  // 8
    return 0;
}
```

### Iterativo

```c
int fibonacciIterativo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;   // próximo = soma dos dois anteriores
        a = b;       // avança a janela
        b = c;
    }
    return b;
}

int main() {
    printf("Fibonacci(6) = %d\n", fibonacciIterativo(6));  // 8
    return 0;
}
```

### Comparando a execução para n=6

```
  RECURSIVO                         ITERATIVO
  muitas chamadas repetidas         só uma passagem

  fib(6) chama fib(5) e fib(4)     a=0, b=1
  fib(5) chama fib(4) e fib(3)     i=2: c=1, a=1, b=1
  fib(4) é calculado 2x!           i=3: c=2, a=1, b=2
  fib(3) é calculado 3x!           i=4: c=3, a=2, b=3
  fib(2) é calculado 5x!           i=5: c=5, a=3, b=5
                                   i=6: c=8, a=5, b=8
  total: 25 chamadas               total: 1 loop de 5 passos
```

---

## Resumo Geral

| | Recursivo | Iterativo |
|---|---|---|
| **Como funciona** | função chama a si mesma | laço de repetição |
| **Memória** | usa pilha de chamadas | usa variáveis locais |
| **Legibilidade** | mais próximo da definição matemática | mais explícito |
| **Risco** | stack overflow se caso base errado | sem esse risco |
| **Eficiência** | pode recalcular subproblemas (fib) | geralmente mais rápido |
| **Quando usar** | problema tem estrutura recursiva natural | performance é prioridade |

```
  regra prática:
  se o problema se define em termos de si mesmo → recursão
  se precisa de performance ou memória mínima  → iteração
```

---

## Exercícios

### String invertida

Crie um programa que leia uma string e a apresente invertida. Faça as versões recursiva e iterativa.

```
  Entrada: "CADERNO"

  RECURSIVO                         ITERATIVO
  inverte("CADERNO")                i começa no fim
    imprime 'O'                     C A D E R N O
    inverte("CADEРN")                             ^
      imprime 'N'                   imprime: O N R E D A C
      inverte("CADER")
        ...
          inverte("")  <-- caso base (string vazia)
```

### MDC — Máximo Divisor Comum

Crie um programa recursivo e outro iterativo que calcule o MDC de dois números.

```
  Algoritmo de Euclides:
  MDC(a, b) = MDC(b, a mod b)   com caso base MDC(a, 0) = a

  Exemplo: MDC(48, 18)

  RECURSIVO                         ITERATIVO
  mdc(48, 18)                       a=48, b=18
    mdc(18, 12)    48%18=12         enquanto b != 0:
      mdc(12, 6)   18%12=6           temp=18, a=18, b=48%18=12
        mdc(6, 0)  12%6=0            temp=12, a=12, b=18%12=6
          retorna 6  <-- caso base   temp=6,  a=6,  b=12%6=0
                                    retorna a = 6

  MDC(48, 18) = 6
```