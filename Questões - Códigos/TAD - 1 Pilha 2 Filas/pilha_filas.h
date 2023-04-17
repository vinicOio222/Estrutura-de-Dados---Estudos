#define MAX 100

struct fila{
    int dados[MAX];
    int inicio;
    int final;

};

typedef struct fila Fila;
typedef struct pilha Pilha;

Fila* criarFila();
void enfileirar(Fila* s, int elemento);
int desenfileirar(Fila* fi);
int filaVazia(Fila* fi);
int filaCheia(Fila* fi);
void liberaFila(Fila* fi);

Pilha* criarsPilha();
int pilhaVazia(Pilha* pi);
void empilhar(Pilha* pi, int elemento);
int desepilhar(Pilha* pi);
int topoPilha(Fila* fi);
void liberaPilha(Pilha* fi);


