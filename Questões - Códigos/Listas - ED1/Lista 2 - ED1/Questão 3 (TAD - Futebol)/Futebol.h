#ifndef FUTEBOL_H
#define FUTEBOL_H

typedef struct jogador{
    char nome[30];
    int jogos;
    int gols;
    int assists;

}Jogador;

typedef struct time{
    char nome[30];
    Jogador jogadores_time[11];
    int vitorias;
    int empates;
    int derrotas;

}Time;

void atribuir_Jogador(Jogador* j, char nome[], int jogos, int gols, int assists);
void imprimir_Jogador(Jogador ji);
int bom_Jogador(Jogador  ji);
void atribuir_Time(Time *ti, char nome_time[], Jogador jogadores[], int vitorias, int empates, int derrotas);
void imprimir_Time(Time time);
void pontuacao(Time time);

#endif
