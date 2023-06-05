struct aluno{
    char nome[30];
    int matricula;
    struct aluno *prox;
};

typedef struct hash Hash;

Hash* criaHash(int tamanho);
void liberaHash(Hash* ha);
int insereHash_EncSep(Hash* ha, char nome[30], int mat);
int removeHash_EncSep(Hash* ha, int mat);
int buscaHash_EncSep(Hash* ha, int valor);
float mediaMatriculas(Hash* ha);
void imprimeHash(Hash* ha);
