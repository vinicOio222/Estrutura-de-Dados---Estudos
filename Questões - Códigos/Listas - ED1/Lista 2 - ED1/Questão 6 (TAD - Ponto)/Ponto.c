#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Ponto.h"

struct ponto{
    float x;
    float y;

};

Ponto* Ponto_cria(float x, float y){
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));
    if(p != NULL){
        p->x = x;
        p->y = y;
    }
    return p;
}

void Ponto_libera(Ponto* p){
    free(p);
}

int Ponto_acessa(Ponto* p, float* x, float* y){
    if(p == NULL)
       return 0;
    *x = p->x;
    *y = p->y;
    return 1;
}

float Ponto_distancia(Ponto* p1, Ponto* p2){
    if(p1 == NULL || p2 == NULL)
       return -1;
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

void Ponto_soma(Ponto* p1, Ponto* p2){
    if(p1 == NULL || p2 == NULL){
       printf("Erro: Um ou dois pontos não criados!\n");
       return;
    }
    Ponto soma;
    soma.x = p1->x + p2->x;
    soma.y = p1->y + p2->y;
    printf("\n === Soma de Pontos === \n");
    printf("x = %.2f\n", soma.x);
    printf("y = %.2f\n", soma.y);
    return;

}

void Ponto_subtracao(Ponto* p1, Ponto* p2){
    if(p1 == NULL || p2 == NULL){
       printf("Erro: Um ou dois pontos não criados!\n");
       return;
    }
    Ponto sub;
    sub.x = p1->x - p2x;
    sub.y = p1->y - p2->y;
    printf("\n === Subtração de Pontos === \n");
    printf("x = %.2f\n", sub.x);
    printf("y = %.2f\n", sub.y);
    return;

}

int main(){
    float d;
    Ponto* p, *q;
    float x1, x2, y1, y2;
    printf("Insira os parâmetros do primeiro ponto:\n");
    scanf("%f",&x1);
    scanf("%f",&y1);
    printf("Insira os parâmetros do segundo ponto:\n");
    scanf("%f",&x2);
    scanf("%f",&y2);
    p = Ponto_cria(x1, y1);
    q = Ponto_cria(x2, y2);
    d = Ponto_distancia(p, q);
    printf("Distância entre os dois pontos: %.2f", d);
    Ponto_soma(p,q);
    Ponto_subtracao(p,q);
    Ponto_libera(p);
    Ponto_libera(q);

    return 0;
}

