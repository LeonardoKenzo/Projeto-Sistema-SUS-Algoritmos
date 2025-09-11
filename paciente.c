#include "paciente.h"
#include <stdlib.h>
#include <string.h>

struct paciente_{
    int id;
    char *nome;
    HISTORICO *historico;
    bool em_atendimento;
};

//Cria um paciente com id, nome e historico proprio
PACIENTE *paciente_criar(int id, char *nome){
    PACIENTE *paciente = (PACIENTE *)calloc(1, sizeof(PACIENTE));
    if(paciente != NULL){

        //Inicializa todas as informacoes do paciente
        paciente->id = id;
        paciente->nome = strdup(nome);
        paciente->historico = historico_criar();
        paciente->em_atendimento = false;

        return paciente;
    }
    return NULL;
}

//Retorna o historico do paciente
HISTORICO *paciente_get_historico(PACIENTE *paciente){
    return paciente->historico;
}

//Libera a memoria de todas as informacoes do paciente, inclusive o historico
void paciente_free(PACIENTE **paciente){
    if(paciente != NULL || *paciente != NULL){
        historico_free(&((*paciente)->historico));
        free((*paciente)->nome);
        free(*paciente);
        *paciente = NULL;
    }
}

int paciente_get_id(PACIENTE *paciente){
    if(paciente != NULL){
        return paciente->id;
    }
    return -1;
}

char *paciente_get_nome(PACIENTE *paciente){
    if(paciente != NULL){
        return paciente->nome;
    }
    return NULL;
}