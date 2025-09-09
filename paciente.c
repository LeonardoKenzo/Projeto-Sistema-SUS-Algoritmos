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
PACIENTE *Paciente_Criar(int id, char *nome){
    PACIENTE *paciente = (PACIENTE *)calloc(1, sizeof(PACIENTE));
    if(paciente != NULL){

        //Inicializa todas as informacoes do paciente
        paciente->id = id;
        paciente->nome = strdup(nome);
        paciente->historico = Historico_Criar();

        return paciente;
    }
    return NULL;
}

//Retorna o historico do paciente
HISTORICO *Paciente_GetHistorico(PACIENTE *paciente){
    return paciente->historico;
}


//Libera a memoria de todas as informacoes do paciente, inclusive o historico
void Paciente_Free(PACIENTE **paciente){
    if(paciente != NULL){
        Historico_Free(&((*paciente)->historico));
        free((*paciente)->nome);
        free(*paciente);
        *paciente = NULL;
    }
}

int Paciente_GetID(PACIENTE *paciente){
    if(paciente != NULL){
        return paciente->id;
    }
}

char *Paciente_GetNome(PACIENTE *paciente){
    if(paciente != NULL){
        return paciente->nome;
    }
}