struct aluno{
    char nome[30];
    int matricula;
    float notas[3];
    struct aluno *prox;
};

typedef struct hash Hash;

Hash* criaHash(int tamanho);
void liberaHash(Hash* ha);
int valorString(char* str);
int insereHash_EncSep(Hash* ha, struct aluno al);
int buscaHash_EncSep(Hash* ha, int mat);
void imprimeHash(Hash* ha);
