struct aluno{
    char nome[30];
    int matricula;
    float notas[3];

};

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
void consulta_Fila(Fila* fi, int pos);
void imprime_Fila(Fila* fi);
void tamanho_Fila(Fila* fi);

