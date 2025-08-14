#include "historico.h"
#include <stdlib.h>

//Funciona como uma Pilha de procedimentos medicos
struct historico_{
    char procedimentos[10][100];
    int ultimoProcedimento;
};

//Cria e inicializa um historico novo
HISTORICO *Historico_Criar(){
    HISTORICO *historico = (HISTORICO *)calloc(1, sizeof(HISTORICO));
    if(historico != NULL){

        //Topo da pilha de procedimentos
        historico->ultimoProcedimento = 0; 
        return historico;
    }
    return NULL;
}

//Libera a memoria do historico
void Historico_Free(HISTORICO **historico){
    if(historico != NULL){
        free(*historico);
        *historico = NULL;
    }
}