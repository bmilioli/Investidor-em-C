#include <stdio.h>
#include "investimento.h"
//Estrutura para data de nascimento do investidor
struct data_nascimento {
    int dia;
    int mes;
    int ano;
};
typedef struct data_nascimento dn;
//Estrutura para os dados do investidor
struct investidor {
    int id;
    char* nome;
    dn data;
    char cpf[12];
    char* endereco;
    float salario;    
    float patrimonio;
};
typedef struct investidor investidor;

void limparBuffer();
//Função para inserir investidor
void inserir_pessoa();
//Função para listar os investidores
void listar();
//Função para alterar
void alterar();
//Função para remover investidor
void remover();
//Função para verificar se há IDs repetidos
int verificar_id(int n);
//Função para verificar se há CPFs repetidos
int verificar_cpf(char* n);
//Função menu
void opcao();
