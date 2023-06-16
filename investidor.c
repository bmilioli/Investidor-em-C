#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "investidor.h"
#define MAX_INVESTIDORES 100

investidor lista[MAX_INVESTIDORES];
int num_investidores = 0;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int verificar_id(int n) {
    for (int i = 0; i < num_investidores; i++) {
        if (lista[i].id == n) {
            return 0;  // ID já existe
        }
    }
    return 1;  // ID válido
}



investidor criar_investidor(int id, char* nome, dn data, char cpf[12], float patrimonio) {
    investidor investidor;
    investidor.id = id;

    // Alocar memória para o nome e copiar o valor fornecido
    investidor.nome = malloc(255* sizeof(char));
    if (nome == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(investidor.nome, nome);
    investidor.data = data;
    strcpy(investidor.cpf, cpf);
    investidor.patrimonio = patrimonio;

    return investidor;
}

//FUNÇÃO PARA INSERIR INVESTIDOR
void inserir_pessoa() {
    if (num_investidores < MAX_INVESTIDORES) {
        printf("Digite o ID:\n");
        scanf("%d", &lista[num_investidores].id);

        if (verificar_id(lista[num_investidores].id) == 0) {
            printf("ID já existente. Não é possível inserir o investidor.\n");
            return;
        }
        limparBuffer();

        printf("Digite o nome do investidor:\n");
        char nome[150];
        fgets(nome, 150, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        printf("Digite a data de nascimento:\n");
        scanf("%d", &lista[num_investidores].data.dia);
        getchar();
        scanf("%d", &lista[num_investidores].data.mes);
        getchar();
        scanf("%d", &lista[num_investidores].data.ano);
        getchar();

        printf("Digite o CPF\n");
        fgets(lista[num_investidores].cpf, 12, stdin);
        lista[num_investidores].cpf[strcspn(lista[num_investidores].cpf, "\n")] = '\0';

        printf("Digite o patrimônio:\n");
        scanf("%f", &lista[num_investidores].patrimonio);

        // Criar o investidor usando a função criar_investidor
        lista[num_investidores] = criar_investidor(lista[num_investidores].id, nome, lista[num_investidores].data, lista[num_investidores].cpf, lista[num_investidores].patrimonio);

        // Incrementar o contador de investidores
        num_investidores++;
        printf("Investidor inserido com sucesso!\n");
    }
    else {
        printf("Limite máximo de investidores atingido. Não é possível inserir mais investidores.\n");
    }
}





/*

void inserir_pessoa() {
    if (num_investidores < MAX_INVESTIDORES) {
        printf("Digite o ID:\n");
        scanf("%d", &lista[num_investidores].id);

        if (verificar_id(lista[num_investidores].id) == 0) {
            printf("ID já existente. Não é possível inserir o investidor.\n");
            return;
        }
        limparBuffer();
        // lista[num_investidores].nome = malloc(100 * sizeof(char));
        printf("Digite o nome do investidor:\n");
        fgets(lista[num_investidores].nome, 150, stdin);
        lista[num_investidores].nome[strcspn(lista[num_investidores].nome, "\n")] = '\0';

        printf("Digite a data de nascimento:\n");
        scanf("%d", &lista[num_investidores].data.dia);
          getchar();
        scanf("%d", &lista[num_investidores].data.mes);
          getchar();
        scanf("%d", &lista[num_investidores].data.ano);
          getchar();

        printf("Digite o CPF\n");
        fgets(lista[num_investidores].cpf, 12, stdin);
        lista[num_investidores].cpf[strcspn(lista[num_investidores].cpf, "\n")] = '\0';

        printf("Digite o patrimônio:\n");
        scanf("%f", &lista[num_investidores].patrimonio);

        // Incrementar o contador de investidores
        num_investidores++;
        printf("Investidor inserido com sucesso!\n");
    } else {
        printf("Limite máximo de investidores atingido. Não é possível inserir mais investidores.\n");
    }
}
*/


//FUNÇÃO PARA LISTAR INVESTIDORES
void listar() {
    if (num_investidores == 0) {
        printf("Nenhum investidor cadastrado.\n");
        return;
    }

    printf("Lista de Investidores:\n");
    printf("----------------------\n");

    for (int i = 0; i < num_investidores; i++) {
        printf("ID: %d\n", lista[i].id);
        printf("Nome: %s\n", lista[i].nome);
        printf("Data de Nascimento: %d/%d/%d\n", lista[i].data.dia, lista[i].data.mes, lista[i].data.ano);
        printf("CPF: %s\n", lista[i].cpf);
        printf("Patrimônio: R$ %.2f\n", lista[i].patrimonio);
        printf("----------------------\n----------------------\n");
    }
}

void alterar() {
    int funcao2;
    int escolha;
    char* novo_nome;
    char nome_proximo[100];
    char novo_cpf[12];


    printf("-----------------\nTela de alteração:\nEscolha qual dado você gostaria de alterar:\n-----------------\n");
    printf("0 - Sair\n1 - Nome\n2 - CPF\n3 - Data de Nascimento\n4 - Patrimônio\n");
    scanf("%d", &funcao2);
    // listar();
    switch (funcao2) {
        case 1:
            printf("Digite o ID do usuário:\n");
            scanf("%d", &escolha);
            scanf("%*[^\n]");
            scanf("%*c");
            novo_nome = malloc(255*sizeof(char));
            if (novo_nome == NULL) {
                printf("Erro ao alocar memória.\n");
                exit(1);
            }
            fgets(novo_nome, 255, stdin);
            novo_nome[strcspn(novo_nome, "\n")] = '\0';
            printf("\n\n\n\n");
            // listar();

            for (int i = 0; i < num_investidores; i++) {

                if (lista[i].id == escolha) {
                    if(i + 1 < num_investidores){
                        strcpy(nome_proximo, lista[i+1].nome);
                    }

                    strncpy(lista[i].nome, novo_nome, 150);
                    lista[i+1].nome[255 - 1] = '\0';
                    printf("Nome alterado com sucesso!\n");

                    if(i + 1 < num_investidores){
                        strncpy(lista[i+1].nome,nome_proximo,255);
                    }

                }
            }
            break;



        case 2 :
            printf("Digite o ID do usuário:\n");
            scanf("%d", &escolha);
            limparBuffer();
            for (int i = 0; i < num_investidores; i++) {
                if (lista[i].id == escolha) {
                    printf("Digite o novo CPF:\n");
                    fgets(novo_cpf, 12,stdin);
                    strcpy(lista[i].cpf, novo_cpf);
                }
            }
            break;


        case 3 :
            printf("Digite o ID do usuário:\n");
            scanf("%d", &escolha);
            for (int i = 0; i < num_investidores; i++) {
                if (lista[i].id == escolha) {
                    printf("Digite a data de nascimento corrigida:\n");
                    scanf("%d", &lista[i].data.dia);
                    getchar();
                    scanf("%d", &lista[i].data.mes);
                    getchar();
                    scanf("%d", &lista[i].data.ano);
                    getchar();
                }
            }

            break;


        case 4 :
            printf("Digite o ID do usuário:\n");
            scanf("%d", &escolha);
            for (int i = 0; i < num_investidores; i++) {
                if (lista[i].id == escolha) {
                    printf("Digite o patrimônio atualizado:\n");
                    scanf("%f", &lista[i].patrimonio);
                }
            }

            break;

        default :
            printf("Valor inválido. Tente novamente:\n");

            break;
    }
}

void remover() {
    int id;
    printf("Digite o ID do investidor que deseja remover:\n");
    scanf("%d", &id);

    int indice = -1; // Inicializar o índice como -1 para indicar que o investidor não foi encontrado

    // Procurar o investidor pelo ID
    for (int i = 0; i < num_investidores; i++) {
        if (lista[i].id == id) {
            indice = i;
            break;
        }
    }

    // Verificar se o investidor foi encontrado
    if (indice == -1) {
        printf("Investidor não encontrado.\n");
    } else {
        // Remover o investidor
        free(lista[indice].nome);
        for (int i = indice; i < num_investidores - 1; i++) {
            // Mover os investidores para preencher o espaço vazio
            lista[i] = lista[i + 1];
        }
        num_investidores--; // Atualizar o contador de investidores

        printf("Investidor removido com sucesso!\n");
    }
}

void listar_investidor() {
    if (num_investidores == 0) {
        printf("Nenhum investidor cadastrado.\n");
        return;
    }

    int id;
    printf("Digite o ID do investidor:\n");
    scanf("%d", &id);

    int indice = -1; // Inicializar o índice como -1 para indicar que o investidor não foi encontrado

    // Procurar o investidor pelo ID
    for (int i = 0; i < num_investidores; i++) {
        if (id == lista[i].id) {
            indice = i;
            break;
        }
    }

    // Verificar se o investidor foi encontrado
    if (indice == -1) {
        printf("Investidor não encontrado.\n");
    } else {
        printf("Investidor Nº %d:\n", id);
        printf("----------------------\n");
        printf("ID: %d\n", lista[indice].id);
        printf("Nome: %s\n", lista[indice].nome);
        printf("Data de Nascimento: %d/%d/%d\n", lista[indice].data.dia, lista[indice].data.mes, lista[indice].data.ano);
        printf("CPF: %s\n", lista[indice].cpf);
        printf("Patrimônio: R$ %.2f\n", lista[indice].patrimonio);
        printf("----------------------\n----------------------\n");
    }
}



void opcao() {
    while (1) {
        int funcao1 = 0;

        printf("As funções abaixo estão enumeradas da seguinte maneira:\n\n\n");
        printf("0 - Sair\n1 - Inserir investidor\n2 - Listar Investidores:\n3 - Alterar Investidor\n4 - Remover Investidor\n5 - Listar Investidor Específico\n6 - Ir para a tela de investimentos\n");
        scanf("%d", &funcao1);
        switch (funcao1) {
            case 0:
                exit(0);
            case 1:
                inserir_pessoa();
                break;
            case 2:
                listar();
                break;
            case 3:
                alterar();
                break;
            case 4:
                remover();
                break;
            case 5:
                listar_investidor();
                break;
            case 6 :
                opcao_investimento();
                break;
    
            default:
                printf("Valor inválido!\n");
                break;
        }
    }
}
