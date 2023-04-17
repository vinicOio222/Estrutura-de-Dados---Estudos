#define MAX 100

struct pilha{
    int topo;
    int dados[MAX];

};

typedef struct pilha Pilha;

void empilhar(Pilha *pi, int topo);
int desempilhar(Pilha *pi);
int converterParaDecimal(Pilha *pi, int base);

