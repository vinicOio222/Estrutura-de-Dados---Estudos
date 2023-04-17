#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "NumCompl.h"

struct complexo{
    float x;
    float y;

};

Complexo* criar_complexo(float real, float imag){
    Complexo* c = (Complexo*)malloc(sizeof(Complexo));
    if(c == NULL){
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    c->x = real;
    c->y = imag;
    return c;
}

void destruir_complexo(Complexo* c){
    free(c);

}

void somar_complexos(Complexo *c1, Complexo *c2){
    if(c1 == NULL || c2 == NULL){
        printf("Um ou os dois números complexos não foram gerados!\n");
        exit(1);
    }
    Complexo soma;
    soma.x = c1->x + c2->x;
    soma.y = c1->y + c2->y;
    if(soma.y < 0){
       printf("Soma dos Complexos: %.2f + (%.2fi)\n",soma.x,soma.y);
    }else{
       printf("Soma dos Complexos: %.2f + %.2fi\n",soma.x,soma.y);

    }
}

void multiplicar_complexos(Complexo *c1, Complexo *c2){
    if(c1 == NULL || c2 == NULL){
        printf("Um ou os dois números complexos não foram gerados!\n");
        exit(1);
    }
    Complexo mult;
    mult.x = c1->x*c2->x - c1->y*c2->y;
    mult.y = c1->x*c2->y + c1->y*c2->x;
    if(mult.y < 0){
       printf("Produto dos Complexos: %.2f + (%.2fi)\n",mult.x,mult.y);
    }else{
       printf("Produto dos Complexos: %.2f + %.2fi\n",mult.x,mult.y);

    }

}

int main(){
    Complexo *c1, *c2;
    c1 = criar_complexo(2,3);
    c2 = criar_complexo(1,-4);
    somar_complexos(c1, c2);
    multiplicar_complexos(c1,c2);
    destruir_complexo(c1);
    destruir_complexo(c2);

    return 0;
}
