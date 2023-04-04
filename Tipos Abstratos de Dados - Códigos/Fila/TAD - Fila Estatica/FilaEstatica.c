#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "FilaEstatica.h"

struct fila{
    int inicio, final, qtd;
    struct aluno dados[MAX];

};

Fila* cria_Fila(){
    Fila *fi;
    fi = (Fila*)malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    free(fi);

}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
       return 0;
    if(fi->qtd - 1 == MAX)
       return 0;
    fi->dados[fi->final] = al;
    fi->final = (fi->final + 1) % MAX;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL || fi->qtd == 0)
       return 0;
    fi->inicio = (fi->inicio + 1) % MAX;
    fi->qtd--;
    for(int i = 0; i<fi->qtd; i++){
        fi->dados[i] = fi->dados[i+1];
    }
    return 1;

}

void consulta_Fila(Fila* fi, int pos){
    if(fi == NULL || fi->qtd == 0)
       printf("Erro: a fila não foi criada!\n");
    if(pos >= 0 && pos < fi->qtd){
        printf("\n==ALUNO ENCONTRADO==\n\n");
        printf("Nome: %s\n",fi->dados[pos].nome);
        printf("Matricula: %d\n",fi->dados[pos].matricula);
        printf("Notas: %.2f, %.2f, %.2f\n", fi->dados[pos].notas[0],fi->dados[pos].notas[1], fi->dados[pos].notas[2]);
        printf("\n");
    }else{
        printf("Aluno com posicao %d nao encontrado na fila!",pos);
    }
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
       printf("Erro: a fila não foi criada!\n");
    printf("\n====LISTA DE ALUNOS====\n");
    for(int i = 0; i<fi->qtd; i++){
        printf("Nome: %s\n", fi->dados[i].nome);
        printf("Matricula: %d\n", fi->dados[i].matricula);
        printf("Notas: %.2f, %.2f, %.2f\n", fi->dados[i].notas[0],fi->dados[i].notas[1], fi->dados[i].notas[2]);
        printf("-----------------------\n");
    }

}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
       return 0;
    return fi->qtd;

}

int main(){
    Fila* queue = cria_Fila();
    struct aluno a1, a2, a3;
    strcpy(a1.nome, "Vinicius");
    a1.matricula = 1612520;
    a1.notas[0] = 10;
    a1.notas[1] = 7.87;
    a1.notas[2] = 8.95;
    strcpy(a2.nome, "Matheus");
    a2.matricula = 1034485;
    a2.notas[0] = 10;
    a2.notas[1] = 9.87;
    a2.notas[2] = 9.98;
    strcpy(a3.nome, "Clara");
    a3.matricula = 1737801;
    a3.notas[0] = 8;
    a3.notas[1] = 7.87;
    a3.notas[2] = 7.95;
    insere_Fila(queue, a1);
    insere_Fila(queue, a2);
    insere_Fila(queue, a3);
    consulta_Fila(queue, 0);
    imprime_Fila(queue);
    printf("Tamanho da fila: %d\n",tamanho_Fila(queue));
    remove_Fila(queue);
    imprime_Fila(queue);
    printf("Tamanho da fila: %d\n",tamanho_Fila(queue));
    consulta_Fila(queue,0);
    libera_Fila(queue);

    return 0;

}
