struct nodo{
    int dados;
    struct nodo* ant;
    struct nodo* prox;

};

typedef struct nodo Nodo;
typedef struct lista_enc ListaEnc;

ListaEnc* cria_lista_dupl();
void inserir_elemento_final(ListaEnc *li, int valor);
void remover_elemento_inicio(ListaEnc* li);
void imprimir_lista(ListaEnc* li);

