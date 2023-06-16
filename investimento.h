#include <stdio.h>
struct investimento {
    int codigo;
    int codigoInvestidor;
    char tipo[20];
    char *descricao;
    int prazoDiasUteis;
    float rentabilidadeAnual;
};
typedef struct investimento investimento;


void listarInvestimentos();
void inserirInvestimento();
void opcao_investimento();
void listarInvestimento();
void removerInvestimento();
void alterarInvestimento();
int verifica_codigo(int n);
investimento criar_investimento(int codigo, int codigoInvestidor, char tipo[20], char* descricao, int prazoDiasUteis, float rentabilidadeAnual);
void opcao_investimento();
