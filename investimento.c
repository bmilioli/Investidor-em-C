#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "investimento.h"

#define MAX_INVESTIMENTOS 10
investimento list[MAX_INVESTIMENTOS];
int num_investimentos = 0;

int verifica_codigo(int n) {
  for (int i = 0; i < num_investimentos; i++) {
    if (list[i].codigo == n) {
      return 0; // ID já existe
    }
  }
  return 1; // ID válido
}

investimento criar_investimento(int codigo, int codigoInvestidor, char tipo[20],
                                char *descricao, int prazoDiasUteis,
                                float rentabilidadeAnual) {
  investimento invest;
  invest.codigo = codigo;
  invest.codigoInvestidor = codigoInvestidor;

  // Alocar memória para a descrição e copiar o valor fornecido
  invest.descricao = malloc(255 * sizeof(char));
  if (descricao == NULL) {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }
  strcpy(invest.descricao, descricao);

  invest.prazoDiasUteis = prazoDiasUteis;
  invest.rentabilidadeAnual = rentabilidadeAnual;

  return invest;
}

void inserirInvestimento() {
  if (num_investimentos < MAX_INVESTIMENTOS) {
    printf("Digite o código do investimento:\n");
    scanf("%d", &list[num_investimentos].codigo);
    if (verifica_codigo(list[num_investimentos].codigo) == 0) {
      printf("ID já existente. Não é possível inserir o investidor.\n");
      return;
    }
    // Verificar se o código já existe na lista de investimentos

    printf("Digite o código do investidor associado:\n");
    scanf("%d", &list[num_investimentos].codigoInvestidor);

    printf("Digite o tipo do investimento:\n");
    scanf("%s", list[num_investimentos].tipo);

    printf("Digite a descrição do investimento:\n");
    char descricao[100];
    getchar();
    fgets(descricao, 100, stdin);
    descricao[strcspn(descricao, "\n")] = '\0';
    list[num_investimentos].descricao =
        malloc((strlen(descricao) + 1) * sizeof(char));
    strcpy(list[num_investimentos].descricao, descricao);

    printf("Digite o prazo em dias úteis:\n");
    scanf("%d", &list[num_investimentos].prazoDiasUteis);

    printf("Digite a rentabilidade anual:\n");
    scanf("%f", &list[num_investimentos].rentabilidadeAnual);

    criar_investimento(list[num_investimentos].codigo,
                       list[num_investimentos].codigoInvestidor,
                       list[num_investimentos].tipo,
                       list[num_investimentos].descricao,
                       list[num_investimentos].prazoDiasUteis,
                       list[num_investimentos].rentabilidadeAnual);

    num_investimentos++;
    printf("Investimento inserido com sucesso!\n");
  } else {
    printf("Limite máximo de investimentos atingido. Não é possível inserir "
           "mais investimentos.\n");
  }
}

void listarInvestimentos() {
  if (num_investimentos == 0) {
    printf("Nenhum investimento cadastrado.\n");
    return;
  }

  printf("Lista de Investimentos:\n");
  printf("------------------------\n");

  for (int i = 0; i < num_investimentos; i++) {
    printf("Código: %d\n", list[i].codigo);
    printf("Código do Investidor: %d\n", list[i].codigoInvestidor);
    printf("Tipo: %s\n", list[i].tipo);
    printf("Descrição: %s\n", list[i].descricao);
    printf("Prazo (dias úteis): %d\n", list[i].prazoDiasUteis);
    printf("Rentabilidade Anual: %.2f\n", list[i].rentabilidadeAnual);
    printf("------------------------\n");
  }
}

void alterarInvestimento() {
  int codigo;
  int escolha;
  char *nova_descricao;
  char descricao_proxima[255];
  float nova_rentabilidade;

  printf("----------------------\nTela de alteração de Investimento:\nEscolha "
         "qual dado você gostaria de alterar:\n----------------------\n");
  printf("0 - Sair\n1 - Descrição\n2 - Rentabilidade Anual\n");
  scanf("%d", &escolha);

  switch (escolha) {
  case 1:
    printf("Digite o código do investimento:\n");
    scanf("%d", &codigo);
    scanf("%*[^\n]");
    scanf("%*c");

    nova_descricao = malloc(255 * sizeof(char));
    if (nova_descricao == NULL) {
      printf("Erro ao alocar memória.\n");
      exit(1);
    }

    printf("Digite a nova descrição:\n");
    fgets(nova_descricao, 255, stdin);
    nova_descricao[strcspn(nova_descricao, "\n")] = '\0';

    for (int i = 0; i < num_investimentos; i++) {
      if (list[i].codigo == codigo) {
        if (i + 1 < num_investimentos) {
          strcpy(descricao_proxima, list[i + 1].descricao);
        }

        strncpy(list[i].descricao, nova_descricao, 255);
        list[i + 1].descricao[255 - 1] = '\0';
        printf("Descrição alterada com sucesso!\n");

        if (i + 1 < num_investimentos) {
          strncpy(list[i + 1].descricao, descricao_proxima, 255);
        }
      }
    }
    free(nova_descricao);
    break;

  case 2:
    printf("Digite o código do investimento:\n");
    scanf("%d", &codigo);

    printf("Digite a nova rentabilidade anual:\n");
    scanf("%f", &nova_rentabilidade);

    for (int i = 0; i < num_investimentos; i++) {
      if (list[i].codigo == codigo) {
        list[i].rentabilidadeAnual = nova_rentabilidade;
        printf("Rentabilidade anual alterada com sucesso!\n");
      }
    }
    break;

  default:
    printf("Opção inválida. Tente novamente.\n");
    break;
  }
}

void removerInvestimento() {
  int codigo;
  printf("Digite o código do investimento que deseja remover:\n");
  scanf("%d", &codigo);

  int indice = -1; // Inicializar o índice como -1 para indicar que o
                   // investimento não foi encontrado

  // Procurar o investimento pelo código
  for (int i = 0; i < num_investimentos; i++) {
    if (list[i].codigo == codigo) {
      indice = i;
      break;
    }
  }

  // Verificar se o investimento foi encontrado
  if (indice == -1) {
    printf("Investimento não encontrado.\n");
  } else {
    // Remover o investimento
    free(list[indice].descricao);
    for (int i = indice; i < num_investimentos - 1; i++) {
      // Mover os investimentos para preencher o espaço vazio
      list[i] = list[i + 1];
    }
    num_investimentos--; // Atualizar o contador de investimentos

    printf("Investimento removido com sucesso!\n");
  }
}

void listarInvestimento() {
  if (num_investimentos == 0) {
    printf("Nenhum investimento cadastrado.\n");
    return;
  }

  int codigo;
  printf("Digite o código do investimento:\n");
  scanf("%d", &codigo);

  int indice = -1; // Inicializar o índice como -1 para indicar que o
                   // investimento não foi encontrado

  // Procurar o investimento pelo código
  for (int i = 0; i < num_investimentos; i++) {
    if (codigo == list[i].codigo) {
      indice = i;
      break;
    }
  }

  // Verificar se o investimento foi encontrado
  if (indice == -1) {
    printf("Investimento não encontrado.\n");
  } else {
    printf("Investimento Nº %d:\n", codigo);
    printf("----------------------\n");
    printf("Código: %d\n", list[indice].codigo);
    printf("Código do Investidor: %d\n", list[indice].codigoInvestidor);
    printf("Tipo: %s\n", list[indice].tipo);
    printf("Descrição: %s\n", list[indice].descricao);
    printf("Prazo em Dias Úteis: %d\n", list[indice].prazoDiasUteis);
    printf("Rentabilidade Anual: %.2f\n", list[indice].rentabilidadeAnual);
    printf("----------------------\n----------------------\n");
  }
}

void opcao_investimento() {
  while (1) {
    int funcao2 = 0;

    printf("Escolha uma opção para investimento:\n\n\n");
    printf("0 - Sair\n1 - Inserir investimento\n2 - Listar Investimento:\n3 - "
           "Alterar Investimento\n4 - Remover Investimento\n5 - Listar "
           "Investimento Específico\n");
    scanf("%d", &funcao2);
    switch (funcao2) {
    case 0:
      return;
    case 1:
      inserirInvestimento();
      break;
    case 2:
      listarInvestimentos();
      break;
    case 3:
      alterarInvestimento();
      break;
    case 4:
      removerInvestimento();
      break;
    case 5:
      listarInvestimento();
      break;
    default:
      printf("Valor inválido!\n");
      break;
    }
  }
}
