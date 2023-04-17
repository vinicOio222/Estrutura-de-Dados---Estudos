#define MAX 10

struct pilha{
    int itens[MAX];
    int topo;

};

typedef struct fila Fila;
typedef struct pilha Pilha;

void criar_fila(Fila* fi);
int fila_vazia(Fila* fi);
int fila_cheia(Fila* fi);
void adicionar_fila(Fila* fi,  int valor);
int remover_fila(Fila* fi);
void imprimir_fila(Fila* fi);
void criar_pilha(Pilha* pi);
int pilha_vazia(Pilha* pi);
int pilha_cheia(Pilha* pi);
void adicionar_pilha(Pilha* pi, int valor);
int remover_pilha(Pilha* pi);
void reverter_fila(Fila* fi);




