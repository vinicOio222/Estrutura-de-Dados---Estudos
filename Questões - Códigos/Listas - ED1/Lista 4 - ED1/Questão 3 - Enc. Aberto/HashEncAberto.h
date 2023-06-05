struct item{
    int valor;
};

typedef struct hash Hash;

Hash* criaHash(int tamanho);
void liberaHash(Hash* ha);
int insereHash_EnderAberto(Hash* ha, int valor);
int buscaHash_EnderAberto(Hash* ha, int valor);
void imprimeHash(Hash* ha);
