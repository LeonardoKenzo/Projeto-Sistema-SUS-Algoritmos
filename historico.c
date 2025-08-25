#include "historico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funciona como uma Pilha de procedimentos medicos
struct historico_{
    char *procedimentos[10];
    int tamanho;
    int quantidadeCaracteres;
};

//Cria e inicializa um historico novo
HISTORICO *Historico_Criar(){
    HISTORICO *historico = (HISTORICO *)calloc(1, sizeof(HISTORICO));
    if(historico != NULL){

        //Inicializacao da variavel do historico
        historico->quantidadeCaracteres = 0;

        //Topo da pilha de procedimentos
        historico->tamanho = 0; 
        return historico;
    }
    return NULL;
}

//Libera a memoria do historico
void Historico_Free(HISTORICO **historico){
    if(historico != NULL){
        
        //Libera a memoria de todos os procedimentos
        for(int i = 0; i < (*historico)->tamanho; i++){
            free((*historico)->procedimentos[i]);
        }

        //Libera a memoria do historico
        free(*historico);
        *historico = NULL;
    }
}

//Printa o historico medico inteiro
void Historico_Printar(HISTORICO *historico){
    if(historico != NULL){
        for(int i = 0; i < historico->tamanho; i++){
            printf("%d. %s\n", i + 1, historico->procedimentos[i]);
        }
    }
}

//Insere um procedimento ao historico
bool Historico_InserirProcedimento(HISTORICO *historico, char *procedimento){
    if(!Historico_EstaCheio(historico) && (historico->quantidadeCaracteres + strlen(procedimento)) <= 100){
        historico->quantidadeCaracteres += strlen(procedimento);

        //Insere o procedimento
        historico->procedimentos[historico->tamanho] = strdup(procedimento);
        historico->tamanho++;
        return true;
    }
    //Se nao conseguir inserir
    printf("O histórico médico está cheio.\n");
    return false;
}

//Remove o ultimo procedimento adicionado do historico
bool Historico_RemoverProcedimento(HISTORICO *historico){
    if(!Historico_EstaVazio(historico)){
        
        //Mostra qual procedimento foi removido
        printf("\"%s\" foi removido do histórico médico.\n", historico->procedimentos[historico->tamanho - 1]);

        //Remove o procedimento do historico
        free(historico->procedimentos[historico->tamanho - 1]);
        historico->tamanho--;
        return true;
    }
    //Se nao conseguir remover
    printf("Não há procedimentos para remover.\n");
    return false;
}

//Verifica se o historico esta cheio
bool Historico_EstaCheio(HISTORICO *historico){
    if((historico != NULL && historico->tamanho == 10) || (historico != NULL && historico->quantidadeCaracteres >= 100)){
        return true;
    }
    return false;
}

//Verifica se o historico esta vazio
bool Historico_EstaVazio(HISTORICO *historico){
    if(historico != NULL && historico->tamanho == 0){
        return true;
    }
    return false;
}