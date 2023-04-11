#ifndef LISTAS_COPIAR_H
#define LISTAS_COPIAR_H
#define MAX 100

typedef struct {
    int dados;
}nodo;

typedef struct{
    nodo arr[MAX];
    int tamanho;
}lista_est;

typedef struct nodos_lista{
    nodo dados;
    struct nodos_lista* prox;

}nodos_lista;

typedef struct{
    nodos_lista* cabeca;
    int tamanho;

}lista_din;

int contem_elemento_din(nodos_lista* cabeca, nodo no);
int contem_elemento_est(nodo* arr, int tamanho, nodo no);
void adicionar_din(lista_din* din, nodo no);
void adicionar_est(lista_est* est, nodo no);
void copiar_Est_para_Din(lista_est* est, lista_din* din);
void copiar_Din_para_Est(lista_din* din, lista_est* est);

#endif
