#include <stdio.h>
#include "investidor.h"


//Estrutura para data de nascimento do investidor



/*                            OBSERVAÇÕES
1 - A decisão de usar um ponteiro para algum campo da estrutura depende das necessidades específicas do seu programa e se você precisa da flexibilidade de modificar dinamicamente o valor da idade ao longo do tempo.

2 - A alocação de memória para o campo nome da struct investidor pode ser feita dentro de uma função responsável por inserir um novo investidor.
  */


int main(void) {
    printf("\n\n\n-----------------CADASTRO DE INVESTIDORES-----------\n\n\n");
    opcao();
    return 0;
}