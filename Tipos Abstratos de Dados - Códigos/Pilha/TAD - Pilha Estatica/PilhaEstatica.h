#define MAX 100

struct livro{
    char titulo[50];
    char autor[30];
    int id;

};

typedef struct pilha Pilha;

Pilha* cria_pilha();
void libera_pilha(Pilha* pi);
int insere_pilha(Pilha* pi, struct livro li);
int remove_pilha(Pilha* pi);
void consulta_pilha(Pilha* pi, int pos);
void imprime_pilha(Pilha* pi);
void tamanho_pilha(Pilha *pi);
void acessa_topo_pilha(Pilha *pi);
