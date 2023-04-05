struct livro{
    char titulo[50];
    char autor[30];
    int id;

};

typedef struct Nodo* Pilha;

Pilha* cria_pilha();
void libera_pilha(Pilha* pi);
int insere_pilha(Pilha* pi, struct livro li);
int remove_pilha(Pilha* pi);
void consulta_pilha(Pilha* pi, int pos);
void imprime_pilha(Pilha* pi);
void tamanho_pilha(Pilha *pi);
void acessa_pilha_topo(Pilha *pi);
