struct produto{
    char nome[30];
    int codigo;
    float preco;
    int qtd;
    struct produto *prox;
};

typedef struct HashEstoque Hash;

Hash* criaHash(int tamanho);
void liberaHash(Hash* ha);
int insereHash_EncSep(Hash* ha, struct produto p);
int removeHash_EncSep(Hash* ha, int codigo);
int buscaHash_EncSep(Hash* ha, int codigo);
int atualizaPreco(Hash* ha, int codigo, float preco);
void buscaMaisCaro(Hash* ha);
void imprimeHash(Hash* ha);
