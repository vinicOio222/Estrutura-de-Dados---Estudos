#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"TabelaHash.c"
#include<Windows.h>

int main(){
    int tableSize;
    printf("\n ~ Insira a quantidade de contatos para o Catalogo de Registros: ");
    scanf("%d",&tableSize);
    Hash* ha = criaHash(tableSize);

    int op;
    int DDD, telefone;
    char nome[30], endereco[50];
    int buscaTel, DDDBusca;

    do {
        int flag = 0;

        printf("::::::: Bem-vindo(a) ao Sistema Nacional Catalogo de Contatos Telefonicos :::::::\n\n");
        printf("[1] - Inserir um Contato;\n");
        printf("[2] - Pesquisar Contato;\n");
        printf("[3] - Remover um Contato;\n");
        printf("[4] - Exibir Catalogo de Registros;\n");
        printf("[5] - Exibir Contatos de um DDD;\n");
        printf("[6] - Listar Contatos de um DDD;\n");
        printf("[7] - Busca Aproximada;\n");
        printf("[8] - Sair;\n\n");

        printf("Escolha uma operacao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                system("cls || clear");
                printf("\n\n++++ Inserir Contato ++++\n\n");
                printf("Insira o DDD:");
                scanf("%d", &DDD);
                getchar();

                while(flag == 0){
                    inicializaGeradorAleatorio();
                    int num1 = geraTelefones();
                    int num2 = geraTelefones();
                    int num3 = geraTelefones();

                    if(geraSugestao(ha, DDD, num1) == 0 && geraSugestao(ha, DDD, num2) == 0 && geraSugestao(ha, DDD, num3) == 0){
                        inicializaGeradorAleatorio();
                        num1 = geraTelefones();
                        num2 = geraTelefones();
                        num3 = geraTelefones();
                    }

                    int opNum;
                    printf("Escolha um dos Telefones para o cadastro, se preferir:\n");
                    printf("Sugestao [1] de Tel: %d\n", num1);
                    printf("Sugestao [2] de Tel: %d\n", num2);
                    printf("Sugestao [3] de Tel: %d\n", num3);
                    printf("Insira 0 se quiser criar seu proprio numero\n");
                    printf("\nOpcao: ");
                    scanf("%d", &opNum);
                    getchar();

                    if(opNum == 1){
                        telefone = num1;
                    }else if(opNum == 2){
                        telefone = num2;
                    }else if(opNum == 3){
                        telefone = num3;
                    }else if(opNum == 0){
                        printf("\nDigite o numero de telefone: ");
                        scanf("%d", &telefone);
                        getchar();
                    }else{
                        printf("Operação Inválida!\n");
                    }

                    printf("\nInsira o nome do contato: ");
                    fgets(nome, sizeof(nome), stdin);
                    nome[strcspn(nome, "\n")] = '\0';

                    printf("\nInsira o endereco do contato: ");
                    fgets(endereco, sizeof(endereco), stdin);
                    endereco[strcspn(endereco, "\n")] = '\0';

                    if(verificaDuplicatas(ha, telefone, nome) == 0){
                        flag = 1;
                    }
                }
                insereContato_Hash(ha, DDD, telefone, nome, endereco);
                printf("\nContado Adicionado com sucesso! Retornando ao Menu Principal...\n");
                Sleep(4000);
                system("cls || clear");
                break;
            case 2:
                system("cls || clear");
                printf("\n\n===== Buscar Contato =====\n\n");
                printf("Insira o DDD do Contato: ");
                scanf("%d", &DDDBusca);
                getchar();
                printf("\nInsira o numero de Telefone do Contato: ");
                scanf("%d", &buscaTel);
                getchar();
                struct Usuario* res = buscaContato_Hash(ha, DDDBusca, buscaTel);
                if(res != NULL){
                    printf("\n\n----- Contato Encontrado -----\n\n");
                    printf("DDD: %d\n", DDDBusca);
                    printf("Telefone: %d\n", res->telefone);
                    printf("Nome: %s\n", res->nome);
                    printf("Endereco: %s\n\n", res->endereco);

                }else {
                    printf("Contato nao encontrado!\n");
                }
                break;
            case 3:
                system("cls || clear");
                printf("\n\n---- Remover Contato ----\n\n");
                printf("\nInsira o DDD do contato: ");
                scanf("%d", &DDDBusca);
                getchar();

                printf("\nInsira o telefone do contato: ");
                scanf("%d", &buscaTel);
                getchar();

                removeContato_Hash(ha, DDDBusca, buscaTel);
                Sleep(4000);
                system("cls || clear");
                break;
            case 4 :
                system("cls || clear");
                imprimeHash_emOrdem(ha);
                break;
            case 5:
                system("cls || clear");
                printf("\nInsira o DDD: ");
                scanf("%d", &DDDBusca);
                getchar();
                int posA  = metodoDivisao(ha->TABLE_SIZE, DDD);
                struct HashNo * atualA = ha->itens[posA];
                if(atualA == NULL){
                    printf("Posicao vazia no Catalogo!\n");
                    return 0;
                }
                while(atualA != NULL){
                    if(DDDBusca == atualA->DDD){
                        printf("\n\n..... Escolha como deseja exibir os contatos do DDD %d .....\n\n", DDD);
                        printf("1 - Pre-Ordem;\n");
                        printf("2 - Em-Ordem;\n");
                        printf("3 - Pos-Ordem;\n\n");
                        printf("Opcao: ");
                        scanf("%d", &op);
                        if(op == 1){
                            system("cls || clear");
                            preOrdem_DDD(ha, DDDBusca);
                        }else if(op == 2){
                            system("cls || clear");
                            emOrdem_DDD(ha, DDDBusca);
                        }else if (op == 3) {
                            system("cls || clear");
                            posOrdem_DDD(ha, DDDBusca);
                        }else{
                            printf("Opcao invalida!\n");
                        }
                    }else{
                        printf("DDD %d nao cadastrado!\n", DDDBusca);
                    }
                    atualA = atualA->prox;
                }
                break;
            case 6:
                system("cls || clear");
                printf("Insira o DDD: ");
                scanf("%d", &DDDBusca);
                getchar();
                int posB = metodoDivisao(ha->TABLE_SIZE, DDDBusca);
                struct HashNo* atualB = ha->itens[posB];
                while(atualB != NULL){
                    if(DDDBusca == atualB->DDD){
                        printf("\n\n#### Escolha como deseja listar os contatos do DDD %d ####\n\n", DDD);
                        printf("1 - Em Ordem Alfabetica de Nome;\n");
                        printf("2 - Em Ordem Crescente de Telefone;\n");
                        printf("Opcao: ");
                        scanf("%d", &op);
                        if(op == 1){
                            system("cls || clear");
                            exibirListaNomes(ha, DDDBusca);
                        }else if(op == 2){
                            system("cls || clear");
                            exibirListaNumeros(ha, DDDBusca);
                        }else{
                            printf("Opcao invalida!\n");
                        }
                    }else{
                        printf("DDD %d nao cadastrado!\n", DDDBusca);
                    }
                    atualB = atualB->prox;
                }
                break;
            case 7:
                system("cls || clear");
                printf("\n\n ,,,,, Busca Aproximada ,,,,,\n\n");
                printf("~ Insira os parte dos digitos do(s) telefone(s): ");
                scanf("%d", &buscaTel);
                buscaAproximadaNumero(ha, buscaTel);
                break;
            case 8:
                printf("\nSaindo do Sistema...Ate logo.\n");
                break;
            default:
                printf("\nOpcao invalida!\nTente novamente uma operacao valida!\n");
                break;

        }

    }while(op != 8);

    return 0;
}
