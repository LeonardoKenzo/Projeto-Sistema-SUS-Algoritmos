#include "fila_de_atendimento.h"
#include "paciente.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct fila_de_atendimento_
{
    PACIENTE **pacientes;
    int capacidade;
    int inicio;
    int fim;
    PACIENTE *proximo;
};

FILA_DE_ATENDIMENTO *fila_criar(int capacidade){
    FILA_DE_ATENDIMENTO *fila = (FILA_DE_ATENDIMENTO *)malloc(sizeof(FILA_DE_ATENDIMENTO));
    if (fila == NULL) {
        return NULL;
    }

    fila->pacientes = (PACIENTE **)malloc(capacidade * sizeof(PACIENTE *));
    if (fila->pacientes == NULL) {
        free(fila);
        return NULL;
    }

    //Inicializa as variaveis da fila
    fila->capacidade = capacidade;
    fila->inicio = 0;
    fila->fim = 0;
    fila->proximo = NULL;
    return fila;
}

bool fila_vazia(FILA_DE_ATENDIMENTO *fila) {
    if (fila == NULL) {
        return true;
    }
    return fila->inicio == fila->fim;
}

bool fila_cheia(FILA_DE_ATENDIMENTO *fila) {
    if (fila == NULL) {
        return false;
    }
    return (fila->fim + 1) % fila->capacidade == fila->inicio;
}

bool fila_inserir(FILA_DE_ATENDIMENTO *fila, PACIENTE *paciente) {
    if ((fila == NULL && !fila_cheia(fila)) || paciente == NULL) {
        printf("Não foi possivel inserir o paciente na triagem.\n");
        return false;
    }

    fila->pacientes[fila->fim] = paciente;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->proximo = fila->pacientes[fila->fim];
    return true;
}

//Remove o primeiro paciente que entrou na fila
PACIENTE *fila_remover(FILA_DE_ATENDIMENTO *fila) {
    if (fila == NULL && !fila_vazia(fila)) {
        return NULL;
    }

    PACIENTE *pacienteRemovido = fila->pacientes[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    return pacienteRemovido;
}

//Libera a fila e todos os pacientes nela
void fila_liberar(FILA_DE_ATENDIMENTO **fila) {
    if (fila == NULL || *fila == NULL) {
        return;
    }

    for (int i = 0; i < ((*fila)->fim) - 1; i++){
        paciente_free(&((*fila)->pacientes[i]));
    }
    free((*fila)->pacientes);
    free(*fila);
    *fila = NULL;
}
