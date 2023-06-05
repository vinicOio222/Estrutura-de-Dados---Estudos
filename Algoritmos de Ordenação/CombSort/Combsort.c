#include<stdio.h>

void comb_sort(int vetor[], int tamanho){
    int trocado = 1;
    int aux, intervalo, cont = 0;
    intervalo = tamanho;
    while(intervalo > 1 || trocado == 1){
        intervalo = intervalo * 10/13;
        if(intervalo == 9 || intervalo == 10)
           intervalo = 11;
        if(intervalo < 1)
           intervalo = 1;
        trocado = 0;
        for(int i = 0, j = intervalo; j < tamanho; i++, j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
                trocado = 1;
            }
        }
        printf("Iteração %d: ", cont);
        for(int k = 0; k<tamanho; k++)
            printf("%d ", vetor[k]);
        printf("\n");
        cont++;
    }
}

int main(){
    int numbers[] = {10,4,5,3,87,1,2,2,4,19};
    comb_sort(numbers, 10);
    printf("Array Ordenado:\n");
    for(int i = 0; i<10; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}
