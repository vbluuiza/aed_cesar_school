| Estrutura | Ponteiros necessários | Usa struct extra? |
| --------- | --------------------- | ----------------- |
| Lista     | 1 (`head`)            | ❌ opcional        |
| Pilha     | 1 (`topo`)            | ❌ opcional        |
| Fila      | 2 (`frente`, `atras`) | ✔ recomendado     |

struct Lista { No* head; };
struct Pilha { No* topo; };
struct Fila  { No* frente; No* atras; };