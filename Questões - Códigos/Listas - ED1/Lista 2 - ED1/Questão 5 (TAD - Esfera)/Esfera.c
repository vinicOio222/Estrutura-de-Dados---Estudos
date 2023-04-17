#include<stdio.h>
#include<stdlib.h>
#include "Esfera.h"

struct esfera{
    float raio;

};

Esfera* cria_Esfera(float r){
    Esfera* e = (Esfera*)malloc(sizeof(Esfera));
    if(e != NULL){
        e->raio = r;
    }
    return e;

}

void libera_Esfera(Esfera *e){
    free(e);

}

void raio_Esfera(Esfera *e){
   if(e == NULL){
      printf("Erro: a esfera não foi criada!\n");
      return;
   }

   printf("Raio da Esfera: %.2f cm\n",e->raio);

}

void volume_Esfera(Esfera *e){
    if(e == NULL){
       printf("Erro: a esfera não foi criada!\n");
       return;
    }
    printf("Volume da Esfera: %.2f cm^3\n", (4*(3.14159)*(e->raio*e->raio*e->raio))/3);

}

int main(){
    float r = 2.00;
    Esfera *e = cria_Esfera(r);
    raio_Esfera(e);
    volume_Esfera(e);
    libera_Esfera(e);

    return 0;

}
