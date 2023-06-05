struct item{
    int valor;
    struct item *prox;
};

typedef struct HashEnc Hash;
Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int insereHash_EncSep(Hash* ha, int valor);
int removeHash(Hash* ha, int valor);
void buscaHash_EncSep(Hash* ha, int valor);
void imprimeHash(Hash* ha);

