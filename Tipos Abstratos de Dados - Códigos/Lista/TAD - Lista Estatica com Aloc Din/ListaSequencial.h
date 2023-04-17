#ifndef LISTASEQUENCIAL_H
#define LISTASEQUENCIAL_H
#define MAX 100

struct aluno{
    char nome[30];
    int matricula;
    float notas[3];

};

typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista_inicio(Lista* li);
int remove_lista_fim(Lista* li);
int remove_lista_otimizado(Lista* li, int mat);
void busca_lista_pos(Lista* li, int pos);
void busca_lista_mat(Lista* li, int matricula);
void imprime_lista(Lista* li);

#endif
