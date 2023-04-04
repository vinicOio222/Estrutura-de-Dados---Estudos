#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ListaDinEnc.h"

struct Nodo{
    struct aluno dados;
    struct Nodo *prox;
};

typedef struct Nodo nodo;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
       *li = NULL;
    return li;

}

void libera_lista(Lista* li){
    if(li != NULL){
       nodo* no;
       while((*li) != NULL){
         no = *li;
         *li = (*li)->prox;
         free(no);
       }
       free(li);
    }

}

int tamanho_lista(Lista* li){
    if(li == NULL)
       return 0;
    int cont = 0;
    nodo* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;

}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
       return 0;
    nodo* no;
    no = (nodo*)malloc(sizeof(nodo));
    if(no == NULL)
       return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
       return 0;
    nodo* no;
    no = (nodo*)malloc(sizeof(nodo));
    if(no == NULL)
       return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    }else{
        nodo* aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;

}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
       return 0;
    nodo* no;
    no = (nodo*)malloc(sizeof(nodo));
    if(no == NULL)
       return 0;
    no->dados = al;
    if((*li) == NULL){
        no->prox = NULL;
        *li = no;
        return 1;
    }else{
        nodo *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
       return 0;
    if((*li) == NULL)
       return 0;
    nodo* no = *li;
    *li = no->prox;
    free(no);
    return 1;

}

int remove_lista_final(Lista* li){
    if(li == NULL)
       return 0;
    if((*li) == NULL)
       return 0;
    nodo *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li))
       *li = no->prox;
    else
       ant->prox = no->prox;
    free(no);
    return 1;

}

int remove_lista_mat(Lista* li, int mat){
    if(li == NULL)
       return 0;
    if((*li) == NULL)
       return 0;
    nodo *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)
       return 0;
    if(no == *li)
       *li = no->prox;
    else
       ant->prox = no->prox;
    free(no);
    return 1;

}

int remove_lista_pos(Lista* li, int pos){
    if (li == NULL)
        return 0;
    int tam = tamanho_lista(li);
    if (pos <= 0 || pos > tam)
        return 0;
    nodo *ant, *no = *li;
    for (int i = 1; i < pos; i++) {
        ant = no;
        no = no->prox;
    }
    if (no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;

}

void busca_lista_mat(Lista* li, int mat){
    if(li == NULL)
       printf("Erro: Lista não criada!");
    nodo *no = *li;
    while(no != NULL &&  no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        printf("Aluno com matrícula %d não encontrado!\n", mat);
    else{
        printf("\n===ALUNO ENCONTRADO===\n");
        printf("Nome: %s\n", no->dados.nome);
        printf("Matrícula: %d\n", no->dados.matricula);
        printf("Notas: %.2f, %.2f, %.2f\n", no->dados.notas[0], no->dados.notas[1], no->dados.notas[2]);
        printf("\n");
    }
}

void busca_lista_pos(Lista* li, int pos){
    if(li == NULL)
    printf("Erro: Lista não criada!");
    nodo *no = *li;
    int i = 1;
    while(no != NULL && i<pos){
        no = no->prox;
        i++;
    }
    if(no == NULL || pos <= 0 )
      printf("Aluno com posição %d não encontrado na lista!\n", pos);
    else{
        printf("\n===ALUNO ENCONTRADO===\n");
        printf("Nome: %s\n", no->dados.nome);
        printf("Matrícula: %d\n", no->dados.matricula);
        printf("Notas: %.2f, %.2f, %.2f\n", no->dados.notas[0], no->dados.notas[1], no->dados.notas[2]);
        printf("\n");
    }

}

void imprime_lista(Lista* li){
    if(li == NULL)
       printf("Erro: Lista não criada!");
    nodo *no = *li;
    printf("\n===LISTA DE ALUNOS===\n");
    while(no != NULL){
        printf("Nome: %s\n", no->dados.nome);
        printf("Matrícula: %d\n", no->dados.matricula);
        printf("Notas: %.2f, %.2f, %.2f\n", no->dados.notas[0], no->dados.notas[1], no->dados.notas[2]);
        printf("\n");
        no = no->prox;
    }
}

int main(){
    Lista* li = cria_lista();
    struct aluno a1, a2, a3;
    strcpy(a1.nome,"Vinícius");
    a1.matricula = 1612520;
    a1.notas[0] = 8.50;
    a1.notas[1] = 9.2;
    a1.notas[2] = 6.9;
    strcpy(a2.nome,"Kalil");
    a2.matricula = 1612521;
    a2.notas[0] = 8.50;
    a2.notas[1] = 9.2;
    a2.notas[2] = 6.9;
    strcpy(a3.nome,"Holanda");
    a3.matricula = 1612519;
    a3.notas[0] = 8.50;
    a3.notas[1] = 9.2;
    a3.notas[2] = 6.9;
    insere_lista_ordenada(li, a1);
    insere_lista_ordenada(li, a2);
    insere_lista_ordenada(li, a3);
    busca_lista_pos(li, 1);
    imprime_lista(li);
    printf("Tamanho da lista: %d\n",tamanho_lista(li));
    remove_lista_pos(li, 1);
    remove_lista_mat(li, 1612520);
    imprime_lista(li);
    printf("Tamanho da lista: %d",tamanho_lista(li));
    libera_lista(li);

    return 0;


}
