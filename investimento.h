#include <stdio.h>


//Estrutura para data de  investimento
struct data_investimento {
    int dia;
    int mes;
    int ano;
};
typedef struct data_investimento di;

struct investimento {
    int codigo;
    int codigoInvestidor;
    char tipo[20];
    float valor;
    char *descricao;
    int prazoDiasUteis;
    di dataInvestimento;    
    float rentabilidadeAnual;
    float valorizacao;
};
typedef struct investimento investimento;


void listarInvestimentos();
void inserirInvestimento();
void opcao_investimento();
void listarInvestimento();
void removerInvestimento();
void alterarInvestimento();
int verifica_codigo(int n);
//somatorio do patrimonio
float somarPatrimonio(int id);
investimento criar_investimento(int codigo, int codigoInvestidor, char tipo[20], float valor, char *descricao, int prazoDiasUteis,di dataIvestimento ,float rentabilidadeAnual, float valorizacao);

