#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Futebol.h"

void atribuir_Jogador(Jogador *ji, char nome[], int jogos, int gols, int assists){
    strcpy(ji->nome, nome);
    ji->jogos = jogos;
    ji->gols = gols;
    ji->assists = assists;

}

void imprimir_Jogador(Jogador ji){
    printf("Nome: %s\n", ji.nome);
    printf("Gols: %d\n", ji.gols);
    printf("Assistências: %d\n", ji.assists);
    printf("Jogos: %d\n", ji.jogos);
    printf("-----------------------\n");


}

int bom_Jogador(Jogador ji){
    return(ji.gols > 10 || ji.assists > 5);
}

void atribuir_Time(Time *ti, char nome_time[], Jogador jogadores[], int vitorias, int empates, int derrotas){
    strcpy(ti->nome, nome_time);
    ti->vitorias = vitorias;
    ti->derrotas = derrotas;
    ti->empates = empates;
    for(int i = 0; i<11; i++){
        ti->jogadores_time[i] = jogadores[i];
    }

}

void imprimir_Time(Time ti){
    printf("\n===JOGADOR DESTAQUE===\n");
    printf("Time: %s\n", ti.nome);
    printf("Vitórias: %d\n", ti.vitorias);
    printf("Empates: %d\n", ti.empates);
    printf("Derrotas: %d\n", ti.derrotas);
    printf("-----------------------\n");
}

void pontuacao(Time ti){
    printf("Pontuação Total do Time: %d", ti.vitorias*3 + ti.empates);

}

int main()
{
    Jogador vector_jogadores[11];
    char nomes[11][50];
    int num_jogos[11], num_assistencias[11], num_gols[11];
    for (int i = 0; i < 11; i++)
    {
        printf("Insira o nome do jogador %d : ", i + 1);
        scanf("%s", &nomes[i]);
        printf("Insira a quantidade de jogos do jogador %d : ", i + 1);
        scanf("%d", &num_jogos[i]);
        printf("Insira a quantidade de gols do jogador %d : ", i + 1);
        scanf("%d", &num_gols[i]);
        printf("Insira a quantidade de assistencias do jogador %d : ", i + 1);
        scanf("%d", &num_assistencias[i]);
        printf("----------------------------------------------------------\n");
    }

    for (int i = 0; i < 11; i++)
        atribuir_Jogador(&vector_jogadores[i], nomes[i], num_jogos[i], num_gols[i], num_assistencias[i]);

    for (int i = 0; i < 11; i++)
    {
        if (bom_Jogador(vector_jogadores[i]))
            printf("%s é um bom jogador\n", vector_jogadores[i].nome);
        else
            printf("%s é um mal jogador\n", vector_jogadores[i].nome);
        printf("----------------------------------------------------------\n");
    }

    Time time1;
    int vitorias, empates, derrotas;
    char nome_do_time[50];

    printf("Insira o nome do time : ");
    scanf("%s", &nome_do_time);
    printf("Insira a quantidade de vitorias do time : ");
    scanf("%d", &vitorias);
    printf("Insira a quantidade de empates do time : ");
    scanf("%d", &empates);
    printf("Insira a quantidade de derrotas do time : ");
    scanf("%d", &derrotas);

    atribuir_Time(&time1, nome_do_time, vector_jogadores, vitorias, empates, derrotas);

    imprimir_Time(time1);
    pontuacao(time1);
    return 0;
}

