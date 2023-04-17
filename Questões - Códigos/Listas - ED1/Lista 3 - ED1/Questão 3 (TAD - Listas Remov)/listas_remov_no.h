struct nodo{
    char valor;
    struct nodo *prox;
};

typedef struct nodo Nodo;

void adicionar_Nodo(Nodo** cabeca, char valor);
void remover_Nodo_L1(Nodo* l1, int* l2, int* l3, int tamanho_l2, int tamanho_l3, char* result, int* tamanho_re);

