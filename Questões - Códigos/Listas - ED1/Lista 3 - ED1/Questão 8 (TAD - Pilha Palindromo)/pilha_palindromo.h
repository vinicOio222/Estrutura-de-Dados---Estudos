#define MAX 100

struct pilha{
    int topo;
    char dados[MAX];
};

typedef struct pilha Pilha;

void empilhar(Pilha *pi, char caracter);
int desempilhar(Pilha *pi);
char topoPilha(Pilha *pi);
int pilhaVazia(Pilha *pi);
int eUmPalindromo(char *palavra);
