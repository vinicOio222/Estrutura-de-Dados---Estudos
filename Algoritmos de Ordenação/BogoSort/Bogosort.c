#include<stdio.h>
#include<stdlib.h>

int is_sorted(int *a, int n){
    while(--n >= 1){
        if(a[n] < a[n-1])
            return 0;
    }
    return 1;
}

void shuffle(int *a, int n){
    int t, temp;
    for(int i = 0; i<n; i++){
        t = a[i];
        temp = rand() % n;
        a[i] = a[temp];
        a[temp] = t;
    }
}

void bogosort(int *a, int n){
    int iteration = 0;
    while(!is_sorted(a,n)){
        printf("Iteração %d: ", iteration);
        for(int i = 0; i<n; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
        shuffle(a,n);
        iteration++;
    }
}

int main(){
    int numbers[] = {5,4,3,2,1,0};
    bogosort(numbers, 6);
    printf("Array Ordenado:\n");
    for(int i = 0; i<6; i++)
        printf("%d ", numbers[i]);
    printf("\n");

}
