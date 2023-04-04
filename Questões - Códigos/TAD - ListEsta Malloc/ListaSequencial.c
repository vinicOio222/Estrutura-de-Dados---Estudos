#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "ListaSequencial.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];

};

Lista* cria_lista(){
    Lista* li;
    li = (Lista*)malloc(sizeof(struct lista));
    if(li != NULL)
       li->qtd = 0;
    return li;
}

void libera_lista(Lista* li){
    free(li);

}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li != NULL)
       return 0;
    if(li->qtd-1 >= MAX)
       return 0;
    int i;
    for(int i = li->qtd-1; i >= 0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;

}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
       return 0;
    if(li->qtd == MAX)
       return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;

}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
       return 0;
    if(li->qtd - 1 == MAX)
       return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula < al.matricula)
       i++;
    for(k=li->qtd-1;k>=i; k--)
       li->dados[k+1] = li->dados[k];
    li->dados[i] = al;
    li->qtd++;
    return 1;
}

int remove_lista_fim(Lista* li){
    if(li == NULL)
       return 0;
    if(li->qtd == 0)
      return 0;
    li->qtd--;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
       return 0;
    if(li->qtd == 0)
      return 0;
    for(int i = 0; i<li->qtd-1; i++)
        li->dados[i] = li->dados[i+1];
    li->qtd--;
    return 1;
}

int remove_lista_otimizado(Lista* li, int mat){
    if(li == NULL)
       return 0;
    if(li->qtd == 0)
       return 0;
    int i =0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
       return 0;
    li->qtd--;
    li->dados[i] = li->dados[li->qtd];
    return 1;
}

void imprime_lista(Lista* li){
    if(li == NULL)
       return 0;
    printf("\n====LISTA DE ALUNOS====\n");
    for(int i = 0; i<li->qtd; i++){
        printf("Nome: %s\n", li->dados[i].nome);
        printf("Matricula: %d\n", li->dados[i].matricula);
        printf("Notas: %.2f, %.2f, %.2f\n", li->dados[i].notas[0],li->dados[i].notas[1], li->dados[i].notas[2]);
        printf("\n");
    }

}

void tamanho_lista(Lista* li){
    printf("\nTamanho da lista: %d\n\n", li->qtd);

}

void busca_lista_pos(Lista* li, int pos){
    if(li->qtd == 0)
      printf("Lista vazia!");
    if(pos >= 0 && pos < li->qtd){
        printf("\n==ALUNO ENCONTRADO==\n\n");
        printf("Nome: %s\n",li->dados[pos].nome);
        printf("Matricula: %d\n",li->dados[pos].matricula);
        printf("Notas: %.2f, %.2f, %.2f\n", li->dados[pos].notas[0],li->dados[pos].notas[1], li->dados[pos].notas[2]);
        printf("\n");
    }else{
        printf("Aluno com posicao %d nao encontrado na lista!",pos);
    }
}

void busca_lista_mat(Lista* li, int mat){
    if(li->qtd == 0)
       printf("Lista vazia!\n");
    for(int i = 0; i<li->qtd; i++){
        if(mat == li->dados[i].matricula){
            printf("\n===ALUNO ENCONTRADO===\n");
            printf("Nome: %s\n", li->dados[i].nome);
            printf("Matricula: %d\n", li->dados[i].matricula);
            printf("Notas: %.2f, %.2f, %.2f\n", li->dados[i].notas[0],li->dados[i].notas[1], li->dados[i].notas[2]);
            printf("\n");
            break;

        }else{
            printf("Aluno com matricula %d nao encontrado!\n",mat);
            break;
        }
    }

}


int main(){
    Lista* li = cria_lista();
    struct aluno a1,a2,a3;
    strcpy(a1.nome, "Vini");
    a1.matricula = 1612520;
    a1.notas[0] = 6.0;
    a1.notas[1] = 5.0;
    a1.notas[2] = 9.0;
    strcpy(a2.nome, "Gabryella");
    a2.matricula = 1612521;
    a2.notas[0] = 6.0;
    a2.notas[1] = 5.0;
    a2.notas[2] = 9.0;
    strcpy(a3.nome, "Diogo");
    a3.matricula = 1612442;
    a3.notas[0] = 6.0;
    a3.notas[1] = 5.0;
    a3.notas[2] = 9.0;
    insere_lista_ordenada(li, a1);
    insere_lista_ordenada(li, a2);
    insere_lista_ordenada(li, a3);
    imprime_lista(li);
    tamanho_lista(li);
    remove_lista_otimizado(li, 1612520);
    imprime_lista(li);
    tamanho_lista(li);
    busca_lista_pos(li,1);

    libera_lista(li);
    return 0;

}
