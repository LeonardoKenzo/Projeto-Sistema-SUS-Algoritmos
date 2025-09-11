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
HISTORICO *historico_criar(){
    HISTORICO *historico = (HISTORICO *)calloc(1, sizeof(HISTORICO));
    if(historico != NULL){

        //Inicializacao da variavel do historico
        for(int i = 0; i < 10; i++){
            historico->procedimentos[i] = NULL;
        }
        historico->quantidadeCaracteres = 0;
        historico->tamanho = 0; 
        return historico;
    }
    return NULL;
}

//Libera a memoria do historico
void historico_free(HISTORICO **historico){
    if(historico != NULL || *historico != NULL){
        
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
void historico_printar(HISTORICO *historico){
    if(historico != NULL){
        for(int i = 0; i < historico->tamanho; i++){
            printf("%d. %s\n", i + 1, historico->procedimentos[i]);
        }
    }
}

//Insere um procedimento ao historico
bool historico_inserir_procedimento(HISTORICO *historico, char *procedimento){
    if(!historico_esta_cheio(historico) && (historico->quantidadeCaracteres + strlen(procedimento)) <= 100){
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
bool historico_remover_procedimento(HISTORICO *historico){
    if(!historico_esta_vazio(historico)){
        
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
bool historico_esta_cheio(HISTORICO *historico){
    if((historico != NULL && historico->tamanho == 10) || (historico != NULL && historico->quantidadeCaracteres >= 100)){
        return true;
    }
    return false;
}

//Verifica se o historico esta vazio
bool historico_esta_vazio(HISTORICO *historico){
    if(historico != NULL && historico->tamanho == 0){
        return true;
    }
    return false;
}