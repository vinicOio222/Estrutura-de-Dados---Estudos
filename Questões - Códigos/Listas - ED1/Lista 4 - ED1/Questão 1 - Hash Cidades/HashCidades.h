#define TABLE_SIZE 30

struct cidade{
    char nome[30];
    struct cidade *prox;
};

typedef struct HashCidades Hash;

Hash* criaHash();
void liberaHash(Hash* ha);
int chaveDivisao(int chave, int tamanho);
int insereCidade(Hash* ha, struct cidade ci);
void imprimeResultados(Hash* ha);

