struct aluno{
    char nome[30];
    int matricula;
    float notas[3];

};

typedef struct hash Hash;

Hash* criaHash(int tamanho);
void liberaHash(Hash* ha);
int valorString(char *str);
int insereHash_SemColisao(Hash* ha, struct aluno al);
int buscaHash_SemColisao(Hash* ha, int mat);
int insereHash_EnderAberto(Hash* ha, struct aluno al);
int buscaHash_EnderAberto(Hash* ha, int mat);
void imprimeHash(Hash* ha);
