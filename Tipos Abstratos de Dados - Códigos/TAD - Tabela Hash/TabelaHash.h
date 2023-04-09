struct aluno{
    char nome[30];
    int matricula;
    float notas[3];

};

typedef struct hash Hash;

Hash* cria_Hash(int tamanho);
void libera_Hash(Hash* ha);
int chaveDivisao(int chave, int TABLE_SIZE);
int valorString(char* str);
int insereHash_SemColisao(Hash* ha, struct aluno al);
void buscaHash_SemColisao(Hash* ha, int mat);
int sondagemLinear(int pos, int i, int TABLE_SIZE);
int insereHash_EnderAberto(Hash* ha, struct aluno al);
void buscaHash_EnderAberto(Hash* ha, int mat);
void imprime_Hash(Hash* ha);
